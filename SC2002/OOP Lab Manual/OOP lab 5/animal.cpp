#include <string>
#include <iostream>

#include "animal.h"
using namespace std;

#ifdef ANIMAL_H
#define ANIMAL_H

Animal::Animal(): _name("unknown"){
        cout << "constructing Animal object " << _name << endl;
    }
Animal::Animal(string n, COLOR c){
        _name = n;
        _color = c;
        string colors[5] = {"Green", "Blue", "White", "Black", "Brown"};  

        cout << "constructing Animal object " << _name << endl;
        cout<< n << " is " << colors[c] << " in color\n"   << endl;    
    }
Animal::~Animal(){
    cout << "destructing Animal object " << _name << endl;
    }

string Animal::getName(){return _name;}

        /*void speak() const{
            cout << "Animal speaks\n " << endl;
        }*/
void Animal::speak(){
    cout << "Animal speaks\n " << endl;
}    

Mammal::Mammal():Animal(){
    cout << "constructing Mammal object" <<Mammal::getName() << endl;
}              
Mammal::Mammal(string n, COLOR c):Animal(n, c){
    cout << "constructing Mammal object" <<Mammal::getName() << endl;
}

Mammal::~Mammal(){
    cout << "destructing Mammal object" <<Mammal::getName()<<endl;
}

void Mammal::eat()const{
    cout<< "Mammal eat " <<endl;
}

void Mammal::move(){
    cout<< "Mammal move " <<endl;    
}

//put types in front of function names
//put "current class name ::"

#endif