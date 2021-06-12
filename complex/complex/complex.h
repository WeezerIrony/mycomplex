#pragma once
#include <iostream>
class complex
{
public:
	complex(double a = 0.0, double b = 0.0);
	double Re() const;
	double Im() const;
    bool operator==(const complex& cplx);
    bool operator==(double x);
    friend std::ostream& operator<<(std::ostream& out, const complex& cpx) {
        out << "(" << cpx.Re() << "; " << cpx.Im() << ")" << std::endl;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, complex& cpx) {
        in >> cpx.re >> cpx.im;
        return in;
    }
    complex& operator+(const complex& cplx);
    complex& operator-(const complex& cplx);
    complex& operator*(const complex& cplx);
    complex& operator/(const complex& cplx);
    complex& operator=(const complex& cplx);
    complex& operator+=(const complex& cplx);
    complex& operator-=(const complex& cplx);
    complex& operator*=(const complex& cplx);
    complex& operator/=(const complex& cplx);
    complex& operator+(double x);
    complex& operator-(double x);
    complex& operator*(double x);
    complex& operator/(double x);
    complex& operator=(double x);
    complex& operator+=(double x);
    complex& operator-=(double x);
    complex& operator*=(double x);
    complex& operator/=(double x);
private:
	double re;
	double im;
};


