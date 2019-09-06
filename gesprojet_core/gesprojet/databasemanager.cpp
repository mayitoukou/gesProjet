#include "databasemanager.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

void DatabaseManager::debugQuery(const QSqlQuery& query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
             qDebug() << "Query OK:" << query.lastQuery();
    } else {
               qWarning() << "Query KO:" << query.lastError().text();
               qWarning() << "Query text:" << query.lastQuery();
    }
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
        mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
        mDaos(), domaineDao(*mDatabase), typeAssocDao(*mDatabase),
        partenaireDao(*mDatabase),associationDao(*mDatabase),
        projetDao(*mDatabase)
{
    mDatabase->setDatabaseName(path);

    bool openStauts = mDatabase->open();
    qDebug() << "Database connection: " << (openStauts ?  "OK" : "Error");


  AddandDisplayDao();

}

void DatabaseManager::AddandDisplayDao()
{

    mDaos.insert("domDao", &domaineDao);
    mDaos.insert("typeDao", &typeAssocDao);
    mDaos.insert("partenaireDao",&partenaireDao);
    mDaos.insert("association", &associationDao);
    mDaos.insert("projetDao", &projetDao);

    QHashIterator<QString, const Dao*> i(mDaos);
    while (i.hasNext())
            i.next().value()->init();
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
    delete  mDatabase;
}
