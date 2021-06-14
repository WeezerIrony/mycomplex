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
    friend std::ostream& operator<<(std::ostream& out, const complex& z);
    friend std::istream& operator>>(std::istream& in, complex& z);
    friend complex operator+(const complex& lhs, const complex& rhs);
    friend complex operator-(const complex& lhs, const complex& rhs);
    friend complex operator*(const complex& lhs, const complex& rhs);
    friend complex operator/(const complex& lhs, const complex& rhs);
    complex& operator=(const complex& rhs);
    complex& operator+=(const complex& rhs);
    complex& operator-=(const complex& rhs);
    complex& operator*=(const complex& rhs);
    complex& operator/=(const complex& rhs);
    friend complex operator+(complex& lhs, const double rhs);
    friend complex operator-(complex& lhs, const double rhs);
    friend complex operator*(complex& lhs, const double rhs);
    friend complex operator/(complex& lhs, const double rhs);
    complex& operator=(double rhs);
    complex& operator+=(double rhs);
    complex& operator-=(double rhs);
    complex& operator*=(double rhs);
    complex& operator/=(double rhs);
    friend complex conj(const complex& z);
    friend double abs(const complex& z);
    friend double norm(const complex& z);
    friend double arg(const complex& z);
    friend double Arg(const complex& z, int k);
    friend complex root(const complex& z, const int n, int k = 0) {
        if (n == 0) throw std::runtime_error("Does not exist");
        if (k > n - 1) k = n - k;
        complex result;
        result.re = pow(abs(z), 1.0 / n) * cos((arg(z) / n) + ((2 * pi * k) / n));
        result.im = pow(abs(z), 1.0 / n) * sin((arg(z) / n) + ((2 * pi * k) / n));
        return result;
    }
    friend complex sqrt(const complex& z, int k = 0) {
        if (k > 1) k = 2 - k;
        complex result;
        result.re = sqrt(abs(z)) * cos((arg(z) / 2) + (pi * k));
        result.im = sqrt(abs(z)) * sin((arg(z) / 2) + (pi * k));
        return result;
    }
    friend complex sin(const complex& z);
    friend complex cos(const complex& z);
    friend complex tg(const complex& z);
    friend complex ctg(const complex& z);
    friend complex exp(const complex& z);
    friend complex Ln(const complex& z, const int k);
    friend complex ln(const complex& z);
    friend complex Lg(const complex& z, const int k);
    friend complex lg(const complex& z);
    friend complex pow(const complex& lhs, const int rhs);
    friend complex Pow(const complex& lhs, const complex& rhs, int k);
    friend complex pow(const complex& lhs, const complex& rhs);
    friend complex Pow(double lhs, const complex& rhs, int k);
    friend complex pow(double lhs, const complex& rhs);
    friend complex cround(const complex& z, const int n);
private:
	double re;
	double im;
};

complex polar(const double r, const double phi);
