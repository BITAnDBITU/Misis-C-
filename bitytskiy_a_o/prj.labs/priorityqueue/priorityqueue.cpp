#include "priorityqueue.h"
#include <algorithm>

PriorityQueue::PriorityQueue(int size)
		: size_(size), end_(0){
	data_ = new int[size_];
	priorities_ = new int[size_];
}
PriorityQueue::PriorityQueue(const PriorityQueue &obj)
		: size_(obj.size_),end_(obj.end_) {
	data_ = new int[size_];
	std::copy(obj.data_, obj.data_ + obj.size_, data_);
	
	priorities_ = new int[size_];
	std::copy(obj.priorities_, obj.priorities_+ obj.size_, priorities_);
}
PriorityQueue::~PriorityQueue() {
	delete[]data_;
	delete[]priorities_;
}

int PriorityQueue::getSize() const {
	return size_;
}

bool PriorityQueue::isEmpty() const {
	return end_ == 0;
}

bool PriorityQueue::isFull() const {
	return size_ == end_;
}

int PriorityQueue::top() const {
	return data_[end_];
}

int PriorityQueue::pop() {
	if (isEmpty()) {
		throw std::exception("Queue is empty");
	}

	int result = data_[end_];
	end_--;
	return result;
}

void PriorityQueue::enqueue(int value, int priority) {
	if (isFull()) {
		throw std::exception("Queue is full");
	}

	end_++;

	for (int i(0); i < end_; i++) {
		if (priority <= priorities_[i]) {
			for (int j(end_-1); j > i; j--) {
				data_[j] = data_[j-1];
				priorities_[j] = priorities_[j-1];
			}
			data_[i] = value;
			priorities_[i] = priority;
			break;
		}
	}
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
