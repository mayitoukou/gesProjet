#include "partenaire.h"
#include "projet.h"

Partenaire::Partenaire(const QString& name, const QString& sigle, const QString& adresse, const QString& telephone,
                       const QString& email, const QString& scan_doc) :
            mId(-1),
            mName(name),
            mSigle(sigle),
            mAdresse(adresse),
            mTelephone(telephone),
            mEmail(email),
            mScan_doc(scan_doc)
{

}

int Partenaire::Id() const
{
    return  mId;
}

QString Partenaire::getName() const
{
    return mName;
}

QString Partenaire::getSigle() const
{
    return mSigle;
}

QString Partenaire::getAdresse() const
{
    return  mAdresse;
}

QString Partenaire::getTelephone() const
{
    return  mTelephone;
}

QString Partenaire::getEmail() const
{
    return mEmail;
}

QString Partenaire::getScan_doc() const
{
    return  mScan_doc;
}


void Partenaire::setId(int id)
{
    mId = id;
}

void Partenaire::setName(const QString& name)
{
    mName = name;
}

void Partenaire::setAdresse(const QString& adresse)
{
    mAdresse = adresse;
}

void Partenaire::setTelephone(const QString& telephone)
{
    mTelephone = telephone;
}

void Partenaire::setSigle(const QString& sigle)
{
    mSigle = sigle;
}

void Partenaire::setEmail(const QString& email)
{
    mEmail = email;
}

void Partenaire::setScan_doc(const QString& scan_doc)
{
    mScan_doc = scan_doc;
}


