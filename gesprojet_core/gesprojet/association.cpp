#include "association.h"

Association::Association()
{

}

Association::Association(const QString code, const QString name, const QString adresse, const QString telephone, const QString codePostal, const QString email, int domaineId, int typeId):    
    mId(-1),
    mCode(code),
    mName(name),
    mAdresse(adresse),
    mTelephone(telephone),
    mCodePostal(codePostal),
    mEmail(email),
    mDomaineId(domaineId),
    mTypeId(typeId)

{
}

int Association::Id() const
{
    return  mId;
}

QString Association::getCode() const
{
    return mCode;
}

QString Association::getName() const
{
    return  mName;
}

QString Association::getAdresse() const
{
    return  mAdresse;
}

QString Association::getTelephone() const
{
    return mTelephone;
}

QString Association::getCodePostal() const
{
    return mCodePostal;
}

QString Association::getEmail() const
{
    return  mEmail;
}

int Association::getDomaineId() const
{
    return  mDomaineId;
}

int Association::getAssocType() const
{
    return mTypeId;
}

void Association::setId(int id)
{
    mId = id;
}

void Association::setCode(const QString& code)
{
    mCode = code;
}

void Association::setName(const QString& name)
{
    mName = name;
}

void Association::setAdresse(const QString& adresse)
{
    mAdresse = adresse;
}

void Association::setTelephone(const QString& telephone)
{
    mTelephone = telephone;
}

void Association::setCodePostal(const QString& codePostal)
{
    mCodePostal = codePostal;
}

void Association::setEmail(const QString& email)
{
    mEmail = email;
}

void Association::setDomaineId(int domaineId)
{
    mDomaineId = domaineId;
}

void Association::setAssocTypeId(int typeId)
{
    mTypeId = typeId;
}



