#ifndef DOMAINEMODEL_H
#define DOMAINEMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "gesprojet_global.h"
#include "domaine.h"
#include "databasemanager.h"


class GESPROJETSHARED_EXPORT DomaineModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
               IdRole = Qt::UserRole + 1,
               NameRole,
    };

    DomaineModel(QObject * parent = nullptr);

    QModelIndex addDomaine(const Domaine& domaine);
    Q_INVOKABLE void addDomaineFromName(const QString& name);
    Q_INVOKABLE void rename(int row, const QString& name);

    int rowCount(const QModelIndex& index = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE  QVariant dataId(int row);

    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex& parent) override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;


private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;    
    std::unique_ptr<std::vector<std::unique_ptr<Domaine>>> mDomaines;

};

#endif // DOMAINEMODEL_H
