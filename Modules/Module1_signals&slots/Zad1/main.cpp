#include <QCoreApplication>
#include "personobserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person p1("Anna", "Baranna", 24);
    Person p2("Zbych", "Szybki", 65);
    Person p3("Andrzej", "Duda", 48);

    PersonList * myList = new PersonList();
    PersonObserver observer(myList);

    QObject::connect(myList, SIGNAL(add(Person)), &observer, SLOT(personAddedToList(Person)));
    QObject::connect(myList, SIGNAL(rem(Person)), &observer, SLOT(personDeleted(Person)));
    QObject::connect(myList, SIGNAL(mod(Person, Person)), &observer, SLOT(personInListModified(Person, Person)));

    myList->addPerson(p3);
    myList->addPerson(p2);
    myList->addPerson(p1);
    std::cout<<"Dodano 3 osoby..."<<std::endl;

    Person p4("Antoni", "Dębiński", 55);
    myList->updatePerson(p3, p4);
    std::cout<<std::endl;

    myList->removePerson(p2);

    std::cout<<"Lista: "<<std::endl;
    myList->printList();

    std::cout<<"koniec\n";


    delete myList;
    int tmp;
    std::cin>>tmp;
    return a.exec();
}
