#include "domainedao.h"
#include "domaine.h"

#include <QSqlDatabase>
#include<QSqlQuery>
#include <QVariant>

using namespace std;

DomaineDao::DomaineDao(QSqlDatabase& database) :
        Dao(),mDatabase(database)
{

}

void DomaineDao::init() const
{
    if (!mDatabase.tables().contains("domaine")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE domaine (id INTEGER PRIMARY KEY AUTOINCREMENT ,"
                   " name VARCHAR(30) )");
    }
}

void DomaineDao::AddDomaine(Domaine& domaine) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO domaine (name) VALUES (:name)");
    query.bindValue(":name", domaine.name());
    query.exec();
    domaine.setId(query.lastInsertId().toInt());
}

void DomaineDao::updateDomaine(const Domaine& domaine) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE domaine SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", domaine.name());
    query.bindValue(":id", domaine.id());
    query.exec();
}

void DomaineDao::removeDomaine(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM domaine WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

QString DomaineDao::domaineForId(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT  name  FROM domaine WHERE id = (:id)");
    query.bindValue(":id",id);
    query.exec();

    QString name;
    while (query.next()) {
        name = query.value("name").toString();
    }
    return name;
}


unique_ptr<vector<unique_ptr<Domaine>>> DomaineDao::domaine() const
{
    QSqlQuery query("SELECT * FROM domaine", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Domaine>>> list(new vector<unique_ptr<Domaine>>());
    while (query.next()) {
            unique_ptr<Domaine> domaine(new Domaine());
            domaine->setId(query.value("id").toInt());
            domaine->setName(query.value("name").toString());
            list->push_back(move(domaine));
    }
    return list;
}
