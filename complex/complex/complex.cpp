#include "complex.h"
#include <iomanip>
#include <iostream>

complex const i(0, 1);

complex::complex(double a, double b) : re(a), im(b) {}

double complex::Re() const {
	return re;
}

double complex::Im() const {
	return im;
}

bool operator==(const complex& lhs, const complex& rhs) {
	return (lhs.re == rhs.re && lhs.im == rhs.im);
}

bool operator==(const complex& lhs, double rhs) {
	return (lhs.re == rhs && lhs.im == 0);
}

bool equals(complex& lhs, const complex& rhs, const double err) {
	return (abs(err) >= abs(lhs - rhs));
}

bool equals(complex& lhs, double rhs, const double err) {
	return (abs(err) >= abs(lhs - rhs));
}

std::ostream& operator<<(std::ostream& out, const complex& z) {
	complex ot = cround(z, 4);
	if (ot.re == -0) ot.re = 0;
	if (ot.im == -0) ot.im = 0;
	out << "(" << std::setprecision(5) << ot.re << ";" << std::setprecision(5) << ot.im << ")";
	return out;
}

std::istream& operator>>(std::istream& in, complex& z) {
	in >> z.re >> z.im;
	return in;
}

complex operator+(const complex& lhs, const complex& rhs) {
	complex res;
	res.re = lhs.re + rhs.re;
	res.im = lhs.im + rhs.im;
	return res;
}

complex operator-(const complex& lhs, const complex& rhs) {
	complex res;
	res.re = lhs.re - rhs.re;
	res.im = lhs.im - rhs.im;
	return res;
}

complex operator*(const complex& lhs, const complex& rhs) {
	complex res;
	res.re = (lhs.re * rhs.re) - (lhs.im * rhs.im);
	res.im = (lhs.re * rhs.im) + (lhs.im * rhs.re);
	return res;
}

complex operator/(const complex& lhs, const complex& rhs) {
	if (rhs==0) throw std::runtime_error("Undefined (division by zero)");
	complex res;
	res.re = ((rhs.re * lhs.re) + (rhs.im * lhs.im)) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	res.im = ((rhs.re * lhs.im) - (lhs.re * rhs.im)) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	return res;
}

complex& complex::operator=(const complex& rhs) {
	re = rhs.re;
	im = rhs.im;
	return *this;
}

complex& complex::operator+=(const complex& rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

complex& complex::operator-=(const complex& rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

complex& complex::operator*=(const complex& rhs) {
	auto re0 = re;
	auto im0 = im;
	re = (re0 * rhs.re) - (im0 * rhs.im);
	im = (re0 * rhs.im) + (im0 * rhs.re);
	return *this;
}

complex& complex::operator/=(const complex& rhs) {
	if (rhs==0) throw std::runtime_error("Undefined (division by zero)");
	auto re0 = re;
	auto im0 = im;
	re = ((rhs.re * re0) + (rhs.im * im0)) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	im = ((rhs.re * im0) - (re0 * rhs.im)) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	return *this;
}

complex operator+(complex& lhs, const double rhs) {
	complex res;
	complex op(rhs);
	res = lhs + op;
	return res;
}

complex operator-(complex& lhs, const double rhs) {
	complex res;
	complex op(rhs);
	res = lhs - op;
	return res;
}

complex operator*(complex& lhs, const double rhs) {
	complex res;
	complex op(rhs);
	res = lhs * op;
	return res;
}

complex operator/(complex& lhs, const double rhs) {
	if (rhs == 0) throw std::runtime_error("Undefined (division by zero)");
	complex op(rhs);
	complex res;
	res = lhs / op;
	return res;
}

complex& complex::operator=(const double rhs) {
	re = rhs;
	im = 0;
	return *this;
}

complex& complex::operator+=(const double rhs) {
	complex op(rhs);
	*this += op;
	return *this;
}

complex& complex::operator-=(const double rhs) {
	complex op(rhs);
	*this -= op;
	return *this;
}

complex& complex::operator*=(const double rhs) {
	complex op(rhs);
	*this *= op;
	return *this;
}

complex& complex::operator/=(const double rhs) {
	if (rhs == 0) throw std::runtime_error("Undefined (division by zero)");
	complex z(rhs);
	*this /= z;
	return *this;
}

complex conj(const complex& z) {
	complex res(z.re, (z.im * -1));
	return res;
}

complex polar(const double r, const double phi) {
	complex res((r * cos(phi)), (r * sin(phi)));
	return res;
}

double abs(const complex& z) {
	return sqrt(pow(z.re, 2)+pow(z.im, 2));
}

double norm(const complex& z) {
	return pow(z.re, 2) + pow(z.im, 2);
}

double arg(const complex& z) {
	if (z == 0) throw std::runtime_error("Undefined (division by zero)");
	if (z.re > 0) {
		if (z.im >= 0) return atan(z.im / z.re);
		else return (2 * pi) - atan(abs(z.im / z.re));
	}
	if (z.re == 0) {
		if (z.im > 0) return (pi / 2);
		else return (3 * pi / 2);
	}
	if (z.re < 0) {
		if (z.im >= 0) return pi - atan(abs(z.im / z.re));
		else return pi + atan(abs(z.im / z.re));
	}
}

double Arg(const complex& z, int k) {
	return arg(z) + 2 * pi * k;
}

complex sin(const complex& z) {
	return ((exp(i * z) - exp(-1 * i * z)) / (2 * i));
}

complex cos(const complex& z) {
	return ((exp(i * z) + exp(-1 * i * z)) / 2);
}

complex tg(const complex& z)
{
	if (cos(z) == 0) throw std::runtime_error("Undefined (division by zero)");
	return (sin(z)/cos(z));
}

complex ctg(const complex& z)
{
	if (sin(z) == 0) throw std::runtime_error("Undefined (division by zero)");
	return (cos(z) / sin(z));
}

complex exp(const complex& z) {
	complex res;
	res.re = exp(z.re) * cos(z.im);
	res.im = exp(z.re) * sin(z.im);
	return res;
}

complex Ln(const complex& z, const int k) {
	complex res;
	res.re = log(abs(z));
	res.im = Arg(z, k);
	return res;
}

complex ln(const complex& z) {
	return Ln(z, 0);
}

complex Lg(const complex& z, const int k) {
	complex res;
	res.re = log10(abs(z));
	res.im = Arg(z, k);
	return res;
}

complex lg(const complex& z) {
	return Lg(z, 0);
}

complex pow(const complex& lhs, const int rhs) {
	complex res;
	res.re = pow(arg(lhs), rhs) * cos(rhs * arg(lhs));
	res.im = pow(arg(lhs), rhs) * sin(rhs * arg(lhs));
	return res;
}

complex Pow(const complex& lhs, const complex& rhs, int k) {
	return exp(rhs * Ln(lhs, k));
}

complex pow(const complex& lhs, const complex& rhs) {
	return Pow(lhs, rhs, 0);
}

complex Pow(double lhs, const complex& rhs, int k) {
	return exp(rhs * Ln(lhs, k));
	return 0;
}

complex pow(double lhs, const complex& rhs) {
	return Pow(lhs, rhs, 0);
}

complex cround(const complex& z, const int n) {
	complex res;
	res.re = (round(z.re * pow(10, n))) * pow(10, -n);
	res.im = (round(z.im * pow(10, n))) * pow(10, -n);
	return res;
}

