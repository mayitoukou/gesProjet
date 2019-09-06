#include "domainemodel.h"
using namespace std;

DomaineModel::DomaineModel(QObject * parent) :
    QAbstractListModel (parent),
    mDb(DatabaseManager::instance()),
    mDomaines(mDb.domaineDao.domaine())
{

}

int DomaineModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return  mDomaines->size();
}

QVariant DomaineModel::data(const QModelIndex& index, int role) const
{
    if(!isIndexValid(index)) {
        return QVariant();
    }
    const Domaine& domaine = *mDomaines->at(index.row());

    switch (role) {
    case Roles::IdRole:
        return domaine.id();

    case Roles::NameRole:
    case Qt::DisplayRole:
        return domaine.name();

    default:
        return QVariant();
    }
}

QVariant DomaineModel::dataId(int row)
{
     return data(index(row), Roles::IdRole);
}

QHash<int, QByteArray> DomaineModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::IdRole] = "id";
    roles[Roles::NameRole] = "name";
    return roles;
}

bool DomaineModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0
                    || index.row() >= rowCount()
                    || !index.isValid()) {
        return false;
    }
    return true;
}

QModelIndex DomaineModel::addDomaine(const Domaine& domaine)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Domaine> newDomaine(new Domaine(domaine));
    mDb.domaineDao.AddDomaine(*newDomaine);
    mDomaines->push_back(move(newDomaine));
    endInsertRows();
    return index(rowIndex, 0);
}

void DomaineModel::addDomaineFromName(const QString& name)
{
    addDomaine(Domaine(name));
}


bool DomaineModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index)
            || role != Roles::NameRole) {
        return false;
    }
    Domaine& domaine = *mDomaines->at(index.row());
    domaine.setName(value.toString());
    mDb.domaineDao.updateDomaine(domaine);
    emit dataChanged(index, index);
    return true;
}

void DomaineModel::rename(int row, const QString& name)
{
    setData(index(row), name, Roles::NameRole);
}

bool DomaineModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0
                    || row >= rowCount()
                    || count < 0
                    || (row + count) > rowCount()) {
        return false;
    }

    beginRemoveRows(parent, row, row + count -1);
    int countleft = count;
    while (countleft--) {
        const Domaine& domaine = *mDomaines->at(row + countleft);
        mDb.domaineDao.removeDomaine(domaine.id());
    }
    mDomaines->erase(mDomaines->begin() + row,
                                            mDomaines->begin() + row + count);

    endRemoveRows();
    return true;
}
