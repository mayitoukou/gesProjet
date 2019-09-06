#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <QString>
#include <QObject>
#include "gesprojet_global.h"


class GESPROJETSHARED_EXPORT Association
{

public:

     Association();
     Association(const QString code, const QString name, const QString adresse, const QString telephone,
                         const QString codePostal, const QString email, int domaineId, int typeId);

public:

    int Id() const;
    QString getCode() const;
    QString getName() const;
    QString getAdresse() const;
    QString getTelephone() const;
    QString getCodePostal() const;
    QString getEmail() const;
    int  getDomaineId() const;
    int getAssocType() const;

    void setId(int id);
    void setCode(const QString& code);
    void setName(const QString& name);
    void setAdresse(const QString& adresse);
    void setTelephone(const QString& telephone);
    void setCodePostal(const QString& codePostal);
    void setEmail(const QString& email);
    void setDomaineId(int domaineId);
    void setAssocTypeId(int typeId);

private:
    int mId;
    QString mCode;
    QString mName;
    QString mAdresse;
    QString mTelephone;
    QString mCodePostal;
    QString mEmail;
    int mDomaineId;
    int mTypeId;

};

#endif // ASSOCIATION_H
