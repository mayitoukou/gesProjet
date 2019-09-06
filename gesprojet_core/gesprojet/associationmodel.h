#ifndef ASSOCIATIONMODEL_H
#define ASSOCIATIONMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <memory>
#include <QObject>

#include "gesprojet_global.h"
#include "association.h"
#include "databasemanager.h"
#include <string>

class DomaineModel;
class Domaine;

class GESPROJETSHARED_EXPORT AssociationModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        CodeRole,
        NomRole,
        AdresseRole,
        TelephoneRole,
        CodePostalRole,
        EmailRole,
        DomaineRole,
        typeRole
    };

    AssociationModel(QObject * parent = nullptr);

    QModelIndex addAssociation(const Association& association);
    Q_INVOKABLE void add(const QString& code, const QString& name, const QString& adresse, const QString& telephone, const QString& codePostal, const QString& email, int mDomaineId, int mTypeAssocId);
    Q_INVOKABLE void rename(int row, const QString& code, QString& name, QString& adresse, QString& telephone, QString& codePostal, QString& email,int mDomaineId, int mTypeAssocId);
    Q_INVOKABLE QVariant dataId(int row);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;


private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;

    std::unique_ptr<std::vector<std::unique_ptr<Association>>> mAssociations;

};

#endif // ASSOCIATIONMODEL_H
