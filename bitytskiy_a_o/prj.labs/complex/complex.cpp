#include <iostream>
#include <sstream>
#include "complex.h"

Complex::Complex(const double real)
	: Complex(real, 0.0) {
}

Complex::Complex(const double real, const double imaginary)
	: re(real), im(imaginary) {
}

bool Complex::operator==(const Complex &rhs) const {
	if (this != &rhs) {
		return ((re * rhs.re >= 0) && (im * rhs.im >= 0) && (std::abs(std::abs(re) - std::abs(rhs.re)) < 0.000001)) &&
			(std::abs((std::abs(im) - std::abs(rhs.im)) < 0.000001));
	}
	return true;
}

bool Complex::operator!=(const Complex &rhs) const {
	return !operator==(rhs);
}

Complex &Complex::operator+=(const double rhs) {
	return operator+=(Complex(rhs));
}

Complex &Complex::operator-=(const double rhs) {
	return operator-=(Complex(rhs));
}

Complex &Complex::operator*=(const double rhs) {
	return operator*=(Complex(rhs));
}

Complex &Complex::operator/=(const double rhs) {
	return operator/=(Complex(rhs));
}

Complex &Complex::operator+=(const Complex &rhs) {
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex &Complex::operator-=(const Complex &rhs) {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator+(const Complex &lhs, const Complex &rhs) {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex &Complex::operator*=(const Complex &rhs) {
	int tempRe = re;
	re = (re * rhs.re) - (im * rhs.im);
	im = (tempRe * rhs.im) + (im * rhs.re);
	return *this;
}

Complex &Complex::operator/=(const Complex &rhs) {
	int tempRe = re;
	if (re == 0 && im == 0) {
		throw std::exception("Äåëåíèå íà 0!");
	}
	else {
		re = ((re * rhs.re) + (im * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
		im = ((im * rhs.re) - (tempRe * rhs.im)) / ((rhs.re * rhs.re) + (rhs.im * rhs.im));
	}
	return *this;
}

std::ostream &Complex::writeTo(std::ostream &ostrm) const {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream &Complex::readFrom(std::istream &istrm) {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) &&
			(Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}