#include<iostream>
using namespace std;
#include <string>

class Polygon {
    public:
        virtual float calArea() = 0;
        enum KindofPolygon {POLY_RECT, POLY_TRIANG};

        Polygon(float w, float h, string n, KindofPolygon p) {
            width = w;
            height = h;
            name = n;
            polytype = p;
        }

        string getName() {
            return name;
        }

        KindofPolygon getPolytype() {
            return polytype;
        }

        KindofPolygon setPolytype(KindofPolygon p) {
            polytype = p;
        }

        void printWidthHeight(){
            cout << "Width: " << width << endl;
            cout << "Height: " << height << endl;
        }

    protected: 
        float width, height;
        string name;
        KindofPolygon polytype;
};

class Rectangle: public Polygon {
    public:
        Rectangle(float w, float h, string n, KindofPolygon p):Polygon(w, h, n, p) {  
            this->polytype = POLY_RECT;
        }

        float calArea() {
            return (width * height);
        }
};

class Triangle:public Polygon{
    public:
        Triangle(float w, float h, string n, KindofPolygon p):Polygon(w,h,n,p){
            this->polytype = POLY_TRIANG;
        }
        
        float calArea(){
            return (width * height)/2;
        }
};

class TestPolygon{
    public: 
        void printArea(Polygon *p){
            cout << "Area of " << p->getPolytype()<< p->getName() << " is " << p->calArea() << endl;
        }
};

int main(){
    TestPolygon test;

    Rectangle rect(4,5,"Rectangle", Polygon::POLY_RECT);
    test.printArea(&rect);
    rect.printWidthHeight();
    
    Triangle triang(4,5,"Triangle", Polygon::POLY_TRIANG);
    test.printArea(&triang);
    triang.printWidthHeight();

}