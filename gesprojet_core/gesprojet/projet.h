#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QDate>
#include "gesprojet_global.h"


class GESPROJETSHARED_EXPORT Projet
{
public:
     Projet();
     Projet(const QString& titre, const QString& descriptif, QDate date_debut, QDate date_fin, const QString& objectif, const QString& nameChef, const QString& prenomChef,
                    const QString& telephoneChef, const QString& emailChef, const QString& continent, const QString& pays, const QString& region, const QString& localite, double cout, int partenaireId, int assocId);

    int Id() const;
    QString getTitre() const;
    QString getDescriptif() const;
    QDate getDatedebut() const;
    QDate getDateFin() const;
    QString getObjectif() const;
    QString getNameChef() const;
    QString getPrenomChef() const;
    QString getTelephoneChef() const;
    QString getEmailChef() const;
    QString getContient() const;
    QString getPays() const;
    QString getRegion() const;
    QString getLocalite() const;
    double getCout() const;
    int getPartenaireId() const;
    int  getAssociationId() const;

    void setId(int id);
    void setTitre(const QString& titre);
    void setDescriptif(const QString& descriptif);
    void setDatedebut(QDate date_debut);
    void setDatefin(QDate date_fin);
    void setObjectif(const QString& objectif);
    void setNameChef( const QString& nameChef);
    void setPrenomChef(const QString& prenomChef);
    void setTelephoneChef(const QString& telephoneChef);
    void setEmailChef(const QString& emailChef);
    void setContient(const QString& continent);
    void setPays(const QString& pays);
    void setRegion(const QString& region);
    void setLocalite(const QString& localite);
    void setCout(double cout);
    void setPartenaireId(int partenaireId);
    void setAssociationId(int  associationId);

private:
    int mId;    
    QString mTitre;
    QString mDescriptif;
    QDate mDateDebut;
    QDate mDateFin;
    QString mObjectif;
    QString mName_chef;
    QString mPrenom_chef;
    QString mTelephone_chef;
    QString mEmail_chef;
    QString mContient;
    QString mPays;
    QString mRegion;
    QString mLocalite;
    double mCout;
    int mPartenaireId;
    int mAssociationId;

};

#endif // PROJET_H
