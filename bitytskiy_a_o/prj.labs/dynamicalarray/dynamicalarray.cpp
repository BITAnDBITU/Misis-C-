#include <iostream>
#include "dynamicalarray.h"

using namespace std;


DynamicalArray::DynamicalArray()
{
	size_ = 0;
	data_ = new int[size_];
}

DynamicalArray::DynamicalArray(const int size) {
	if (size < 0)
		throw std::exception("Size should not be negative");
	size_ = size;
	data_ = new int[size_];
	for (int i (0); i < size_; i++)
	{
		data_[i] = 0;
	}
}

DynamicalArray& DynamicalArray::operator=( const DynamicalArray& rhs) {
	return *this;
}
DynamicalArray::DynamicalArray(const DynamicalArray& obj) {
	size_ = obj.size_;
	data_ = new int(size_);
	for (int i (0); i < size_; i++)
	{
		data_[i] = obj.data_[i];
	}
}

int DynamicalArray::getSize() {
	return size_;
}
void DynamicalArray::setSize(int size) {
	int* newData = new int[size];

	for (int i(0); i < size_; i++)
		newData[i] = data_[i];

	data_ = newData;
	size_ = size;
}
int* DynamicalArray::getData() {
	return data_;
}
void DynamicalArray::setData(int* data) {
	data_ = data;
}
int& DynamicalArray:: operator[](const int i) const {
	return data_[i];
}
std::ostream& DynamicalArray::writeTo(std::ostream& ostrm) const {
	for (int i (0); i < size_; i++)
	{
		ostrm << data_[i] << " ";
	}
	return ostrm;
}
DynamicalArray::~DynamicalArray() {
	delete[]data_;
}