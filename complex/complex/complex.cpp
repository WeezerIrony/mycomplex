#include "complex.h"

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

complex& operator+(complex& lhs, const complex& rhs) {
	lhs.re += rhs.re;
	lhs.im += rhs.im;
	return lhs;
}

complex& operator-(complex& lhs, const complex& rhs) {
	lhs.re -= rhs.re;
	lhs.im -= rhs.im;
	return lhs;
}

complex& operator*(complex& lhs, const complex& rhs) {
	lhs.re = lhs.re * rhs.re - lhs.im * rhs.im;
	lhs.im = lhs.re * rhs.im + lhs.im * rhs.re;
	return lhs;
}

complex& operator/(complex& lhs, const complex& rhs) {
	if (rhs==0) throw std::runtime_error("Division by zero");
	lhs.re = (rhs.re * lhs.re + rhs.im * lhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	lhs.im = (rhs.re * lhs.im - lhs.re * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	return lhs;
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
	re = re * cplx.re - im * cplx.im;
	im = re * cplx.im + im * cplx.re;
	return *this;
}

complex& complex::operator/=(const complex& cplx) {
	if (cplx.re == 0 && cplx.im == 0) throw std::runtime_error("Division by zero");
	re = (cplx.re * re + cplx.im * im) / (pow(cplx.re, 2) + pow(cplx.im, 2));
	im = (cplx.re * im - re * cplx.im) / (pow(cplx.re, 2) + pow(cplx.im, 2));
	return *this;
}

complex& operator+(complex& lhs, double rhs) {
	complex z(rhs);
	lhs += z;
	return lhs;
}

complex& operator-(complex& lhs, double rhs) {
	complex z(rhs);
	lhs -= z;
	return lhs;
}

complex& operator*(complex& lhs, double rhs) {
	complex z(rhs);
	lhs *= z;
	return lhs;
}

complex& operator/(complex& lhs, double rhs) {
	complex z(rhs);
	if (z==0) throw std::runtime_error("Division by zero");
	lhs /= z;
	return lhs;
}

complex& complex::operator=(double x) {
	re = x;
	im = 0;
	return *this;
}

complex& complex::operator+=(double x) {
	complex z(x);
	*this += z;
	return *this;
}

complex& complex::operator-=(double x) {
	complex z(x);
	*this -= z;
	return *this;
}

complex& complex::operator*=(double x) {
	complex z(x);
	*this *= z;
	return *this;
}

complex& complex::operator/=(double x) {
	complex z(x);
	*this /= z;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const complex& cpx) {
	out << "(" << cpx.Re() << "; " << cpx.Im() << ")" << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, complex& cpx) {
	in >> cpx.re >> cpx.im;
	return in;
}

complex conj(const complex& cplx) {
	complex z(cplx.re, (cplx.im * -1));
	return z;
}

double abs(const complex& cplx) {
	return sqrt(pow(cplx.re, 2)+pow(cplx.im, 2));
}

double norm(const complex& cplx) {
	return pow(cplx.re, 2) + pow(cplx.im, 2);
}


