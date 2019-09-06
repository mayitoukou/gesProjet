#ifndef DOMAINEDAO_H
#define DOMAINEDAO_H

class QSqlDatabase;
class Domaine;
#include <dao.h>
#include <memory>
#include <vector>
#include <QString>

class DomaineDao : public Dao
{
public:
    DomaineDao(QSqlDatabase& database);
    void init() const override;

    void AddDomaine(Domaine& domaine) const;
    void updateDomaine(const Domaine& domaine) const;
    void removeDomaine(int id) const;
    QString domaineForId(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Domaine>>> domaine() const;


private:
    QSqlDatabase& mDatabase;

};

#endif // DOMAINEDAO_H

