#include "priorityqueue.h"
#include <iostream>
#include <algorithm>

PriorityQueue::PriorityQueue(int size)
	: size_(size) {
	data_ = new int[size_];
	priorities_ = new int[size_];
}

PriorityQueue::PriorityQueue(const PriorityQueue &obj)
	: size_(obj.size_), end_(obj.end_) {

	data_ = new int[obj.size_];
	for (int i = 0; i < obj.size_; i++) {
		data_[i] = obj.data_[i];
	}

	priorities_ = new int[obj.size_];
	for (int i = 0; i < obj.size_; i++) {
		priorities_[i] = obj.priorities_[i];
	}
}
PriorityQueue::~PriorityQueue() {
	delete[] data_;
	delete[] priorities_;
}

bool PriorityQueue::isEmpty() const {
	return end_ == 0;
}

bool PriorityQueue::isFull() const {
	return size_ == end_ - 1;
}

int PriorityQueue::top() const {
	return data_[end_ - 1];
}

int PriorityQueue::pop() {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}

	int result = data_[end_ - 1];
	end_--;
	return result;
}

void PriorityQueue::push(int value, int priority) {
	if (isFull()) {
		throw std::exception("Queue is full");
	}
	if (priority <= 0) {
		throw std::exception("Priority cannot be negative");
	}
	bool isPushed = false;
	for (int i(0); i < end_; i++) {
		if (priority >= priorities_[i]) {
			for (int j(end_); j > i; j--) {
				data_[j] = data_[j - 1];
				priorities_[j] = priorities_[j - 1];
			}
			data_[i] = value;
			priorities_[i] = priority;
			isPushed = true;
			break;
		}
	}
	if (!isPushed) {
		data_[end_] = value;
		priorities_[end_] = priority;
	}
	end_++;
}

std::ostream & PriorityQueue::writeTo(std::ostream & ostrm) const
{
	ostrm << "( ";
	for (int i(0); i < end_; i++) {
		ostrm << data_[i] << " ";
	}
	ostrm << " )";
	return ostrm;
}

PriorityQueue &PriorityQueue::operator=(const PriorityQueue &rhs) {
	if (this != &rhs) {
		if (size_ < rhs.size_) {
			int *newData(new int[rhs.size_]);
			delete[] data_;
			data_ = newData;

			int *newPriorities(new int[rhs.size_]);
			delete[] priorities_;
			priorities_ = newPriorities;
		}
		std::copy(rhs.data_, rhs.data_ + rhs.size_, data_);
		std::copy(rhs.priorities_, rhs.priorities_ + rhs.size_, priorities_);
		size_ = rhs.size_;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & ostrm, const PriorityQueue & obj)
{
	return obj.writeTo(ostrm);
}
