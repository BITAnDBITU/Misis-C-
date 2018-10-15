#include <iostream>
#include"matrix.h"

using namespace std;
std::ostream& operator<<(std::ostream& ostrm, const Matrix& rhs) {
	return rhs.writeTo(ostrm);
}

void test() {
	Matrix mat1();
	Matrix mat2(4, 5);
	for (int i(0); i < mat2.getSizeStol(); i++) {
		for (int j(0); i < mat2.getSizeStr(); i++)
		{
			mat2[i][j] = 1;
		}
	}
	Matrix mat3(mat2);
	mat3[0][3] = 4;
	mat3[1][3] = 4;
	mat3[2][3] = 4;
	mat3[3][3] = 4;
	cout << mat1 << endl;
	cout << mat2 << endl;
	cout << mat3 << endl;
}

int main() {
	test();
}