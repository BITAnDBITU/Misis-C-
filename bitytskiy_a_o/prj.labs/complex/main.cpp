#include <iostream>
#include <sstream>
#include "complex.h"

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
	return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()) {
		cout << "Read success: " << str << " -> " << z << endl;
	}
	else {
		cout << "Read error : " << str << " -> " << z << endl;
	}
	return istrm.good();
}
bool testSum() {
	Complex answ(6.0, 6.0);
	Complex n1(2.0, 3.0);
	Complex n2(4.0, 3.0);
	Complex result = n1 + n2;
	return answ == result;
}
bool testSub() {
	Complex answ(2.0, 1.0);
	Complex n1(6.0, 4.0);
	Complex n2(4.0, 3.0);
	Complex result = n1 - n2;
	return answ == result;
}
bool testMul() {
	Complex answer(-1, 47);
	Complex number1(5, 3);
	Complex number2(4, 7);
	number1 *= number2;
	return number1 == answer;
}
bool testDiv() {
	Complex answer(-1.5, -0.5);
	Complex number1(-2, 1);
	Complex number2(1, -1);
	number1 /= number2;

	return number1 == answer;
}
int main() {
	using namespace std;

	cout << "testSum: " << (testSum() ? "success" : "you have mistakes") << endl;
	cout << "testSub: " << (testSub() ? "success" : "you have mistakes") << endl;
	cout << "testMul: " << (testMul() ? "success" : "you have mistakes") << endl;
	cout << "testDiv: " << (testDiv() ? "success" : "you have mistakes") << endl;
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	return 0;
}