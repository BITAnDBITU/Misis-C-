#include <iostream>
#include <dynamicalarray/dynamicalarray.h>

using namespace std;

void test() {
    DynamicalArray ar1(5);
    DynamicalArray ar2(ar1);
    for (int i = 0; i < ar1.getSize(); i++) {
        ar1[i] = i;
        cout << ar1[i] << " ";
    }
    cout << endl;
    DynamicalArray ar3(ar1);
    for (int i = 0; i < ar3.getSize(); i++) {
        cout << ar3[i] << " ";
    }
    cout << endl;
    ar2[4] = 10;
    ar2.setSize(6);
    for (int i = 0; i < ar2.getSize(); i++) {
        cout << ar2[i] << " ";
    }
    cout << endl;
    try {
        ar3.setSize(-1);
    }
    catch (const std::exception &) {
        cout << "Negative size" << endl;
    }

    try {
        cout << ar3[10] << endl;
    }
    catch (const std::exception &) {
        cout << "Index out range" << endl;
    }

    try {
        cout << ar3[-1] << endl;
    }
    catch (const std::exception &) {
        cout << "Index out range" << endl;
    }


}

std::ostream &operator<<(std::ostream &ostrm, const DynamicalArray &rhs) {
    return rhs.writeTo(ostrm);
}

int main() {
    test();
    return 0;
}