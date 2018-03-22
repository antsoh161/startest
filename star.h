#ifndef STAR_H
#define STAR_H
#include <QApplication>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>

class star{
    private:
    public:
    //Add all star members
    int idNum = -1;
    QString name;

    star();
    ~star();
    //Add all star related member functions, search, sort etc..
    int getId();
    void setId(int id);
    void setName(QString s);
    QString getN();
    void findStarByName(QString s);
};
#endif // STAR_H
