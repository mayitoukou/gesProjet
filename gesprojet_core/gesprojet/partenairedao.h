#ifndef PARTENAIREDAO_H
#define PARTENAIREDAO_H

class QSqlDatabase;
class Partenaire;
#include <dao.h>
#include <memory>
#include <vector>
#include <QString>


class PartenaireDao : public Dao
{
public:
    PartenaireDao(QSqlDatabase& database);
    void init() const override;

    void AddPartenaire(Partenaire& partenaire) const;
    void updatePartenaire(const Partenaire& partenaire) const;
    void removePartenaire(int id) const;
    QString partenaireForId(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Partenaire>>> partenaire() const;

private:
    QSqlDatabase& mDatabase;


};

#endif // PARTENAIREDAO_H
