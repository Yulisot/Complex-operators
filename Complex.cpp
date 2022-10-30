#include "Complex.h"
using std::endl;


Complex::Complex()
{
	real = 0;
	imaginary = 0;
}

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}

void Complex::set_real(double r)
{
	real = r;
}

void Complex::set_imaginary(double i)
{
	imaginary = i;
}

double Complex::get_real() const
{
	return real;
}

double Complex::get_imaginary() const
{
	return imaginary;
}

Complex Complex::operator+(const Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(this->get_real() + other.get_real());
	tmp->set_imaginary(this->get_imaginary() + other.get_imaginary());
	return *tmp;
}

Complex Complex::operator+=(const Complex& other)
{
	Complex* tmp = new Complex;
	this->set_real(this->get_real() + other.get_real());
	this->set_imaginary(this->get_imaginary() + other.get_imaginary());
	return *tmp;
	
}

Complex Complex::operator*=(const Complex& other) 
{
	Complex* tmp = new Complex;
	Complex* tmp1 = new Complex;
	tmp1->set_real((this->get_real() * other.get_real()) - (this->get_imaginary() * other.get_imaginary()));
	this->set_real(tmp1->get_real());
	tmp->set_imaginary((this->get_real() * other.get_imaginary()) + (this->get_imaginary() * other.get_real()));
	this->set_imaginary(tmp->get_imaginary());
	return *this;

	
}

Complex Complex::operator/=(const Complex& other) 
{
	Complex* tmp = new Complex;
	Complex* tmp1 = new Complex;
	tmp->set_real(this->get_real() * other.get_real() + this->get_imaginary() * other.get_imaginary());
	tmp1->set_real(other.get_real() * other.get_real() + other.get_imaginary() * other.get_imaginary());
	this->set_real(tmp->get_real() / tmp1->get_real());
	tmp->set_imaginary((this->get_imaginary() * other.get_real()) - (this->get_real() * other.get_imaginary()));
	tmp1->set_imaginary(other.get_real() * other.get_real() + other.get_imaginary() * other.get_imaginary());
	this->set_imaginary((tmp->get_imaginary()) / (tmp1->get_imaginary()));
	return *tmp;
}

Complex Complex::operator-=(const Complex& other)
{
	Complex* tmp = new Complex;
	this->set_real(this->get_real() - other.get_real());
	this->set_imaginary(this->get_imaginary() - other.get_imaginary());
	return *tmp;

}

Complex Complex::operator-(const Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(this->get_real() - other.get_real());
	tmp->set_imaginary(this->get_imaginary() - other.get_imaginary());
	return *tmp;


}

Complex Complex::operator*(const Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real((this->get_real() * other.get_real()) - (this->get_imaginary() * other.get_imaginary()));
	tmp->set_imaginary((this->get_real() * other.get_imaginary()) + ((this->get_imaginary() * other.get_real())));
	return *tmp;
}

Complex Complex::operator/(const Complex& other)
{
	Complex* tmp = new Complex;
	Complex* tmp1 = new Complex;
	tmp->set_real((this->get_real() * other.get_real()) + (this->get_imaginary() * other.get_imaginary()));
	tmp1->set_real((other.get_real() * other.get_real()) + (other.get_imaginary() * other.get_imaginary()));
	tmp->set_real(tmp->get_real() / tmp1->get_real());
	tmp->set_imaginary(this->get_imaginary() * other.get_real() - this->get_real() * other.get_imaginary());
	tmp1->set_imaginary((other.get_real() * other.get_real()) + (other.get_imaginary() * other.get_imaginary()));
	tmp->set_imaginary(tmp->get_imaginary() / tmp1->get_imaginary());
	return *tmp;
}

Complex::~Complex()
{
	cout << "(-0-)" << endl;
}




ostream& operator<<(ostream& print, const Complex& p)
{
	
	if (p.get_imaginary() == 0)
	{
		print << p.get_real();
	}
	if (p.get_imaginary() > 0)
	{
		print << p.get_real() << "+" << p.get_imaginary() << "i";
		return print;
	}
	if (p.get_imaginary() < 0)
	{
		print << p.get_real() << " " << p.get_imaginary() << "i";
		return print;
	}
}

Complex operator*(double d, Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() * d);
	tmp->set_imaginary(other.get_imaginary()*d);
	return *tmp;
}

Complex operator*(Complex& other, double d)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() * d);
	tmp->set_imaginary(other.get_imaginary()*d);
	return *tmp;
}

Complex operator/(Complex& other, double d)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() / d);
	tmp->set_imaginary(other.get_imaginary() / d);
	return *tmp;
}

Complex operator/(double d, Complex& other)
{
	Complex* tmp = new Complex;
	tmp->set_real(other.get_real() / d);
	tmp->set_imaginary(other.get_imaginary() / d);
	return *tmp;
}

