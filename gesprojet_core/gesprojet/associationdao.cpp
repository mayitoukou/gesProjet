#include "associationdao.h"
#include "association.h"
#include <QSqlDatabase>
#include<QSqlQuery>
#include <QVariant>

using namespace std;

AssociationDao::AssociationDao(QSqlDatabase& database) :
        Dao(), mDatabase(database)
{

}

// Permet de créer la table association dans la base de données

void AssociationDao::init() const
{
    if (!mDatabase.tables().contains("association")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE association")
         + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
         + "domaine_id INTEGER,"
         + "typeAssoc_id INTEGER,"
         +"code VARCHAR(10),"
         +"nom VARCHAR(30),"
         +"adresse VARCHAR(50),"
         +"code_postal VARCHAR(10),"
         +"telephone VARCHAR(30),"
         +"email TEXT)");
    }
}

// Permet d'ajouter une association dans la base de données
void AssociationDao::AddAssociation(Association& association) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("INSERT INTO association")
            + "(domaine_id, typeAssoc_id, code, nom, adresse, code_postal, telephone, email)"
            + "VALUES("
            + ":domaine_id,"
            + ":typeAssoc_id,"
            + ":code,"
            +  ":nom,"
            +  ":adresse,"
            +  ":code_postal,"
            +  ":telephone,"
            + ":email)");

    query.bindValue(":domaine_id", association.getDomaineId());
    query.bindValue(":typeAssoc_id", association.getAssocType());
    query.bindValue(":code", association.getCode());
    query.bindValue(":nom", association.getName());
    query.bindValue(":adresse", association.getAdresse());
    query.bindValue(":code_postal", association.getCodePostal());
    query.bindValue(":telephone", association.getTelephone());
    query.bindValue(":email", association.getEmail());
    query.exec();

    association.setId(query.lastInsertId().toInt());

}

// Permet de modifier les informations d'une Association dans la base de données
void AssociationDao::updateAssociation(Association& association) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("UPDATE association SET domaine_id = (:domaine_id), typeAssoc_id = (:typeAssoc_id)")
           + "code = (:code), nom = (:nom), adresse = (:adresse), code_postal = (:code_postal),"
           + "telephone = (:telephone), email = (:email) WHERE id = (:id)");

    query.bindValue(":domaine_id", association.getDomaineId());
    query.bindValue(":typeAssoc_id", association.getAssocType());
    query.bindValue(":code", association.getCode());
    query.bindValue(":nom", association.getName());
    query.bindValue(":adresse", association.getAdresse());
    query.bindValue(":code_postal", association.getCodePostal());
    query.bindValue(":telephone", association.getTelephone());
    query.bindValue(":email", association.getEmail());
    query.bindValue(":id", association.Id());
    query.exec();
}

QString AssociationDao::associationForId(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT nom FROM association WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();

    QString name;
    while (query.next()) {
        name = query.value("nom").toString();
    }
    return  name;
}

// Permet de supprimer une association dans la base

void AssociationDao::removeAssociation(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM association WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

void AssociationDao::removeAssocForDomaine(int domaineId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM association WHERE domaine_id = (:domaine_id)");
    query.bindValue(":domaine_id", domaineId);
    query.exec();
}

// Permet de récupérer les associations dans la base de données
unique_ptr<vector<unique_ptr<Association>>> AssociationDao::association() const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM association");
    query.exec();

    unique_ptr<vector<unique_ptr<Association>>> list(new vector<unique_ptr<Association>>());
    while (query.next()) {
        unique_ptr<Association> association(new Association());
        association->setId(query.value("id").toInt());
        association->setCode(query.value("code").toString());
        association->setName(query.value("nom").toString());
        association->setAdresse(query.value("adresse").toString());
        association->setCodePostal(query.value("code_postal").toString());
        association->setTelephone(query.value("telephone").toString());
        association->setEmail(query.value("email").toString());
        association->setDomaineId(query.value("domaine_id").toInt());
        association->setAssocTypeId(query.value("typeAssoc_id").toInt());

        list->push_back(move(association));
    }
    return list;
}


