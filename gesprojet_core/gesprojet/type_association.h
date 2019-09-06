#ifndef TYPE_ASSOCIATION_H
#define TYPE_ASSOCIATION_H

#include <QString>
#include "gesprojet_global.h"

class GESPROJETSHARED_EXPORT Type_association
{
public:
    explicit  Type_association(const QString& libelle = "");

    int id() const;
    void setId(int id);
    QString libelle() const;
    void setlibelle(const QString& libelle);

private:
    int mId;
    QString mlibelle;
};

#endif // TYPE_ASSOCIATION_H
