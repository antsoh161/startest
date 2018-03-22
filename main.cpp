#include "mainwindow.h"
#include <QApplication>
#include "mainwindow.h"
#include <star.h>
#include "db.h"
#include <QApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlDriver>

//Test123
//testting branch
//Branch ?
//Add this to master

int main(int argc, char *argv[]) {
     //qputenv("QT_DEBUG_PLUGINS", QByteArray("1"));
     QApplication a(argc, argv);
     MainWindow w;
     w.show();

     database db2 = database();
     db2.delete_row("starstest",10);
     db2.update_table("starstest",5,"namn = 'sol27'");
     star s;



     return a.exec();
}

