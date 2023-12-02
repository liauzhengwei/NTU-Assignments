#include <string>

using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

enum COLOR{ Green, Blue, White, Black, Brown };

class Animal;
class Animal{
    public:
        Animal();
        Animal(string n, COLOR c);

        ~Animal();

        string getName();
        virtual void speak();
        virtual void move()=0;

    private:
        string _name;
        COLOR _color;
};


class Mammal:public Animal{
    public:
        Mammal();                 
        Mammal(string n, COLOR c);

        ~Mammal();

        void eat()const;

        virtual void move();
};

#endif