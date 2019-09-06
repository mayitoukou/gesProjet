#include "partenairedao.h"
#include "partenaire.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

using namespace std;


PartenaireDao::PartenaireDao(QSqlDatabase& database) :
    Dao(), mDatabase(database)
{

}

void PartenaireDao::init() const
{
    if (!mDatabase.tables().contains("partenaire")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE partenaire")
         + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"
         + "nom_part VARCHAR(30),"
         + "sigle_part VARCHAR(10),"
         + "adresse_part VARCHAR(30),"
         + "telephone_part VARCHAR(40),"
         + "email_part TEXT,"
         + "scan_document TEXT)");
    }
}

void PartenaireDao::AddPartenaire(Partenaire& partenaire ) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("INSERT INTO partenaire")
                  +"(nom_part, sigle_part, adresse_part, telephone_part, email_part, scan_document)"
                  + "VALUES("
                  + ":nom_part,"
                  + ":sigle_part,"
                  + ":adresse_part,"
                  + ":telephone_part,"
                  + ":email_part,"
                  + ":scan_document"
                  +")");

    query.bindValue(":nom_part", partenaire.getName());
    query.bindValue(":sigle_part", partenaire.getSigle());
    query.bindValue(":adresse_part", partenaire.getAdresse());
    query.bindValue(":telephone_part", partenaire.getTelephone());
    query.bindValue(":email_part", partenaire.getEmail());
    query.bindValue(":scan_document", partenaire.getScan_doc());
    query.exec();
    partenaire.setId(query.lastInsertId().toInt());

}

void PartenaireDao::updatePartenaire(const Partenaire& partenaire) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("UPDATE partenaire SET nom_part = (:nom_part), sigle_part = (:sigle_part)")
            + "adresse_part = (:adresse_part), telephone_part = (:telephone_part), email_part = (:email_part)"
             + "scan_document = (:scan_document) WHERE id = (:id)");

    query.bindValue(":nom_part", partenaire.getName());
    query.bindValue(":sigle_part", partenaire.getSigle());
    query.bindValue(":adresse_part", partenaire.getAdresse());
    query.bindValue(":telephone_part", partenaire.getTelephone());
    query.bindValue(":email_part", partenaire.getEmail());
    query.bindValue(":scan_document", partenaire.getScan_doc());
    query.bindValue(":id", partenaire.Id());
    query.exec();

}

void PartenaireDao::removePartenaire(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM partenaire WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

QString PartenaireDao::partenaireForId(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT nom_part FROM partenaire WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();

    QString name;
    while (query.next()) {
        name = query.value("nom_part").toString();
    }
    return  name;
}

unique_ptr<vector<unique_ptr<Partenaire>>> PartenaireDao::partenaire() const
{
    QSqlQuery query("SELECT * FROM partenaire", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Partenaire>>> list(new vector<unique_ptr<Partenaire>>());
    while (query.next()) {
        unique_ptr<Partenaire> partenaire(new Partenaire());
        partenaire->setId(query.value("id").toInt());
        partenaire->setName(query.value("nom_part").toString());
        partenaire->setSigle(query.value("sigle_part").toString());
        partenaire->setAdresse(query.value("adresse_part").toString());
        partenaire->setTelephone(query.value("telephone_part").toString());
        partenaire->setEmail(query.value("email_part").toString());
        partenaire->setScan_doc(query.value("scan_document").toString());

        list->push_back(move(partenaire));
    }
    return list;
}
