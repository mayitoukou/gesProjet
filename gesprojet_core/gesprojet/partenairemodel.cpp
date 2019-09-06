#include "partenairemodel.h"
#include "partenaire.h"

using namespace std;

PartenaireModel::PartenaireModel(QObject * parent) :
    QAbstractListModel (parent),
    mDb(DatabaseManager::instance()),
    mPartenaires(mDb.partenaireDao.partenaire())
{
}

int PartenaireModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mPartenaires->size();
}


QVariant PartenaireModel::data(const QModelIndex& index, int role) const
{
    if(!isIndexValid(index)) {
        return QVariant();
    }
    const Partenaire& partenaire = *mPartenaires->at(index.row());

    switch (role) {
    case Roles::IdRole:
        return partenaire.Id();

    case Roles::NameRole:
    case Qt::DisplayRole:
        return partenaire.getName();

    case Roles::SigleRole:
        return partenaire.getSigle();

    case Roles::AdresseRole:
        return partenaire.getAdresse();

    case Roles::TelephoneRole:
        return partenaire.getTelephone();

    case Roles::EmailRole:
        return partenaire.getEmail();

    case Roles::Scan_docRole:
        return partenaire.getScan_doc();

    default:
        return QVariant();
    }
}

QHash<int, QByteArray> PartenaireModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    roles[Roles::SigleRole] = "sigle";
    roles[Roles::AdresseRole] = "adresse";
    roles[Roles::TelephoneRole] = "telephone";
    roles[Roles::EmailRole] = "email";
    roles[Roles::Scan_docRole] = "scan_doc";
    return roles;
}

bool PartenaireModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0
                    || index.row() >= rowCount()
                    || !index.isValid()) {
        return false;
    }
    return true;
}

QModelIndex PartenaireModel::addPartenaire(const Partenaire& partenaire)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Partenaire> newPartenaire(new Partenaire(partenaire));
    mDb.partenaireDao.AddPartenaire(*newPartenaire);
    mPartenaires->push_back(move(newPartenaire));
    endInsertRows();
    return index(rowIndex, 0);
}

void PartenaireModel::add(const QString& name, const QString& sigle, const QString& adresse, const QString& telephone,
                                                        const QString& email, const QString& doc)
{
    addPartenaire(Partenaire(name, sigle, adresse, telephone, email, doc));
}

QVariant PartenaireModel::dataId(int row)
{
    return data(index(row), Roles::IdRole);
}

bool PartenaireModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!isIndexValid(index)
            || role != Roles::NameRole) {
        return false;
    }
    Partenaire& partenaire = * mPartenaires->at(index.row());
    partenaire.setName(value.toString());
    partenaire.setSigle(value.toString());
    partenaire.setAdresse(value.toString());
    partenaire.setTelephone(value.toString());
    partenaire.setEmail(value.toString());
    partenaire.setScan_doc(value.toString());
    mDb.partenaireDao.updatePartenaire(partenaire);
    emit dataChanged(index, index);
    return true;
}

bool PartenaireModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0
                    || row >= rowCount()
                    || count < 0
                    || (row + count) > rowCount() ) {
        return false;
    }

    beginRemoveRows(parent, row, row + count -1);
    int countleft = count;
    while (countleft--) {
        const Partenaire& partenaire = *mPartenaires->at(row + countleft);
        mDb.partenaireDao.removePartenaire(partenaire.Id());
    }
    mPartenaires->erase(mPartenaires->begin() + row,
                                            mPartenaires->begin() + row + count);

    endRemoveRows();
    return true;
}



