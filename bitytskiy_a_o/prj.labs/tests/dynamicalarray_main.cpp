#include <iostream>
#include <dynamicalarray/dynamicalarray.h>

using namespace std;
void test() {
	DynamicalArray ar1(5);
	DynamicalArray ar2(ar1);
	for (int i = 0; i < ar1.getSize(); i++)
	{
		ar1[i] = i;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << ar1[i] << " ";
	}
	cout << endl;
	ar2[4] = 10;
	for (int i = 0; i < ar2.getSize(); i++)
	{
		cout << ar2[i] << " ";
	}
	cout << endl;

}
std::ostream& operator<<(std::ostream& ostrm, const DynamicalArray& rhs) {
	return rhs.writeTo(ostrm);
}
int main() {
	test();
	return 0;
}