#ifndef TYPEASSOCDAO_H
#define TYPEASSOCDAO_H

class QSqlDatabase;
class Type_association;
#include <dao.h>
#include <memory>
#include <vector>
#include <QString>

class typeAssocdao : public Dao
{
public:
    typeAssocdao(QSqlDatabase& database);
    void init() const override;

    void AddTypeAssoc(Type_association& type) const;
    void updateTypeAssoc(const Type_association& type) const;
    void removeTypeAssoc(int id) const;
    QString typeForId(int id) const;

    std::unique_ptr<std::vector<std::unique_ptr<Type_association>>> typeAssoc() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // TYPEASSOCDAO_H
