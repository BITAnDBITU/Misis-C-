#include <iostream>
#include <sstream>
#include <rational/rational.h>

using namespace std;

Rational operator+(const Rational &lhs, const Rational &rhs);

Rational operator-(const Rational &lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const Rational &rhs);

Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational sum(lhs);
    sum += rhs;
    return sum;
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    Rational sub(lhs);
    sub -= rhs;
    return sub;
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational mul(lhs);
    mul *= rhs;
    return mul;
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    Rational div(lhs);
    div /= rhs;
    return div;
}

inline std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) {
    return rhs.writeTo(ostrm);
}

inline std::istream &operator>>(std::istream &istrm, Rational &rhs) {
    return rhs.readFrom(istrm);
}

bool testParse(const std::string &str) {
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

void testException() {
    Rational n1(15, -2);
    Rational n2(-15, 2);
    Rational n3(-15, -2);
    Rational n4(15, 2);
    cout << (n1 == n2) << endl;
    cout << (n3 == n4) << endl;
}

int main() {
    using namespace std;

    cout << "testSum: " << (testSum() ? "success" : "you have mistakes") << endl;
    cout << "testSub: " << (testSub() ? "success" : "you have mistakes") << endl;
    cout << "testMul: " << (testMul() ? "success" : "you have mistakes") << endl;
    cout << "testDiv: " << (testDiv() ? "success" : "you have mistakes") << endl;
    testException();

    return 0;
}