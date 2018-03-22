#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <stdio.h>



class database
{
    QSqlDatabase db;
public:
    database();
    database(QString driver, QString host,QString dbName,QString usrname, QString passw);
    void insert_star(QString table, QString values);
    void delete_row(QString table, int id);
    void update_table(QString table,int id,QString cond);

};

#endif // DB_H
