#ifndef PARTENAIRE_H
#define PARTENAIRE_H

#include <QString>
#include "gesprojet_global.h"
#include <vector>
#include <memory>

class GESPROJETSHARED_EXPORT Partenaire
{
public:
    explicit  Partenaire(const QString& name="", const QString& sigle="", const QString& adresse="", const QString& telephone="",
                        const QString& email="", const QString& scan_doc="");

    int Id() const;
    QString getName() const;
    QString getSigle() const;
    QString getAdresse() const;
    QString getTelephone() const;
    QString getEmail() const;
    QString getScan_doc() const;


    void setId(int id);
    void setName(const QString& name);
    void setSigle(const QString& sigle);
    void setAdresse(const QString& adresse);
    void setTelephone(const QString& telephone);
    void setEmail(const QString& email);
    void setScan_doc(const QString& scan_doc);

private:
    int mId;
    QString mName;
    QString mSigle;
    QString mAdresse;
    QString mTelephone;
    QString mEmail;
    QString mScan_doc;

};

#endif // PARTENAIRE_H
