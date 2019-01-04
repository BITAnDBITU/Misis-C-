#pragma once
#ifndef MATRIX
#define MATRIX

class Matrix {
public:
	Matrix();

	Matrix(const Matrix &rhs);

	Matrix(const int sizeStr1_, const int sizeStol1_);

	~Matrix();

	int &at(const int i, const int j);

	int getSizeStr();

	int getSizeStol();

	Matrix &operator=(const Matrix &rhs);

	std::ostream &writeTo(std::ostream &ostrm) const;

private:
	int sizeStr_{ 0 };
	int sizeStol_{ 0 };
	int **data_{ nullptr };
};

std::ostream &operator<<(std::ostream &ostrm, const Matrix &rhs);

#endif;
