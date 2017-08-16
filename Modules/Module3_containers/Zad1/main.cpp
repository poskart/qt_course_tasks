#include <QCoreApplication>
#include "QMap"
#include <iostream>
#include "QDebug"

class Person
{
public:
    Person(){}
    Person(QString n, QString s, int a) :
        name(n), surname(s), age(a)
    {}
    virtual ~Person(){}
    friend std::ostream& operator<< (std::ostream& stream, const Person& p)
    {
        stream<<p.name.toStdString()<<" "<<p.surname.toStdString()<<" "<<p.age<<std::endl;
        return stream;
    }
    friend QDebug operator<< (QDebug stream, const Person& p)
    {
        stream<<p.name<<" "<<p.surname<<" "<<QString::number(p.age);
        return stream;
    }
    operator QString()
    {
        return name+surname+QString::number(age);
    }

    int getAge(void)
    {
        return age;
    }

private:
    QString name;
    QString surname;
    int age;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Person> lista;
    QMap<int, Person> mapa;

    Person tab[20];
    tab[0] = Person("Maciej", "Skorża", 45);
    tab[1] = Person("Paweł", "Janas", 56);
    tab[2] = Person("Piotr", "Poskart", 24);
    tab[3] = Person("Romuald", "Traugutt", 244);
    tab[4] = Person("Adam", "Małysz", 44);
    tab[5] = Person("Luiza", "Złotkowska", 28);
    tab[6] = Person("Robert", "Kubica", 30);
    tab[7] = Person("Robert", "lewandowski", 29);

    for(int i = 0; i < 8; i++)
    {
        lista.append(tab[i]);
        mapa.insert(mapa.end(), i, tab[i]);
    }

    std::cout<<"Lista osob:"<<std::endl;
    for(Person& p:lista)
        std::cout<<p;
    std::cout<<"Lista osob inną metodą:"<<std::endl;
    for(Person& p:lista)
        qDebug()<<p;

    qDebug()<<"Lista za pomocą iteratora stl:";
    QList<Person>::iterator it = lista.begin();
    for(; it != lista.end(); it++)
    {
        qDebug()<<*it;
    }
    qDebug()<<"Lista za pomocą iteratora java:";
    QListIterator<Person> iter(lista);
    while(iter.hasNext())
        qDebug()<<iter.next();

    qDebug()<<"Wyswietlanie mapy:";
    for(int i = 0; i < 8; i++)
    {
        qDebug()<<mapa.take(i);
    }

    QMutableListIterator<Person> rmIter(lista);
    while(rmIter.hasNext())
    {
        if(rmIter.next().getAge()%2 == 0)
            rmIter.remove();
    }

    QMap<int, Person>::iterator qmI;
    for(qmI = mapa.begin(); qmI != mapa.end(); qmI++)
        if((*qmI).getAge()%2 == 0)
            qmI = mapa.erase(qmI);

    qDebug()<<"\nUsuwanie\n";

    QListIterator<Person> iter2(lista);
    qDebug()<<"Lista za pomocą iteratora java:";
    iter2.toFront();
    while(iter2.hasNext())
        qDebug()<<iter2.next();

    qDebug()<<"Wyswietlanie mapy:";
    QMapIterator<int, Person> qmIt(mapa);
    while(qmIt.hasNext())
        qDebug()<<qmIt.next().value();

    std::cout<<"Rozmiar mapy: "<<mapa.size()<<std::endl;

    return a.exec();
}
