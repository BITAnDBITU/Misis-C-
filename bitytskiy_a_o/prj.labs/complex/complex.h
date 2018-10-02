#pragma once
#include <iostream>
#include <sstream>

struct Complex {
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs) const {
		return (re == rhs.re) && (im == rhs.im);
	}
	bool operator!=(const Complex& rhs) const { return !operator==(rhs); }

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs);

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs);

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};
};
