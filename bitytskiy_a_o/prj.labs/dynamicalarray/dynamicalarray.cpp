#include <iostream>
#include "dynamicalarray.h"

using namespace std;


DynamicalArray::DynamicalArray() {
    size_ = 0;
    data_ = new int[size_];
}

DynamicalArray::DynamicalArray(const int size) {
    if (size < 0)
        throw std::exception("Size should not be negative");
    size_ = size;
    data_ = new int[size_];
    for (int i(0); i < size_; i++) {
        data_[i] = 0;
    }
}

DynamicalArray &DynamicalArray::operator=(const DynamicalArray &rhs) {
    if (this != &rhs) {
        if (size_ < rhs.size_) {
            int *newData(new int[rhs.size_]);
            delete[] data_;
            data_ = newData;
        }
        std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
        size_ = rhs.size_;
    }
    return *this;
}

DynamicalArray::DynamicalArray(const DynamicalArray &obj) {
    size_ = obj.size_;
    data_ = new int(size_);
    for (int i(0); i < size_; i++) {
        data_[i] = obj.data_[i];
    }
}

bool DynamicalArray::operator==(const DynamicalArray &obj) const {
    if (size_ == obj.size_) {
        for (int i = 0; i < size_; i++) {
            if (data_[i] != obj.data_[i]) {
                return false;
            }
        }
    }
}

bool DynamicalArray::operator!=(const DynamicalArray &obj) const {
    return !operator==(obj);
}

int DynamicalArray::getSize() {
    return size_;
}

void DynamicalArray::setSize(int size) {
    if (size < 0) {
        throw std::exception("Negative size!");
    } else {

        int *newData = new int[size];
        if (size <= size_) {
            for (int i(0); i < size; i++) {
                newData[i] = data_[i];
            }
        } else {
            for (int i(0); i < size_; i++) {
                newData[i] = data_[i];
            }
            for (int i(size_); i < size; i++) {
                newData[i] = 0;
            }
        }
        data_ = newData;
        size_ = size;

    }
}

int &DynamicalArray::operator[](const int i) const {
    if (i < 0 || i >= size_)
        throw std::exception("Index out range");
    else
        return data_[i];
}

std::ostream &DynamicalArray::writeTo(std::ostream &ostrm) const {
    for (int i(0); i < size_; i++) {
        ostrm << data_[i] << " ";
    }
    return ostrm;
}

DynamicalArray::~DynamicalArray() {
    delete[]data_;
}