#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>
#include <iostream>

class Person
{
public:
    Person():name(""), surname(""), age(0){}
    Person(std::string name, std::string surname, int age);
    std::string getName(void);
    std::string getSurname(void);
    int getAge(void);

    ~Person(){}
    bool operator==(const Person & p);
    Person & operator=(const Person & rightP);
private:
    std::string name;
    std::string surname;
    int age;
};

#endif // PERSON_H
