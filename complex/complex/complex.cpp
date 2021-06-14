#include "complex.h"
#include <iomanip>
#include <iostream>

complex::complex(double a, double b) : re(a), im(b) {}

double complex::Re() const {
	return re;
}

double complex::Im() const {
	return im;
}

bool operator==(const complex& lhs, const complex& rhs)
{
	return (lhs.re == rhs.re && lhs.im == rhs.im);
}

bool operator==(const complex& lhs, double rhs)
{
	return (lhs.re == rhs && lhs.im == 0);
}

bool equals(complex& lhs, const complex& rhs, const double err)
{
	return (abs(err) >= abs(lhs - rhs));
}

bool equals(complex& lhs, double rhs, const double err)
{
	return (abs(err) >= abs(lhs - rhs));
}

std::ostream& operator<<(std::ostream& out, const complex& cpx) {
	complex ot = cround(cpx, 4);
	out << "(" << std::setprecision(5) << ot.re << "; " << std::setprecision(5) << ot.im << ")" << std::endl;
	return out;
}

complex operator+(complex& lhs, const complex& rhs) {
	complex res;
	res.re = lhs.re + rhs.re;
	res.im = lhs.im + rhs.im;
	return res;
}

complex operator-(complex& lhs, const complex& rhs) {
	complex res;
	res.re = lhs.re - rhs.re;
	res.im = lhs.im - rhs.im;
	return res;
}

complex operator*(complex& lhs, const complex& rhs) {
	complex res;
	res.re = (lhs.re * rhs.re) - (lhs.im * rhs.im);
	res.im = (lhs.re * rhs.im) + (lhs.im * rhs.re);
	return res;
}

complex operator/(complex& lhs, const complex& rhs) {
	if (rhs==0) throw std::runtime_error("Division by zero");
	complex res;
	res.re = ((rhs.re * lhs.re) + (rhs.im * lhs.im)) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	res.im = ((rhs.re * lhs.im) - (lhs.re * rhs.im)) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	return res;
}

complex& complex::operator=(const complex& cplx) {
	re = cplx.re;
	im = cplx.im;
	return *this;
}

complex& complex::operator+=(const complex& cplx) {
	re += cplx.re;
	im += cplx.im;
	return *this;
}

complex& complex::operator-=(const complex& cplx) {
	re -= cplx.re;
	im -= cplx.im;
	return *this;
}

complex& complex::operator*=(const complex& cplx) {
	re = (re * cplx.re) - (im * cplx.im);
	im = (re * cplx.im) + (im * cplx.re);
	return *this;
}

complex& complex::operator/=(const complex& cplx) {
	if (cplx.re == 0 && cplx.im == 0) throw std::runtime_error("Division by zero");
	re = ((cplx.re * re) + (cplx.im * im)) / (pow(cplx.re, 2) + pow(cplx.im, 2));
	im = ((cplx.re * im) - (re * cplx.im)) / (pow(cplx.re, 2) + pow(cplx.im, 2));
	return *this;
}

complex operator+(complex& lhs, const double rhs) {
	complex res;
	complex z(rhs);
	res = lhs + z;
	return res;
}

complex operator-(complex& lhs, const double rhs) {
	complex res;
	complex z(rhs);
	res = lhs - z;
	return res;
}

complex operator*(complex& lhs, const double rhs) {
	complex res;
	complex z(rhs);
	res = lhs * z;
	return res;
}

complex operator/(complex& lhs, const double rhs) {
	complex z(rhs);
	if (z==0) throw std::runtime_error("Division by zero");
	complex res;
	res = lhs / z;
	return res;
}

complex& complex::operator=(const double x) {
	re = x;
	im = 0;
	return *this;
}

complex& complex::operator+=(const double x) {
	complex z(x);
	*this += z;
	return *this;
}

complex& complex::operator-=(const double x) {
	complex z(x);
	*this -= z;
	return *this;
}

complex& complex::operator*=(const double x) {
	complex z(x);
	*this *= z;
	return *this;
}

complex& complex::operator/=(const double x) {
	complex z(x);
	*this /= z;
	return *this;
}

std::istream& operator>>(std::istream& in, complex& cpx) {
	in >> cpx.re >> cpx.im;
	return in;
}

complex conj(const complex& cplx) {
	complex res(cplx.re, (cplx.im * -1));
	return res;
}

complex polar(const double r, const double phi) {
	complex res;
	res.re = r*cos(phi);
	res.im = r*sin(phi);
	return res;
}

double abs(const complex& cplx) {
	return sqrt(pow(cplx.re, 2)+pow(cplx.im, 2));
}

double norm(const complex& cplx) {
	return pow(cplx.re, 2) + pow(cplx.im, 2);
}

complex cround(complex z, int n)
{
	z.re = (round(z.re * pow(10, n))) * pow(10, -n);
	z.im = (round(z.im * pow(10, n))) * pow(10, -n);
	return z;
}

