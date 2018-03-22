#include "star.h"

star::star(){
}
star::~star(){
}

void star::setId(int id){
        this->idNum = id;
        return;
}
QString star::getN(){
    return this->name;

}
int star::getId(){
        return idNum;
}
void star::setName(QString s){
    this->name = s;
    return;
}
    //Set this star to found star
void star::findStarByName(QString s){
        QSqlQuery q;
        q.prepare("select * from starstest where name = ?");
        q.addBindValue(s);
        if(q.exec()){
                q.next();
                this->setId(q.value(0).toInt());
                qDebug() << "id set to" << q.value(0).toInt();
                this->setName(q.value(1).toString());
                qDebug() << "name set to " << q.value(1).toString();
        }
        else{
            qDebug() << "findStarByName failed";
            return;
        }
    return;
}
