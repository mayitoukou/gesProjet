#include "typeassocdao.h"
#include "type_association.h"

#include <QSqlDatabase>
#include<QSqlQuery>
#include <QVariant>
#include <memory>

using namespace std;

typeAssocdao::typeAssocdao(QSqlDatabase& database) :
        Dao(), mDatabase(database)
{

}

void typeAssocdao::init() const
{
    if (!mDatabase.tables().contains("type_assoc")) {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE type_assoc (id INTEGER PRIMARY KEY AUTOINCREMENT ,"
                    "libelle VARCHAR(30))");
    }
}

void typeAssocdao::AddTypeAssoc(Type_association& type) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO type_assoc (libelle) VALUES (:libelle)");
    query.bindValue(":libelle", type.libelle());
    query.exec();
    type.setId(query.lastInsertId().toInt());
}

void typeAssocdao::updateTypeAssoc(const Type_association& type) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE type_assoc SET libelle = (:libelle) WHERE id = (:id)");
    query.bindValue(":libelle", type.libelle());
    query.bindValue(":id", type.id());
    query.exec();
}

void typeAssocdao::removeTypeAssoc(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM type_assoc WHERE id =(:id)");
    query.bindValue(":id", id);
    query.exec();
}

QString typeAssocdao::typeForId(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT libelle FROM type_assoc WHERE id =(:id)");
    query.bindValue(":id",id);
    query.exec();

    QString libelle;
    while (query.next()) {
        libelle = query.value("libelle").toString();
    }
    return libelle;
}

unique_ptr<vector<unique_ptr<Type_association>>>  typeAssocdao::typeAssoc() const
{
    QSqlQuery query("SELECT * FROM type_assoc", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Type_association>>> list(new vector<unique_ptr<Type_association>>());
    while (query.next()) {
       unique_ptr<Type_association> type(new Type_association());
       type->setId(query.value("id").toInt());
       type->setlibelle(query.value("libelle").toString());
       list->push_back(move(type));
    }
    return list;
}
