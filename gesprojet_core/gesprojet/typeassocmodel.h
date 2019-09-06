#ifndef TYPEASSOCMODEL_H
#define TYPEASSOCMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "gesprojet_global.h"
#include "type_association.h"
#include "databasemanager.h"



class GESPROJETSHARED_EXPORT TypeAssocModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles{
        idRoles = Qt::UserRole + 1,
        libelleRole,
    };

    TypeAssocModel(QObject * parent = 0);

    QModelIndex addTypeAssoc(const Type_association& typeAssoc);
    Q_INVOKABLE void addTypeFromName(const QString& name);
    Q_INVOKABLE void rename(int row, const QString& name);

    int rowCount(const QModelIndex& index = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QVariant dataId(int row);

    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Type_association>>> mTypeAssoc;
};

#endif // TYPEASSOCMODEL_H
