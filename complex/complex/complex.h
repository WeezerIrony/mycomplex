#pragma once
#include <iostream>
class complex
{
public:
	complex(double a = 0.0, double b = 0.0);
	double Re() const;
	double Im() const;
    friend bool operator==(const complex& lhs, const complex& rhs);
    friend bool operator==(const complex& lhs, double rhs);
    friend std::ostream& operator<<(std::ostream& out, const complex& cpx);
    friend std::istream& operator>>(std::istream& in, complex& cpx);
    friend complex& operator+(complex& lhs, const complex& rhs);
    friend complex& operator-(complex& lhs, const complex& rhs);
    friend complex& operator*(complex& lhs, const complex& rhs);
    friend complex& operator/(complex& lhs, const complex& rhs);
    complex& operator=(const complex& cplx);
    complex& operator+=(const complex& cplx);
    complex& operator-=(const complex& cplx);
    complex& operator*=(const complex& cplx);
    complex& operator/=(const complex& cplx);
    friend complex& operator+(complex& lhs, double rhs);
    friend complex& operator-(complex& lhs, double rhs);
    friend complex& operator*(complex& lhs, double rhs);
    friend complex& operator/(complex& lhs, double rhs);
    complex& operator=(double x);
    complex& operator+=(double x);
    complex& operator-=(double x);
    complex& operator*=(double x);
    complex& operator/=(double x);
    friend complex conj(const complex& cplx);
    friend double abs(const complex& cplx);
    friend double norm(const complex& cplx);
private:
	double re;
	double im;
};


