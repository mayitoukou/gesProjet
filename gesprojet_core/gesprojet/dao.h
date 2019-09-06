#ifndef DAO_H
#define DAO_H


class  Dao
{
public:
    Dao() {}
    virtual ~Dao() {}

    virtual void init() const = 0;

};

#endif // DAO_H
