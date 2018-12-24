#pragma once
#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE
#include <iostream>
using namespace std;

class PriorityQueue {
public:
	PriorityQueue() = default;
	~PriorityQueue();
	PriorityQueue(const PriorityQueue &obj);
	explicit PriorityQueue(int size);

	bool isEmpty() const;
	bool isFull() const;
	int top() const;
	int pop();
	void push(int value, int priority);
	std::ostream& writeTo(std::ostream& ostrm) const;
	PriorityQueue &operator=(const PriorityQueue &rhs);

private:
	int *data_;
	int *priorities_;
	int size_;
	int end_{0};
};
std::ostream& operator<<(std::ostream& ostrm, const PriorityQueue& obj);
#endif