#include "typeassocmodel.h"
using namespace std;

TypeAssocModel::TypeAssocModel(QObject * parent) :
    QAbstractListModel (parent),
    mDb(DatabaseManager::instance()),
    mTypeAssoc(mDb.typeAssocDao.typeAssoc())
{

}

int TypeAssocModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return mTypeAssoc->size();
}

QVariant TypeAssocModel::data(const QModelIndex& index, int role) const
{
    if(!isIndexValid(index)) {
        return QVariant();
    }
    const Type_association& typeAssoc = *mTypeAssoc->at(index.row());

    switch (role) {
    case Roles::idRoles:
        return typeAssoc.id();

    case Roles::libelleRole:
    case Qt::DisplayRole:
        return typeAssoc.libelle();

    default:
        return QVariant();
    }
}

QVariant TypeAssocModel::dataId(int row)
{
    return data(index(row), Roles::idRoles);
}


QHash<int, QByteArray> TypeAssocModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::idRoles] = "id";
    roles[Roles::libelleRole] = "libelle";
    return roles;
}

bool TypeAssocModel::isIndexValid(const QModelIndex& index) const
{
    if (index.row() < 0
                    || index.row() >= rowCount()
                    || !index.isValid()) {
        return false;
    }
    return true;
}

QModelIndex TypeAssocModel::addTypeAssoc(const Type_association& typeAssoc)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    unique_ptr<Type_association> newTypeAssoc(new Type_association(typeAssoc));
    mDb.typeAssocDao.AddTypeAssoc(*newTypeAssoc);
    mTypeAssoc->push_back(move(newTypeAssoc));
    endInsertRows();
    return index(rowIndex, 0);
}

void TypeAssocModel::addTypeFromName(const QString& name)
{
    addTypeAssoc(Type_association(name));
}

bool TypeAssocModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if(!isIndexValid(index)
            || role != Roles::libelleRole) {
        return false;
    }
    Type_association& typeAssoc = *mTypeAssoc->at(index.row());
    typeAssoc.setlibelle(value.toString());
    mDb.typeAssocDao.updateTypeAssoc(typeAssoc);
    emit dataChanged(index, index);
    return true;
}

void TypeAssocModel::rename(int row, const QString& name)
{
    setData(index(row), name, Roles::libelleRole);
}

bool TypeAssocModel::removeRows(int row, int count, const QModelIndex& parent)
{
    if (row < 0
                    || row >= rowCount()
                    || count < 0
                    || (row + count) > rowCount()) {
        return false;
    }
    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;
    while (countLeft--) {
        const Type_association& typeAssoc = *mTypeAssoc->at(row + countLeft);
        mDb.typeAssocDao.removeTypeAssoc(typeAssoc.id());
    }
    mTypeAssoc->erase(mTypeAssoc->begin() + row,
                                                mTypeAssoc->begin() + row + count);
    endRemoveRows();
    return  true;

}
