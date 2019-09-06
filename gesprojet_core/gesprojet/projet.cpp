#include "projet.h"
#include "association.h"

Projet::Projet(): mCout(0.0)
{

}

Projet::Projet(const QString& titre, const QString& descriptif, QDate date_debut, QDate date_fin,
               const QString& objectif,  const QString &nameChef, const QString &prenomChef, const QString &telephoneChef, const QString &emailChef, const QString &continent, const QString &pays, const QString &region, const QString &localite, double cout, int partenaireId, int assocId) :
        mId(-1),
        mTitre(titre),
        mDescriptif(descriptif),
        mDateDebut(date_debut),
        mDateFin(date_fin),
        mObjectif(objectif),
        mName_chef(nameChef),
        mPrenom_chef(prenomChef),
        mTelephone_chef(telephoneChef),
        mEmail_chef(emailChef),
        mContient(continent),
        mPays(pays),
        mRegion(region),
        mLocalite(localite),
        mCout(cout),
        mPartenaireId(partenaireId),
        mAssociationId(assocId)
{
}

int Projet::Id() const
{
    return mId;
}

QString Projet::getTitre() const
{
    return mTitre;
}

QString Projet::getDescriptif() const
{
    return mDescriptif;
}

QDate Projet::getDatedebut() const
{
    return mDateDebut;
}

QDate Projet::getDateFin() const
{
    return mDateFin;
}

QString Projet::getObjectif() const
{
    return mObjectif;
}

double Projet::getCout() const
{
    return  mCout;
}

QString Projet::getNameChef() const
{
    return mName_chef;
}

QString Projet::getPrenomChef() const
{
    return mPrenom_chef;
}

QString Projet::getTelephoneChef() const
{
    return mTelephone_chef;
}

QString Projet::getEmailChef() const
{
    return mEmail_chef;
}

QString Projet::getContient() const
{
    return mContient;
}

QString Projet::getPays() const
{
    return mPays;
}

QString Projet::getRegion() const
{
    return mRegion;
}

QString Projet::getLocalite() const
{
    return mLocalite;
}

int  Projet::getPartenaireId() const
{
    return mPartenaireId;
}

int  Projet::getAssociationId() const
{
    return mAssociationId;
}

void Projet::setId(int id)
{
    mId =id;
}

void Projet::setTitre(const QString& titre)
{
    mTitre = titre;
}

void Projet::setDescriptif(const QString& descriptif)
{
    mDescriptif = descriptif;
}

void Projet::setDatedebut(QDate date_debut)
{
    mDateDebut = date_debut;
}

void Projet::setDatefin(QDate date_fin)
{
    mDateFin = date_fin;
}

void Projet::setObjectif(const QString& objectif)
{
    mObjectif = objectif;
}

void Projet::setNameChef(const QString &nameChef)
{
    mName_chef = nameChef;
}

void Projet::setPrenomChef(const QString &prenomChef)
{
    mPrenom_chef = prenomChef;
}

void Projet::setTelephoneChef(const QString &telephoneChef)
{
    mTelephone_chef = telephoneChef;
}

void Projet::setEmailChef(const QString &emailChef)
{
    mEmail_chef = emailChef;
}

void Projet::setContient(const QString &continent)
{
    mContient = continent;
}

void Projet::setPays(const QString &pays)
{
    mPays = pays;
}

void Projet::setRegion(const QString &region)
{
    mRegion = region;
}

void Projet::setLocalite(const QString &localite)
{
    mLocalite = localite;
}

void Projet::setCout(double cout)
{
    mCout = cout;
}

void Projet::setPartenaireId(int partenaireId)
{
    mPartenaireId = partenaireId;
}

void Projet::setAssociationId(int associationId)
{
    mAssociationId = associationId;
}


