#include <iostream>

using namespace std;

class Complex {
	double _real, _imag;
	public:
		Complex() : _real(0.0), _imag(0.0) {}
		Complex(const double real, const double imag) : _real(real), _imag(imag) {}
		
		// member
		Complex operator +(const Complex op);
//		Complex operator *(const Complex op);
		Complex& operator +=(const Complex& op) ;
		void print() ;

//		friend Complex operator +(const Complex op1, const Complex op2);
		friend ostream& operator<<(ostream& os, const Complex& q);
};
