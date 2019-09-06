#ifndef PROJETMODEL_H
#define PROJETMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <memory>

#include "gesprojet_global.h"
#include "projet.h"

class DatabaseManager;
class AssociationModel;

class GESPROJETSHARED_EXPORT ProjetModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        TitreRole,
        DescriptifRole,
        DateDebutRole,
        DateFinRole,
        ObjectifRole,
        NameChefRole,
        PrenomChefRole,
        TelephoneChefRole,
        EmailChefRole,
        ContinentRole,
        PaysRole,
        RegionRole,
        LocaliteRole,
        CoutRole,
        PartenaireRole,
        AssociationRole
    };

    ProjetModel(QObject * parent = nullptr);

    QModelIndex addProjet(const Projet& projet);
    Q_INVOKABLE void add(const QString& titre, const QString& description, QDate& dateDebut, QDate& dateFin, const QString& objectif, const QString&  nameChef,
                         const QString& prenomChef, const QString& telephone, const QString& email, const QString& continent, const QString& pays, const QString& region, const QString& localite,
                         double cout, int partenaireId, int associationId);

    int rowCount(const QModelIndex& paernt = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;
    int mAssociationId;
    int mPartenaireId;
    std::unique_ptr<std::vector<std::unique_ptr<Projet>>> mProjets;

};

#endif // PROJETMODEL_H
