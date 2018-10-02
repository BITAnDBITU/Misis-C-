#include <iostream>
#include <sstream>
#include "rational.h"

using namespace std;

Rational::Rational(const int numerator)
{
	setNumerator(numerator);
	setDenominator(1);
}
Rational::Rational(const int numerator, const int denominator)
{
	setNumerator(numerator);
	setDenominator(denominator);
}

int Rational::getNumerator() {
	return num;
}
void Rational::setNumerator(int numerator) {
	num = numerator;
}

int Rational::getDenominator() {
	return den;
}
void Rational::setDenominator(int denominator) {
	if (denominator != 0) {
		den = denominator;
	}
	else
	{
		throw std::exception("Divide by zero exception");
	}
}
Rational& Rational::operator+=(const int rhs) {
	return operator+=(Rational(rhs));
}
Rational& Rational::operator-=(const int rhs) {
	return operator-=(Rational(rhs));
}
Rational& Rational::operator*=(const int rhs) {
	return operator*=(Rational(rhs));
}
Rational& Rational::operator/=(const int rhs) {
	return operator/=(Rational(rhs));
}

Rational& Rational::operator+=(const Rational& rhs) {
	num = num * rhs.den + rhs.num*den;
	den *= rhs.den;
	normalForm();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
	num = num * rhs.den - rhs.num*den;
	den *= rhs.den;
	normalForm();
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
	num *= rhs.num;
	den *= rhs.den;
	normalForm();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	num *= rhs.den;
	den *= rhs.num;
	normalForm();
	return *this;
}
int gcd(int a, int b) {
	while (a != b) {
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		b = b - a;
	}
	return a;
}
void Rational::normalForm() {
	if (num != 0 && den != 0) {
		int nod = gcd(num, den);
		num /= nod;
		den /= nod;
	}
	if (den < 0) {
		num *= -1;
		den *= -1;
	}
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const {
	ostrm << leftBrace << num << separator << den << rightBrace;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
	char leftBrace(0);
	int numerator(0);
	char comma(0);
	int denominator(0);
	char rightBrace(0);
	istrm >> leftBrace >> numerator >> comma >> denominator >> rightBrace;
	if (istrm.good()) {
		if ((Rational::leftBrace == leftBrace) && (Rational::separator == comma) &&
			(Rational::rightBrace == rightBrace)) {
			num = numerator;
			den = denominator;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}