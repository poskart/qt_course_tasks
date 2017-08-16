#ifndef PERSONLIST_H
#define PERSONLIST_H

#include "person.h"
#include <QObject>

class PersonList : public QObject
{
    Q_OBJECT
public:
    PersonList(){}
    virtual ~PersonList(){}

    int getPeopleCount(void){ return listOfPerson.size();}
    void addPerson(Person p);
    void removePerson(Person p);
    void updatePerson(Person oldP, Person newP);
    void printList(void);
signals:
    void add(const Person & p);
    void rem(const Person & p);
    void mod(const Person & oldP, const Person & newP);
private:
    std::vector<Person> listOfPerson;
};

#endif // PERSONLIST_H
