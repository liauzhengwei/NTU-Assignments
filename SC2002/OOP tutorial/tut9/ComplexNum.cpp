#include "complexnum.h"

Complex Complex::operator+(const Complex op){
			double real = _real + op._real ;
			double imag = _imag + op._imag;
			return(Complex(real, imag));
		}
/*
Complex Complex::operator*(const Complex op){
	// your task to practice ;
		}
*/
Complex& Complex::operator +=(const Complex& op) {
			this->_real += op._real ;
			this->_imag +=  op._imag;
			return *this;
		}

void Complex::print() { cout << _real << " + " << _imag << "i" << endl; }
/*
// non member
Complex operator +(const Complex op1, const Complex op2){
	double real = op1._real + op2._real ;
	double imag = op1._imag + op2._imag;
	return(Complex(real, imag));
}
*/
// for cout	
ostream& operator<<(ostream& os, const Complex& q)
{
	os << q._real << " + " << q._imag << "i" << endl ;
	return os;
};

int main() {
	Complex a(1,1),b(1,2),c;
	c = a + b + b ;
	c.print() ;
 
	c+=a ;
	c.operator+=(a) ;
	
	cout << c << a;
	// if you have coded operator*, uncomment this to test
	// Complex d = (a + b)*(a + b)
	// cout << d  ;
	int i ;
	cin >> i ;
}

/*
		
    // test with cout << ++a ;
	Complex& operator++() { // prefix ++a
        // actual increment takes place here
		this->_imag +=1 ;
		this->_real +=1;
        return *this;
    }

	 // test with cout << a++ ;
    Complex operator++(int) {  //postfix a++
        Complex tmp(*this); // copy
        operator++(); // pre-increment
        return tmp;   // return old value
    }



*/