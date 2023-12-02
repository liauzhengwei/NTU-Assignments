#include <iostream>
using namespace std;

/*class A{
    protected:
        int a,b;
    public:
    A():a(0),b(0){}
    A(int x, int y):a(0),b(y){}
    virtual void print();
    int getA(){return a;}

    A operator+(A obj){
        return A(a+obj.a, b+obj.b);
    }
};


class B:public A{
    private:
        float p,q;
    public:
        B():p(0),q(0){}
        B(int m,int n, float u,float v):A(m,n),p(u),q(v){}
        void input(float x, float y);
        virtual void print(float);
};
void A::print(){
    cout<<"A values: "<< a << " " << b <<"\n";
}
void B::print(float){
    cout<<"B values: "<< p << " "<< q <<"\n";
}
void B::input(float x, float y){
    p=x;
    q=y;
}
int doubleIt(A a){return a.getA()*a.getA();}



int main(){
    A a1(10,20), *ptr;
    //A a2(30,5);
    //A a3 = a1.operator+(a2);

    B b1;
    b1.input(7.5,3.142);

    //ptr = &a3;
    ptr = &a1;
    ptr->print();
    ptr = &b1;
    ptr->print();
}*/

class BC{
    public:
        void show(void){cout<< " \n I am in the base class.."; }
};
class DC: public BC{
    public:
        void show(void){ cout<< " \n I am in derived class.."; }
};
int main(){
    BC *ptr1;
    DC dobj;
    ptr1 = &dobj;
    ptr1->show();
}
