#include "personlist.h"

void PersonList::addPerson(Person p)
{
    listOfPerson.push_back(p);
    emit add(p);
}
void PersonList::removePerson(Person p)
{
    std::vector<Person>::iterator it = listOfPerson.begin();
    Person deletedPerson;
    for(; it != listOfPerson.end(); ++it)
    {
        if((*it) == p)
        {
            deletedPerson = *it;
            listOfPerson.erase(it);
            emit rem(deletedPerson);
            return;
        }
    }
}
void PersonList::updatePerson(Person oldP, Person newP)
{
    std::vector<Person>::iterator it = listOfPerson.begin();
    for(; it != listOfPerson.end(); ++it)
    {
        if(*it == oldP)
        {
            (*it) = newP;
            emit mod(oldP, newP);
            return;
        }
    }
}

void PersonList::printList(void)
{
    std::vector<Person>::iterator it = listOfPerson.begin();
    for(; it != listOfPerson.end(); it++)
    {
        std::cout<<(*it).getName()<<" "<<(*it).getSurname()<<std::endl;
    }
}
