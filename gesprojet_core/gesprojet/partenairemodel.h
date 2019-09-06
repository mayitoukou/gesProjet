#ifndef PARTENAIREMODEL_H
#define PARTENAIREMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <memory>

#include "gesprojet_global.h"
#include "partenaire.h"
#include "databasemanager.h"

class GESPROJETSHARED_EXPORT PartenaireModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
         IdRole = Qt::UserRole + 1,
         NameRole,
         SigleRole,
         AdresseRole,
         TelephoneRole,
         EmailRole,
         Scan_docRole
    };

    PartenaireModel(QObject * parent = nullptr);

    QModelIndex addPartenaire(const Partenaire& partenaire);
    Q_INVOKABLE void add(const QString& name, const QString& sigle, const QString& adresse, const QString& telephone, const QString& email, const QString& doc);
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
    std::unique_ptr<std::vector<std::unique_ptr<Partenaire>>> mPartenaires;

};

#endif // PARTENAIREMODEL_H
