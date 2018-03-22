#include "db.h"

database::database()
{
    this->db = QSqlDatabase::addDatabase("QPSQL");
    this->db.setHostName("83.209.128.51");
    this->db.setDatabaseName("test");
    this->db.setUserName("postgres");
    this->db.setPassword("Stockholm1337");
    if(this->db.open()){
        qDebug() << "Connected to server 83.209.128.51:5432";
    }
}

database::database(QString driver, QString host, QString dbName, QString usrname, QString passw){
    this->db = QSqlDatabase::addDatabase(driver);
    this->db.setHostName(host);
    this->db.setDatabaseName(dbName);
    this->db.setUserName(usrname);
    this->db.setPassword(passw);
    qDebug() << "Connected to custom database";
}

void database::insert_star(QString table, QString values){
    QSqlQuery q;

    //Strings
    if(q.prepare("INSERT INTO "+table+
                 " VALUES (:1,:2)"))    //Add columns here

        qDebug() << "Prepared";
   // q.bindValue(":i",v);              //Add binds for columns here
    q.bindValue(":1",values);



    if(q.exec()){
            qDebug() << "Insert succesful";
    }
    else{
        qDebug() << q.lastError();
    }
}

/**
 * @brief database::delete_row
 * Delete from table with ID identifier
 * @param table
 * @param id
 */
void database::delete_row(QString table, int id){
    QSqlQuery q;
    bool ok = 1;

    if(q.prepare("DELETE FROM "+table+" WHERE id = :id"))
        qDebug() << "Delete prepared";
    q.bindValue(":id",id);
    qDebug() << "Do you want to delete row Y/N?";       //Ja/Nej-ruta i UI?
    if(q.exec())
        qDebug() << "exec success";
    else {
        qDebug() << "exec failed";
    }
}

void database::update_table(QString table, int id, QString cond){
    QSqlQuery q;
    if(q.prepare("UPDATE"+table+ "SET :c WHERE id = :id"))
        qDebug() << "update prepared";
    q.bindValue(":c",cond);
    q.bindValue(":id",id);
    if(q.exec())
        qDebug() << "update executed";


}

