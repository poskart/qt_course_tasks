#ifndef PERSONOBSERVER_H
#define PERSONOBSERVER_H

#include "personlist.h"

class PersonObserver : public QObject
{
    Q_OBJECT
public:
    PersonObserver(PersonList * pList) : personList(pList){}

    ~PersonObserver(){}

public slots:
    void personAddedToList(Person newPersonName);
    void personInListModified(Person oldName, Person newName);
    void personDeleted(Person name);

private:
    PersonList * personList;
};

#endif // PERSONOBSERVER_H
