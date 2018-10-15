#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
class Matrix {
public:
	Matrix();
	Matrix(const Matrix& rhs);
	Matrix(const int sizeStr1_, const int sizeStol1_);
	~Matrix();
	int*& operator[](const int ind) const;
	int getSizeStr();
	int getSizeStol();
	std::ostream& writeTo(std::ostream& ostrm) const;
private:
	int sizeStr_{ 0 };
	int sizeStol_{ 0 };
	int** data_{ nullptr };
};
#endif 
