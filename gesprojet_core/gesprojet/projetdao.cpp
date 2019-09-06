#include "projetdao.h"
#include "projet.h"
#include <QSqlDatabase>
#include<QSqlQuery>
#include <QVariant>

using namespace std;

ProjetDao::ProjetDao(QSqlDatabase &database) :
    Dao(), mDatabase(database)
{

}

void ProjetDao::init() const
{
    if (!mDatabase.tables().contains("projet")) {
        QSqlQuery query(mDatabase);
        query.exec(QString("CREATE TABLE projet")
        + "(id INTEGER PRIMARY KEY AUTOINCREMENT,"        
        +  "partenaire_id INTEGER,"
        +  "association_id INTEGER,"
        + "titre VARCHAR(30),"
        + "descriptif TEXT,"
        + "date_debut DATE,"
        + "date_fin DATE,"
        + "objectif TEXT,"
        + "name_chef TEXT,"
        + "prenom_chef TEXT,"
        + "telephone_chef TEXT,"
        + "email_chef TEXT,"
        + "continent TEXT,"
        + "pays TEXT,"
        + "localite TEXT,"
        +  "cout varchar(30))");
    }
}

void ProjetDao::AddProjetInAssoc(int partenaireId, int associationId, Projet& projet) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("INSERT INTO projet")
           + "(partenaire_id, association_id, titre, descriptif, date_debut, date_fin, objectif, name_chef, prenom_chef, telephone_chef, email_chef, continent, pays, region, localite, cout)"
           + "VALUES("
           + ":partenaire_id,"
           + ":association_id,"
           + ":titre,"
           + ":descriptif,"
           + ":date_debut,"
           + ":date_fin,"
           + ":objectif,"
           + ":name_chef,"
           + ":prenom_chef,"
           + ":telephone_chef,"
           + ":email_chef,"
           + ":continent,"
           + ":pays,"
           + ":region,"
           + ":localite,"
           + ":cout"
           + ")");

    query.bindValue(":partenaire_id",partenaireId);
    query.bindValue(":association_id", associationId);
    query.bindValue(":titre", projet.getTitre());
    query.bindValue(":descriptif", projet.getDescriptif());
    query.bindValue(":date_debut", projet.getDatedebut());
    query.bindValue(":date_fin", projet.getDateFin());
    query.bindValue(":objectif", projet.getObjectif());
    query.bindValue(":name_chef", projet.getNameChef());
    query.bindValue(":prenom_chef", projet.getPrenomChef());
    query.bindValue(":telephone_chef", projet.getTelephoneChef());
    query.bindValue(":email_chef", projet.getEmailChef());
    query.bindValue(":continent", projet.getContient());
    query.bindValue(":pays", projet.getPays());
    query.bindValue(":region", projet.getRegion());
    query.bindValue(":localite", projet.getLocalite());
    query.bindValue(":cout", projet.getCout());
    query.exec();

    projet.setId(query.lastInsertId().toInt());
    projet.setPartenaireId(partenaireId);
    projet.setAssociationId(associationId);
}

void ProjetDao::updateProjet(int partenaireId, int associationId, Projet &projet) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("UPDATE projet SET partenaire_id = (:partenaire_id),")
           + "association_id = (:association_id), titre = (:titre), descriptif = (:descriptif),"
           + "date_debut = (:date_debut), date_fin = (:date_fin), objectif = (:objectif), name_chef = (:name_chef), prenom_chef = (:prenom_chef),"
           +"telephone_chef = (:telephone_chef), email_chef = (:email_chef), pays = (:pays), region = (:region), localite = (:localite), cout = (:cout)");

    query.bindValue(":partenaire_id", partenaireId);
    query.bindValue(":association_id", associationId);
    query.bindValue(":titre", projet.getTitre());
    query.bindValue(":descriptif", projet.getDescriptif());
    query.bindValue(":date_debut", projet.getDatedebut());
    query.bindValue(":date_fin", projet.getDateFin());
    query.bindValue(":objectif", projet.getObjectif());
    query.bindValue(":name_chef", projet.getNameChef());
    query.bindValue(":prenom_chef", projet.getPrenomChef());
    query.bindValue(":telephone_chef", projet.getTelephoneChef());
    query.bindValue(":email_chef", projet.getEmailChef());
    query.bindValue(":continent", projet.getContient());
    query.bindValue(":pays", projet.getPays());
    query.bindValue(":region", projet.getRegion());
    query.bindValue(":localite", projet.getLocalite());
    query.bindValue(":cout", projet.getCout());
    query.exec();

}

void ProjetDao::removeProjet(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM projet WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
}

void ProjetDao::removeProjetForAssociation(int associationId) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM projet WHERE association_id = (:association_id)");
    query.bindValue(":association_id", associationId);
    query.exec();
}

unique_ptr<vector<unique_ptr<Projet>>> ProjetDao::projet(int associationId) const
{
    QSqlQuery query(mDatabase);
    query.prepare(QString("SELECT * FROM projet WHERE  association_id = (:association_id)"));

    query.bindValue(":association", associationId);
    query.exec();

    unique_ptr<vector<unique_ptr<Projet>>> list(new vector<unique_ptr<Projet>>());
    while (query.next()) {
       unique_ptr<Projet> projet(new Projet());
       projet->setId(query.value("id").toInt());
       projet->setAssociationId(associationId);
        projet->setTitre(query.value("titre").toString());
       projet->setDescriptif(query.value("descriptif").toString());
       projet->setDatedebut(query.value("date_debut").toDate());
       projet->setDatefin(query.value("date_fin").toDate());
       projet->setObjectif(query.value("objectif").toString());
       projet->setNameChef(query.value("name_chef").toString());
       projet->setPrenomChef(query.value("prenom_chef").toString());
       projet->setTelephoneChef(query.value("telephone_chef").toString());
       projet->setEmailChef(query.value("email_chef").toString());
       projet->setContient(query.value("continent").toString());
       projet->setPays(query.value("pays").toString());
       projet->setRegion(query.value("region").toString());
       projet->setLocalite(query.value("localite").toString());
       projet->setCout(query.value("cout").toDouble());

       list->push_back(move(projet));
    }
    return  list;
}
