#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

struct IPerson
{
    unsigned age;
    char firstName[20];
    char lastName[20];
};

class Person
{
public:
    Person(unsigned a, char* fn, char* ln)
    {
        age = a;
        strcpy_s(firstName, 20, fn);
        strcpy_s(lastName, 20, ln);
    }
    Person() {}
    unsigned showAge() { return this->age; }
    char* showName() { return this->lastName; }

private:
    unsigned age;
    char firstName[20];
    char lastName[20];
};

int main()
{


    Console::WriteLine("Introduceti numarul de persoane: ");
    int people_count;
    cin >> people_count;
    IPerson* people = new IPerson[people_count];
    for (int i = 0; i < people_count; i++) {
        Console::WriteLine("Introduceti numele persoanei{0}:, ", i + 1);
        char ln[20];
        cin >> ln;
        strcpy_s(people[i].lastName, 20, ln);
        Console::WriteLine("Introduceti prenumele persoanei{0}:, ", i + 1);
        char fn[20];
        cin >> fn;
        strcpy_s(people[i].firstName, 20, fn);
        Console::WriteLine("Introoduceti varsta persoanei {0} ", i + 1);
        unsigned age;
        cin >> age;
        people[i].age = age;
    }
    Console::WriteLine("Afisam numele persoanelor si varstele aferente: ");
    for (int i = 0; i < people_count; i++) {
        cout << people[i].firstName << " " << people[i].lastName << "\t" << people[i].age << endl;
    }
    Console::ReadKey();//Mentine fereastra deschisa
}