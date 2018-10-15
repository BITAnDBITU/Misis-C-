
#include <iostream>
#include"matrix.h"

using namespace std;

Matrix::Matrix() {
	sizeStr_ = 0;
	sizeStol_ = 0;
	data_ = new int*[sizeStol_];
	for (int i(0); i < sizeStol_; i++)
	{
		data_[i] = new int[sizeStr_];
	}

}

Matrix::Matrix(const int sizeStr1_, const int sizeStol1_) {
	if (sizeStr1_ < 0 || sizeStol1_ < 0)
		throw std::exception("Size should not be negative");
	data_ = new int*[sizeStol_];
	for (int i(0); i < sizeStol_; i++)
	{
		data_[i] = new int[sizeStr_];
	}
}
Matrix::Matrix(const Matrix& rhs) {
	sizeStol_ = rhs.sizeStol_;
	sizeStr_ = rhs.sizeStr_;
	data_ = new int*[sizeStol_];
	for (int i(0); i < sizeStol_; i++)
	{
		data_[i] = new int[sizeStr_];
	}
	for (int i(0); i < sizeStol_; i++)
	{
		for (int j(0); i < sizeStr_; i++)
		{
			data_[i][j] = rhs.data_[i][j];
		}
	}
}
Matrix::~Matrix() {
	for (int i(0); i < sizeStol_; i++)
	{
		delete[] data_[i];
	}
	delete[] data_;
}
int*& Matrix::operator[](const int i) const {
	return data_[i];
}
int Matrix::getSizeStol() {
	return sizeStol_;
}
int Matrix::getSizeStr() {
	return sizeStr_;
}
std::ostream& Matrix::writeTo(std::ostream& ostrm) const {
	for (int i(0); i < sizeStol_; i++)
	{
		for (int j(0); i < sizeStr_; i++)
		{
			ostrm << this[i][j] << " ";
		}
		ostrm << endl;
	}
	return ostrm;
}

