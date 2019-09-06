/*
* Classe permettant d'effectuer les différentes requettes
* de la classe Association
*/

#ifndef ASSOCIATIONDAO_H
#define ASSOCIATIONDAO_H

class QSqlDatabase;
class Association;

#include <dao.h>
#include <memory>
#include <vector>
#include <QString>


class AssociationDao : public Dao
{
public:
    AssociationDao(QSqlDatabase& database);
    void init() const;

    void AddAssociation(Association& association) const;
    void removeAssociation(int id) const;
    void removeAssocForDomaine(int domaineId) const;
    void updateAssociation(Association& association) const;
    QString associationForId(int id) const;
     std::unique_ptr<std::vector<std::unique_ptr<Association>>> association() const;

private:
     QSqlDatabase& mDatabase;
};

#endif // ASSOCIATIONDAO_H
