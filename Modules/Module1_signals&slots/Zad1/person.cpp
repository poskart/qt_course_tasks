#include "person.h"

Person::Person(std::string name, std::string surname, int age)
{
    this->name = name;
    this->surname = surname;
    this->age = age;
}

bool Person::operator==(const Person & p)
{
    if(this->name == p.name &&
            this->surname == p.surname &&
            this->age == p.age)
        return true;
    return false;
}

Person & Person::operator=(const Person & rightP)
{
    this->name = rightP.name;
    this->surname = rightP.surname;
    this->age = rightP.age;
}

std::string Person::getName()
{
    return name;
}

std::string Person::getSurname(void)
{
    return surname;
}

int Person::getAge(void)
{
    return age;
}

