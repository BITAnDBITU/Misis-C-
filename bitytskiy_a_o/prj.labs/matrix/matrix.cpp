
#include <iostream>
#include"matrix.h"

using namespace std;

Matrix::Matrix() {
    sizeStr_ = 0;
    sizeStol_ = 0;
    data_ = new int *[sizeStr_];
    for (int i(0); i < sizeStr_; i++) {
        data_[i] = new int[sizeStol_];
    }

}

Matrix &Matrix::operator=(const Matrix &rhs) {
    sizeStol_ = rhs.sizeStol_;
    sizeStr_ = rhs.sizeStr_;
    for (int i(0); i < sizeStr_; i++) {
        data_[i] = new int[sizeStol_];
        for (int j(0); j < sizeStol_; j++) {
            data_[i][j] = rhs.data_[i][j];
        }
    }
    return *this;
}

Matrix::Matrix(const int sizeStr1_, const int sizeStol1_) {
    if (sizeStr1_ < 0 || sizeStol1_ < 0)
        throw std::exception("Size should not be negative");
    sizeStr_ = sizeStr1_;
    sizeStol_ = sizeStol1_;
    data_ = new int *[sizeStr_];
    for (int i(0); i < sizeStr_; i++) {
        data_[i] = new int[sizeStol_];
    }
}

Matrix::Matrix(const Matrix &rhs) {
    sizeStol_ = rhs.sizeStol_;
    sizeStr_ = rhs.sizeStr_;
    data_ = new int *[sizeStr_];
    for (int i(0); i < sizeStr_; i++) {
        data_[i] = new int[sizeStol_];
    }
    for (int i(0); i < sizeStr_; i++) {
        for (int j(0); j < sizeStol_; j++) {
            data_[i][j] = rhs.data_[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i(0); i < sizeStol_; i++) {
        delete[] data_[i];
    }
    delete[] data_;
}

int &Matrix::at(const int i, const int j) {
    if (i < 0 || j < 0 || i > sizeStr_ || j > sizeStol_) {
        throw std::exception("Size of row should not be negative");
    }
    return data_[i][j];
}

int Matrix::getSizeStol() {
    return sizeStol_;
}

int Matrix::getSizeStr() {
    return sizeStr_;
}

std::ostream &operator<<(std::ostream &ostrm, const Matrix &rhs) {
    return rhs.writeTo(ostrm);
}

std::ostream &Matrix::writeTo(std::ostream &ostrm) const {
    for (int i(0); i < sizeStr_; i++) {
        for (int j(0); j < sizeStol_; j++) {
            ostrm << data_[i][j] << " ";
        }
        ostrm << endl;
    }
    return ostrm;
}

