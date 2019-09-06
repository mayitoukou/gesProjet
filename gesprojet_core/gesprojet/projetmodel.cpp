#include "projetmodel.h"
#include "databasemanager.h"
#include "associationmodel.h"
#include "partenaire.h"

using namespace std;

ProjetModel::ProjetModel(QObject *parent) :
        QAbstractListModel(parent),
        mDb(DatabaseManager::instance()),
        mAssociationId(-1),
        mPartenaireId(-1),
        mProjets(mDb.projetDao.projet(mAssociationId))
{

}

int ProjetModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mProjets->size();
}

QModelIndex ProjetModel::addProjet(const Projet& projet)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Projet> newProjet(new Projet(projet));
    mDb.projetDao.AddProjetInAssoc(mPartenaireId, mAssociationId, *newProjet);
    mProjets->push_back(move(newProjet));
    endInsertRows();
    return index(rowIndex, 0);
}

void ProjetModel::add(const QString &titre, const QString &description, QDate& dateDebut, QDate& dateFin, const QString &objectif, const QString &nameChef, const QString &prenomChef, const QString &telephone, const QString &email, const QString &continent, const QString &pays, const QString &region, const QString &localite, double cout, int partenaireId, int associationId)
{
    addProjet(Projet(titre, description, dateDebut, dateFin, objectif, nameChef, prenomChef, telephone, email, continent, pays, region, localite, cout, partenaireId, associationId));
}

QVariant ProjetModel::data(const QModelIndex& index, int role) const
{
    if (!isIndexValid(index)) {
        return QVariant();
    }
    const Projet& projet = *mProjets->at(index.row());

    switch (role) {
    case Roles::IdRole:
        return projet.Id();

    case Roles::TitreRole:
    case Qt::DisplayRole:
        return projet.getTitre();

    case Roles::DescriptifRole:
        return projet.getDescriptif();

    case Roles::DateDebutRole:
        return projet.getDatedebut();

    case Roles::DateFinRole:
        return projet.getDateFin();

    case Roles::ObjectifRole:
        return projet.getObjectif();

    case Roles::CoutRole:
        return projet.getCout();

    case Roles::AssociationRole:
        return mDb.associationDao.associationForId(projet.getAssociationId());

    case Roles::PartenaireRole:
        return mDb.partenaireDao.partenaireForId(projet.getPartenaireId());
    }

    return QVariant();
}

QHash<int, QByteArray> ProjetModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::TitreRole] = "titre";
    roles[Roles::DescriptifRole] = "descriptif";
    roles[Roles::DateDebutRole] = "date_debut";
    roles[Roles::DateFinRole] = "date_fin";
    roles[Roles::ObjectifRole] = "objectif";
    roles[Roles::CoutRole] = "cout";
    return roles;
}

bool ProjetModel::isIndexValid(const QModelIndex& index) const
{
    if(index.row() < 0
                || index.row() > rowCount()
                || !index.isValid()) {
        return false;
    }
    return true;
}

bool ProjetModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!isIndexValid(index)
            || role != Roles::TitreRole) {
        return false;
    }
    Projet& projet = *mProjets->at(index.row());
    projet.setTitre(value.toString());
    projet.setDescriptif(value.toString());
    projet.setDatedebut(value.toDate());
    projet.setDatefin(value.toDate());
    projet.setObjectif(value.toString());
    projet.setCout(value.toDouble());
    projet.setAssociationId(mAssociationId);
    projet.setPartenaireId(mPartenaireId);
    mDb.projetDao.updateProjet(mPartenaireId, mAssociationId, projet);
    emit dataChanged(index, index);
    return true;
}

bool ProjetModel::removeRows(int row, int count, const QModelIndex& parent)
{
        if(row < 0
                || row >= rowCount()
                || count < 0
                || (row + count) > rowCount()) {
    return false;
    }

    beginInsertRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--) {
        const Projet& projet = *mProjets->at(row + countLeft);
        mDb.projetDao.removeProjet(projet.Id());
    }
    mProjets->erase(mProjets->begin() + row,
                                        mProjets->begin() + row + count);
    endRemoveRows();
    return true;
}


