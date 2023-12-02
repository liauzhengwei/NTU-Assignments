#include <iostream>
#include <string>

using namespace std;

enum COLOR{ Green, Blue, White, Black, Brown };

class Animal{
    public:
        Animal(): _name("unknown"){
            cout << "constructing Animal object " << _name << endl;
        }
        Animal(string n, COLOR c){
            _name = n;
            _color = c;
            string s = colorToString(c);
            cout << "constructing Animal object " << _name << endl;
            cout<< n << " is " << s << " in color\n"   << endl;    
        }

        ~Animal(){
            cout << "destructing Animal object " << _name << endl;
        }

        string colorToString(COLOR c){
            switch(c){
                case Green:
                    return "Green";
                case Blue:
                    return "Blue";
                case White:
                    return "White";
                case Black:
                    return "Black";
                case Brown:
                    return "Brown";
                default:
                    return "Unknown";
            }
        }
        string getName(){return _name;}

        /*void speak() const{
            cout << "Animal speaks\n " << endl;
        }*/
        virtual void speak() const{
            cout << "Animal speaks\n " << endl;
        }
        virtual void move() const=0;

    private:
        string _name;
        COLOR _color;
};


class Mammal:public Animal{
    public:
        Mammal(){
            cout << "constructing Mammal object" <<getName() << endl;
        }              
        Mammal(string n, COLOR c):Animal(n, c){
            cout << "constructing Mammal object" <<getName() << endl;
        }

        ~Mammal(){
            cout << "destructing Mammal object" <<getName()<<endl;
        }

        void eat() const{
            cout<< "Mammal eat " <<endl;
        }

        void move() const{
            cout<< "Mammal move " <<endl;
        }
};

class Dog:public Mammal{
    public:
        Dog(){
            cout << "constructing Dog object" <<getName()<<endl;
        }

        Dog(string n,COLOR c, string o):Mammal(n,c){
            cout << "constructing Dog object" <<getName()<<endl;
            _owner = o;
        }

        ~Dog(){
            cout << "destructing Dog object" <<getName()<<endl;
        }   

        void speak()const{
            cout<<  "Woof"    <<endl;
        }
        void move() const{
            cout<< "Dog move " <<endl;
        }

    private:
        string _owner;    
};

class Cat:public Mammal{
    public:
        Cat(){
            cout << "constructing Cat object" <<getName()<<endl;
        }

        Cat(string n,COLOR c):Mammal(n,c){
            cout << "constructing Cat object" <<getName()<<endl;
        }

        ~Cat(){
            cout << "destructing Cat object" <<getName()<<endl;
        }   

        void speak()const{
            cout<<  "Cat meow"    <<endl;
        }
        void move() const{
            cout<< "Cat move " <<endl;
        } 
};

class Lion:public Mammal{
    public:
        Lion(){
            cout << "constructing Lion object" <<getName()<<endl;
        }
        Lion(string n,COLOR c):Mammal(n,c){
            cout << "constructing Lion object" <<getName()<<endl;
        }

        ~Lion(){
            cout << "destructing Lion object" <<getName()<<endl;
        }   

        void speak()const{
            cout<<  "Lion Roar"    <<endl;
        }
        void move() const{
            cout<< "Lion move " <<endl;
        } 
};

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
