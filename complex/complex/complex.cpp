#include "complex.h"

complex::complex(double a, double b) : re(a), im(b) {}

double complex::Re() const {
	return re;
}

double complex::Im() const {
	return im;
}

bool complex::operator==(const complex& cplx) {
	return (re == cplx.re && im == cplx.im);
}

bool complex::operator==(double x) {
	return (re == x && im == 0);
}

complex& complex::operator+(const complex& cplx) {
	complex z((re + cplx.re), (im + cplx.im));
	return z;
}

complex& complex::operator-(const complex& cplx) {
	complex z((re - cplx.re), (im - cplx.im));
	return z;
}

complex& complex::operator*(const complex& cplx) {
	complex z((re * cplx.re - im * cplx.im), (re * cplx.im + im * cplx.re));
	return z;
}

complex& complex::operator/(const complex& cplx) {
	if (cplx.re == 0 && cplx.im == 0) throw std::runtime_error("Division by zero");
	complex z(((cplx.re * re + cplx.im * im) / (cplx.re * cplx.re + cplx.im * cplx.im)), ((cplx.re * im - re * cplx.im) / ((cplx.re) * (cplx.re) + (cplx.im) * (cplx.im))));
	return z;
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
	re = (cplx.re * re + cplx.im * im) / (cplx.re * cplx.re + cplx.im * cplx.im);
	im = (cplx.re * im - re * cplx.im) / (cplx.re * cplx.re + cplx.im * cplx.im);
	return *this;
}

complex& complex::operator+(double x) {
	complex z(x);
	complex result((re + z.re), (im + z.im));
	return result;
}

complex& complex::operator-(double x) {
	complex z(x);
	complex result((re - z.re), (im - z.im));
	return result;
}

complex& complex::operator*(double x) {
	complex z(x);
	complex result((re * z.re - im * z.im), (re * z.im + im * z.re));
	return result;
}

complex& complex::operator/(double x) {
	complex z(x);
	if (z.re == 0 && z.im == 0) throw std::runtime_error("Division by zero");
	complex result(((z.re * re + z.im * im) / (z.re * z.re + z.im * z.im)), ((z.re * im - re * z.im) / ((z.re) * (z.re) + (z.im) * (z.im))));
	return result;
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
