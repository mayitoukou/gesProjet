#ifndef PROJETDAO_H
#define PROJETDAO_H

class QSqlDatabase;
class Projet;
#include <dao.h>
#include <memory>
#include <vector>

class ProjetDao : public Dao
{
public:
    ProjetDao(QSqlDatabase& database);
    void init() const override;

    void AddProjetInAssoc(int partenaireId, int associationId, Projet& projet) const;
    void updateProjet(int partenaireId, int associationId, Projet& projet) const;
    void removeProjet(int id) const;
    void removeProjetForAssociation(int associationId) const;
    std::unique_ptr<std::vector<std::unique_ptr<Projet>>> projet( int associationId) const;

private:
    QSqlDatabase& mDatabase;


};

#endif // PROJETDAO_H
