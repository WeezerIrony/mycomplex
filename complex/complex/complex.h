#pragma once
#include <iostream>

double const pi = atan(1) * 4;

class complex
{
public:
	complex(double a = 0.0, double b = 0.0);
	double Re() const;
	double Im() const;
    friend bool operator==(const complex& lhs, const complex& rhs);
    friend bool operator==(const complex& lhs, const double rhs);
    friend bool equals(complex& lhs, const complex& rhs, const double err);
    friend bool equals(complex& lhs, double rhs, const double err);
    friend std::ostream& operator<<(std::ostream& out, const complex& cpx);
    friend std::istream& operator>>(std::istream& in, complex& cpx);
    friend complex operator+(complex& lhs, const complex& rhs);
    friend complex operator-(complex& lhs, const complex& rhs);
    friend complex operator*(complex& lhs, const complex& rhs);
    friend complex operator/(complex& lhs, const complex& rhs);
    complex& operator=(const complex& cplx);
    complex& operator+=(const complex& cplx);
    complex& operator-=(const complex& cplx);
    complex& operator*=(const complex& cplx);
    complex& operator/=(const complex& cplx);
    friend complex operator+(complex& lhs, const double rhs);
    friend complex operator-(complex& lhs, const double rhs);
    friend complex operator*(complex& lhs, const double rhs);
    friend complex operator/(complex& lhs, const double rhs);
    complex& operator=(double x);
    complex& operator+=(double x);
    complex& operator-=(double x);
    complex& operator*=(double x);
    complex& operator/=(double x);
    friend complex conj(const complex& cplx);
    friend complex polar(const double r, const double phi);
    friend double abs(const complex& cplx);
    friend double norm(const complex& cplx);
    friend double arg(const complex& cplx, const int k=0) {
        if (cplx == 0) throw std::runtime_error("Division by zero");
        if (cplx.re > 0) {
            if (cplx.im >= 0) return atan(cplx.im / cplx.re) + (2 * pi * k);
            else return (2 * pi) - atan(abs(cplx.im / cplx.re)) + (2 * pi * k);
        }
        if (cplx.re == 0) {
            if (cplx.im > 0) return (pi / 2) + (2 * pi * k);
            else return (3 * pi / 2) + (2 * pi * k);
        }
        if (cplx.re < 0) {
            if (cplx.im >= 0) return pi - atan(abs(cplx.im / cplx.re)) + (2 * pi * k);
            else return pi + atan(abs(cplx.im / cplx.re)) + (2 * pi * k);
        }
    }
    friend complex nrt(const complex& cplx, const int n, int k = 0) {
        if (n == 0) throw std::runtime_error("Does not exist");
        if (k > n-1) k = n-k;
        complex result;
        result.re = pow(abs(cplx), 1.0 / n) * cos((arg(cplx) / n) + ((2 * pi * k) / n));
        result.im = pow(abs(cplx), 1.0 / n) * sin((arg(cplx) / n) + ((2 * pi * k) / n));
        return result;
    }
    friend complex sqrt(const complex& cplx, int k = 0) {
        if (k > 1) k = 2 - k;
        complex result;
        result.re = sqrt(abs(cplx)) * cos((arg(cplx) / 2) + (pi * k));
        result.im = sqrt(abs(cplx)) * sin((arg(cplx) / 2) + (pi * k));
        return result;
    }
    friend complex cround(complex z, int n);
private:
	double re;
	double im;
};


