#include <iostream>
#include <string>
#include "childAnimal.h"

using namespace std;

#ifdef CHILDANIMAL_H
#define CHILDANIMAL_H   

Dog::Dog():Mammal(){
    cout << "constructing Dog object" << Dog::getName()<<endl;
}

Dog::Dog(string n,COLOR c, string o):Mammal(n,c){
    cout << "constructing Dog object" <<Dog::getName()<<endl;
    _owner = o;
}

Dog::~Dog(){
    cout << "destructing Dog object" <<Dog::getName()<<endl;
}   

void Dog::speak(){
    cout<<  "Woof"    <<endl;
}
void Dog::move(){
    cout<< "Dog move " <<endl;
}

Cat::Cat():Mammal(){
    cout << "constructing Cat object" <<Cat::getName()<<endl;
}

Cat::Cat(string n,COLOR c):Mammal(n,c){
    cout << "constructing Cat object" <<Cat::getName()<<endl;
}

Cat::~Cat(){
    cout << "destructing Cat object" <<Cat::getName()<<endl;
}   

void Cat::speak(){
    cout<<  "Cat meow"    <<endl;
}
void Cat::move(){
    cout<< "Cat move " <<endl;
}


Lion::Lion():Mammal(){
    cout << "constructing Lion object" <<Lion::getName()<<endl;
}
Lion::Lion(string n,COLOR c):Mammal(n,c){
    cout << "constructing Lion object" <<Lion::getName()<<endl;
}

Lion::~Lion(){
    cout << "destructing Lion object" <<Lion::getName()<<endl;
}   

void Lion::speak(){
    cout<<  "Lion Roar"    <<endl;
}
void Lion::move(){
    cout<< "Lion move " <<endl;
}

#endif  