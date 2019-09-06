#ifndef DOMAINE_H
#define DOMAINE_H

#include <QString>
#include "gesprojet_global.h"

class GESPROJETSHARED_EXPORT Domaine
{

public:
    explicit  Domaine(const QString& name = "" );

    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString& name);

private:
    int mId;
    QString mName;
};

#endif // DOMAINE_H
