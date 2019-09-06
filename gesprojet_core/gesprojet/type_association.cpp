#include "type_association.h"

Type_association::Type_association(const QString& libelle) :
        mId(-1),
        mlibelle(libelle)
{

}

int Type_association::id() const
{
    return  mId;
}

void Type_association::setId(int id)
{
    mId = id;
}

QString Type_association::libelle() const
{
    return mlibelle;
}

void Type_association::setlibelle(const QString& libelle)
{
    mlibelle = libelle;
}
