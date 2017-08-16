#include "personobserver.h"

void PersonObserver::personAddedToList(Person newPersonName)
{
    std::cout<<"Dodano nowa osobe: "<<newPersonName.getName()<<" "
            <<newPersonName.getSurname()<<std::endl;
    std::cout<<"Na liscie widnieje "<<personList->getPeopleCount()
            <<" osob"<<std::endl;
}

void PersonObserver::personInListModified(Person oldName,
                                          Person newName)
{
    std::cout<<"Zmodyfikowano osobe "<<oldName.getName()<<" "
            <<oldName.getSurname()<<", teraz nazywa sie: "
            <<newName.getName()<<" "<<newName.getSurname()<<std::endl;
    std::cout<<"Na liscie widnieje "<<personList->getPeopleCount()
            <<" osob"<<std::endl;
}

void PersonObserver::personDeleted(Person name)
{
    std::cout<<"Usunieto osobe: "<<name.getName()<<" "<<name.getSurname()
            <<std::endl;
    std::cout<<"Na liscie widnieje "<<personList->getPeopleCount()
            <<" osob"<<std::endl;
}
