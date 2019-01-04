
#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(const int size) : size_(size), i_first(0), i_last(0) {
	data_ = new int[size_];
}

Queue::~Queue() {
	delete[] data_;
}

Queue::Queue(const Queue &rhs) {
	i_first = rhs.i_first;
	i_last = rhs.i_last;
	size_ = rhs.size_;
	data_ = new int[size_];
	std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
}

bool Queue::isEmpty() {
	return i_first == i_last;
}

bool Queue::isFull() {
	return (i_last - i_first) >= size_;
}

void Queue::push(const int val) {
	if (isFull()) {
		throw std::exception("Queue is full");
	}
	else {
		data_[i_last % size_] = val;
		i_last++;
	}
}

Queue &Queue::operator=(const Queue &rhs) {
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

int Queue::pop() {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}
	else {
		int result = data_[i_first % size_];
		i_first++;
		return result;
	}

}

int Queue::top() {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}
	else {
		return data_[i_first % size_];
	}
}

std::ostream &Queue::writeTo(std::ostream &ostrm) const {
	ostrm << "( ";
	for (int i(i_first); i < i_last; i++) {
		ostrm << data_[i % size_] << " ";
	}
	ostrm << " )";
	return ostrm;
}

