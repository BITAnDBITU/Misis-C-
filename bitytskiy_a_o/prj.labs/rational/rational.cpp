// Copyright 2018 by Polevoy Dmitry under Free Public License 1.0.0

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
  int num{0};
  int den{1};

  static const char leftBrace{'{'};
  static const char separator{'/'};
  static const char rightBrace{'}'};
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs)
{
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	Rational sub(lhs);
	sub -= rhs;
	return sub;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	Rational mul(lhs);
	mul *= rhs;
	return mul;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	Rational div(lhs);
	div /= rhs;
	return div;
}
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
  using namespace std;
  istringstream istrm(str);
  Rational z;
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str << " -> " << z << endl;
  } else {
    cout << "Read error : " << str << " -> " << z << endl;
  }
  return istrm.good();
}
bool testSum() {
	Rational n1(15, 2);
	Rational n2(2, 97);
	Rational answ(1459, 194);
	Rational rez = n1 + n2;
	return rez == answ;
}
bool testSub() {
	Rational n1(15, 2);
	Rational n2(2, 5);
	Rational answ(71, 10);
	Rational rez = n1 - n2;
	return rez == answ;
}
bool testMul() {
	Rational n1(15, 2);
	Rational n2(2, 10);
	Rational answ(3, 2);
	n1 *= n2;
	return n1 == answ;
}
bool testDiv() {
	Rational n1(7, 4);
	Rational n2(2, 3);
	Rational answ(21, 8);
	n1 /= n2;
	return n1 == answ;
}
int main() {
  using namespace std;

  cout << "testSum: " << (testSum() ? "success" : "you have mistakes") << endl;
  cout << "testSub: " << (testSub() ? "success" : "you have mistakes") << endl;
  cout << "testMul: " << (testMul() ? "success" : "you have mistakes") << endl;
  cout << "testDiv: " << (testDiv() ? "success" : "you have mistakes") << endl;
  
  return 0;
}

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
  ostrm << leftBrace << num  << separator << den << rightBrace;
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
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
