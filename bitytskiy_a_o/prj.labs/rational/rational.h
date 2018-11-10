#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <sstream>

class Rational {
public:
	Rational() = default;
	Rational(const int numerator);
	Rational(const int numerator, const int denominator);
	bool operator==(const Rational& rhs) const {
		return (num == rhs.num) && (den == rhs.den);
	}
	bool operator!=(const Rational& rhs) const
	{
		return !operator==(rhs);
	}
	Rational& operator+=(const Rational& rhs);
	Rational& operator+=(const int rhs);

	Rational& operator-=(const Rational& rhs);
	Rational& operator-=(const int rhs);

	Rational& operator*=(const Rational& rhs);
	Rational& operator*=(const int rhs);

	Rational& operator/=(const Rational& rhs);
	Rational& operator/=(const int rhs);

	int getNumerator();
	void setNumerator(int numerator);

	int getDenominator();
	void setDenominator(int numerator);

	void normalForm();

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
private:
	int num{ 0 };
	int den{ 1 };

	static const char leftBrace{ '{' };
	static const char separator{ '/' };
	static const char rightBrace{ '}' };
};
#endif