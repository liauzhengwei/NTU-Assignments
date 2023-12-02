#include <string>
#include "animal.h"
using namespace std;

#ifndef CHILDANIMAL_H
#define CHILDANIMAL_H

class Dog:public Mammal{
    public:
        Dog();

        Dog(string n,COLOR c, string o);

        ~Dog(); 

        void speak();
        void move()override;

    private:
        string _owner;    
};

class Cat:public Mammal{
    public:
        Cat();

        Cat(string n,COLOR c);

        ~Cat();

        void speak();
        void move();
};

class Lion:public Mammal{
    public:
        Lion();
        Lion(string n,COLOR c);

        ~Lion();

        void speak();
        void move();
};

#endif