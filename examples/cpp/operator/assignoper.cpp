/*
 * Copyright (c) airfox 2012.
 *
 * \brief Duplicating what is pointed to during assignment 
 * and copy-construction.
 */

#include <string>
#include <iostream>
using namespace std;

class Dog
{
public:
    Dog(const string &name) : m_name(name)
    {
    }

    Dog(const Dog &other) : m_name(other.m_name + " Copy")
    {
    }

    void Rename(const string &name)
    {
        m_name = name;
    }

    friend ostream &operator<<(ostream &os, const Dog &dog)
    {
        return os<<"["<<dog.m_name<<"]"<<endl;
    }

private:
    string m_name;
};

class DogHouse
{
public:
    DogHouse(Dog *dog, const string &name) : m_dog(dog), 
        m_houseName(name)
    {
    }

    DogHouse(const DogHouse &other) : m_dog(new Dog(*(other.m_dog))), 
        m_houseName(other.m_houseName + " Copy")
    {
    }

    ~DogHouse()
    {
        delete m_dog;
    }

    Dog *GetDog() const
    {
        return m_dog;
    }

    DogHouse &operator=(const DogHouse &other)
    {
        if(&other == this)
        {
            return *this;
        }

        delete m_dog;
        m_dog = new Dog(*(other.m_dog));
        m_houseName = other.m_houseName + " Assigned";

        return *this;
    }

    void Rename(const string &name)
    {
        m_houseName = name;
    }

    friend ostream &operator<<(ostream &os, const DogHouse &house)
    {
        return os<<"["<<house.m_houseName<<"]"<<
            " contains "<<*(house.m_dog);
    }
private:
    Dog *m_dog;
    string m_houseName;
};

int main()
{
    DogHouse house(new Dog("fox"), "fox's house");
    cout<<house<<endl;

    DogHouse house2 = house;
    cout<<house2<<endl;

    house2.GetDog()->Rename("tony");
    house2.Rename("tony's house");
    cout<<house2<<endl;

    // assignment
    house = house2;
    cout<<house<<endl;

    return 0;
}
