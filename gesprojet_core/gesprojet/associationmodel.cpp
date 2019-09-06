/*
* Classe servant de modèle à Association
* permettant d'éffectuer des opétations relatives à Association
*/

#include "associationmodel.h"

#include "domaine.h"
#include "type_association.h"
#include "domainemodel.h"
#include "domaine.h"

using namespace std;

AssociationModel::AssociationModel(QObject *parent) :
    QAbstractListModel(parent),
    mDb(DatabaseManager::instance()),
    mAssociations(mDb.associationDao.association())
{
}

int AssociationModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mAssociations->size();
}

QModelIndex AssociationModel::addAssociation(const Association& association)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Association> newAssociation(new Association(association));
    mDb.associationDao.AddAssociation(*newAssociation);
    mAssociations->push_back(move(newAssociation));
    endInsertRows();
    return index(rowIndex, 0);
}

void AssociationModel::add(const QString& code, const QString& name, const QString& adresse, const QString& telephone, const QString& codePostal, const QString& email, int mDomaineId, int mTypeAssocId)
{
    addAssociation(Association(code, name, adresse, telephone, codePostal, email, mDomaineId, mTypeAssocId));
}

QVariant AssociationModel::data(const QModelIndex& index, int role) const
{
    if(!isIndexValid(index)) {
        return QVariant();
    }
    const Association& association = *mAssociations->at(index.row());

    switch (role) {
    case Roles::IdRole:
        return association.Id();

    case Roles::CodeRole:
        return association.getCode();

    case Roles::NomRole:
    case Qt::DisplayRole:
        return association.getName();

    case Roles::AdresseRole:
        return association.getAdresse();

    case Roles::TelephoneRole:
        return association.getTelephone();

    case Roles::CodePostalRole:
        return association.getCodePostal();

    case Roles::EmailRole:
        return association.getEmail();

    case Roles::DomaineRole:
        return mDb.domaineDao.domaineForId(association.getDomaineId());

    case Roles::typeRole:
        return mDb.typeAssocDao.typeForId(association.getAssocType());

    default:
        return QVariant();
    }
}

QHash<int, QByteArray> AssociationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::CodeRole] = "code";
    roles[Roles::NomRole] = "nom";
    roles[Roles::AdresseRole] = "adresse";
    roles[Roles::TelephoneRole] = "telephone";
    roles[Roles::CodePostalRole] = "codePostale";
    roles[Roles::EmailRole] = "email";
    roles[Roles::DomaineRole] = "domaine";
    roles[Roles::typeRole] = "libelle";
    return roles;
}

bool AssociationModel::isIndexValid(const QModelIndex& index) const
{
    if(index.row() < 0
                || index.row() > rowCount()
                || !index.isValid()) {
        return false;
    }
    return true;
}


bool AssociationModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index)
            || role != Qt::EditRole) {
        return false;
    }
    Association& association = *mAssociations->at(index.row());
    if(role == CodeRole){
        association.setCode(value.toString());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == NomRole) {
        association.setName(value.toString());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == AdresseRole) {
        association.setAdresse(value.toString());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == TelephoneRole) {
        association.setTelephone(value.toString());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == CodePostalRole) {
        association.setCodePostal(value.toString());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == EmailRole) {
        association.setEmail(value.toString());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == DomaineRole) {
        association.setDomaineId(value.toInt());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }
    else if (role == typeRole) {
        association.setAssocTypeId(value.toInt());
        mDb.associationDao.updateAssociation(association);
        emit dataChanged(index, index);
        return true;
    }

}

void AssociationModel::rename(int row, const QString& code, QString& name, QString& adresse, QString& telephone, QString& codePostal, QString& email,int mDomaineId, int mTypeAssocId)
{

        setData(index(row), code, Roles::CodeRole);

        setData(index(row), name, Roles::NomRole);

        setData(index(row), adresse, Roles::AdresseRole);

        setData(index(row), telephone, Roles::AdresseRole);

        setData(index(row), codePostal, Roles::CodePostalRole);

        setData(index(row), email, Roles::EmailRole);

        setData(index(row), mDomaineId, Roles::DomaineRole);

        setData(index(row), mTypeAssocId, Roles::typeRole);
}

QVariant AssociationModel::dataId(int row)
{
    return data(index(row), Roles::IdRole);
}


bool AssociationModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if(row < 0
                    || row >= rowCount()
                    || count < 0
                    || (row + count) > rowCount()) {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--) {
        const Association& association = *mAssociations->at(row + countLeft);
        mDb.associationDao.removeAssociation(association.Id());
    }
    mAssociations->erase(mAssociations->begin() + row,
                                                    mAssociations->begin() + row + count);

    endRemoveRows();
    return true;
}
