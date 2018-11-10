#include <iostream>
#include"matrix.h"

using namespace std;


void test() {
	Matrix mat1;
	Matrix mat2(4,4);
	for (int i (0); i < mat2.getSizeStol(); i++)
	{
		for(int j (0); j < mat2.getSizeStr(); j++)
		{
			mat2.at(i,j) = 1;
		}
	}
	Matrix mat3(mat2);
	
	cout << mat2 <<  endl;
	cout << mat3 << endl;
}
void testException() {
	
	try
	{
		Matrix mat(-1, -1);
		cout << " not successful" << endl;
	}
	catch (const std::exception&)
	{
		cout << "successful" << endl;
	}
	try
	{
		Matrix mat(-1, 1);
		cout << " not successful" << endl;
	}
	catch (const std::exception&)
	{
		cout << "successful" << endl;
	}
	try
	{
		Matrix mat(1, -1);
		cout << " not successful" << endl;
	}
	catch (const std::exception&)
	{
		cout << "successful" << endl;
	}
	try
	{
		Matrix mat(1, 1);
		cout << "successful" << endl;
	}
	catch (const std::exception&)
	{
		cout << " not successful" << endl;
	}
}

int main() {
	test();
	testException();
	return 0;
}