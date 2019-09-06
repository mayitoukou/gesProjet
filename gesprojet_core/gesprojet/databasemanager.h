#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QHash>
#include "domainedao.h"
#include "typeassocdao.h"
#include "partenairedao.h"
#include "associationdao.h"
#include "projetdao.h"

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "projet.db";

                
class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery& query);

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator =(const DatabaseManager& rhs);

private:
    QSqlDatabase* mDatabase;    
    QHash<QString, const Dao*> mDaos;


public:
    const DomaineDao domaineDao;
    const typeAssocdao typeAssocDao;
    const PartenaireDao partenaireDao;
    const AssociationDao associationDao;
    const ProjetDao projetDao;

    void AddandDisplayDao();

};

#endif // DATABASEMANAGER_H
