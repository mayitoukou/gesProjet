#include "domaine.h"

Domaine::Domaine(const QString &name) :
            mId(-1),
            mName(name)
{
}

int Domaine::id() const
{
    return  mId;
}

void Domaine::setId(int id)
{
   mId = id ;
}

QString Domaine::name() const
{
    return  mName;
}

void Domaine::setName(const QString& name)
{
    mName = name;
}
