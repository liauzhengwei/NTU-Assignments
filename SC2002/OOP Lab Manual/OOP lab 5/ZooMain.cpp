/*TO RUN THE CODE
    g++ -o ZooMain.exe animal.cpp childAnimal.cpp ZooMain.cpp
    ./ZooMain.exe

    Another Method:
    g++ -c *.cpp -o ZooMain
    ./ZooMain.exe

*/
using namespace std;

#include <iostream>
#include <string>
#include "animal.h"
#include "childAnimal.h"

int main(){
    //Animal a = Animal("cat",COLOR::Black);
    //color argument return number instead of color when enum used, 
    //need to convert to String as shown above i guess  
    //a.speak();

    //Mammal m = Mammal("sheep",COLOR::White);
    //m.speak();
    /*Mammal *mamPtr = new Mammal("sheep",COLOR::White);
    mamPtr->speak();

    //Dog d = Dog("dog",COLOR::Blue,"me");
    //d.speak();

    Animal *dogPtr = new Dog("dog",COLOR::Blue,"me");
    dogPtr->speak();
    dogPtr->move();

    Animal *animalPtr = new Dog("Lassie",White,"Andy");
    animalPtr->speak();
    animalPtr->move();
    */

    /*Dog dogi("Lassie",White,"Andy");
    Mammal *aniPtr = &dogi;
    Mammal &aniRef = dogi;
    Mammal aniVal = dogi;

    aniPtr->speak();
    aniRef.speak(); 
    aniVal.speak(); 
    */

    cout << "Select the animal to send to Zoo:\n" << endl;
    cout<< "(1)Dog (2)Cat (3)Lion (4)Move all animals (5)Quit\n" << endl;

    int choice = 0;
    Mammal **zoo = new Mammal*[3];
    //Animal **zoo = new Animal*[3]; //doesnt work as Animal has no eat() function and move() is pure virtual
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Lion();

    while(choice !=5){
        cin >> choice;

        switch(choice){
            case 1:
                zoo[0]->speak();
                zoo[0]->move(); 
                zoo[0]->eat();
                break;
            case 2:
                zoo[1]->speak();
                zoo[1]->move(); 
                zoo[1]->eat();
                break;
            case 3:
                zoo[2]->speak();
                zoo[2]->move(); 
                zoo[2]->eat();
                break;
            case 4:
                for(int j = 0; j < 3; j++){
                    zoo[j]->move();
                    zoo[j]->speak();
                    zoo[j]->eat();
                }
                break;
            case 5:
                break;
            default:
                cout<< "Choose an option form 1 to 5\n" << endl;
        }
    }

    cout<<"Program exiting..." << endl;  
    //_name is "unknown" when object constructed 
    //deconstructor is called when the program exits,name is still "unknown"
    return 0;
}