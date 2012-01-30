/*
 * Copyright (c) airfox 2012.
 *
 * \brief Refrence counting, copy-on-write
 */

#include <string>
#include <iostream>
using namespace std;

class Dog
{
public:
    // Only created on the heap.
    static Dog *CreateDog(const string &name)
    {
        return new Dog(name);
    }

    Dog(const Dog &other) : m_name(other.m_name + " copy"), m_refcount(1)
    {
        cout<<"Dog copy constructor: "<<*this<<endl;
    }

    ~Dog()
    {
        cout<<"Deleting Dog: "<<*this<<endl;
    }

    void AddRef()
    {
        cout<<"Attaching Dog: "<<*this<<endl;
        ++m_refcount;
    }

    void Release()
    {
        cout<<"Detaching Dog: "<<*this<<endl;
        if(--m_refcount == 0)
        {
            delete this;
        }
    }

    // Copy this dog, before modifying(Copy-On-Write).
    Dog *Copy()
    {
        cout<<"Copying Dog: "<<*this<<endl;
        if(m_refcount == 1)
        {
            return this;
        }

        --m_refcount;
        return new Dog(*this);
    }

    void Rename(const string &name)
    {
        m_name = name;
        cout<<"Dog renamed to: "<<*this<<endl;
    }

    friend ostream &operator<<(ostream &os, const Dog &dog)
    {
        os<<"["<<dog.m_name<<"], rc = "<<dog.m_refcount;
    }

protected:
    // Constructor.
    Dog(const string &name) : m_name(name), m_refcount(1)
    {
        cout<<"Creating Dog: "<<*this<<endl;
    }

    // Prevent assignment.
    Dog &operator=(const Dog &other);

private:
    string m_name;
    int m_refcount;
};

class DogHouse
{
public:
    DogHouse(Dog *dog, const string &name) : m_dog(dog), m_name(name)
    {
        cout<<"Created DogHouse: "<<*this<<endl;
    }

    ~DogHouse()
    {
        cout<<"Release DogHouse: "<<*this<<endl;
        m_dog->Release();
    }

    DogHouse(const DogHouse &other) : m_dog(other.m_dog), 
        m_name(other.m_name + " copy")
    {
        m_dog->AddRef();
        cout<<"DogHouse copy constructor: "<<*this<<endl;
    }

    DogHouse &operator=(const DogHouse &other)
    {
        if(&other == this)
        {
            return *this;
        }

        m_dog->Release();
        m_dog = other.m_dog;
        m_dog->AddRef();
        m_name = other.m_name + " assignment";

        cout<<"DogHouse operator=: "<<*this<<endl;
        return *this;
    }

    void Rename(const string &name)
    {
        m_name = name;
    }

    void RenameDog(const string &name)
    {
        CopyOnWrite();
        m_dog->Rename(name);
    }

    void CopyOnWrite()
    {
        m_dog = m_dog->Copy();
    }

    Dog *GetDog()
    {
        CopyOnWrite();
        return m_dog;
    }

    friend ostream &operator<<(ostream &os, const DogHouse &house)
    {
        os<<"["<<house.m_name<<"] contains "<<*(house.m_dog);
    }

private:
    string m_name;
    Dog *m_dog;
};

int main()
{
    DogHouse tony(Dog::CreateDog("Tony"), "Tony's house");
    DogHouse fox(Dog::CreateDog("Fox"), "Fox's house");

    DogHouse bob(tony);
    cout<<"After copy constructing:"<<endl;
    cout<<"Tony: "<<tony<<endl;
    cout<<"Fox: "<<fox<<endl;
    cout<<"Bob: "<<bob<<endl;
    cout<<endl;

    fox = tony;
    cout<<"After fox = tony: "<<endl;
    cout<<"Fox: "<<fox<<endl;
    cout<<endl;

    bob = bob;
    cout<<"After bob self assignment: "<<endl;
    cout<<"Bob: "<<bob<<endl;
    cout<<endl;

    bob.GetDog()->Rename("Bob");
    cout<<"After rename bob: "<<endl;
    cout<<"Tony: "<<tony<<endl;
    cout<<"Fox: "<<fox<<endl;
    cout<<"Bob: "<<bob<<endl;

    return 0;
}
