#pragma once
#ifndef QUEUE
#define QUEUE
#include <iostream>
class Queue {
public:

	Queue() = default;
	Queue(const int size);
	Queue(const Queue& rhs);
	~Queue();
	Queue& operator=(const  Queue& rhs);
	bool isEmpty();
	bool isFull();
	void push(const int val);
	int top();
	int pop();
	std::ostream& writeTo(std::ostream& ostrm) const;

private:
	int* data_{ nullptr };
	int size_;
	int i_first;
	int i_last;


};
/*std::ostream& operator<<(std::ostream& ostrm, const Queue& stack) {
	return stack.writeTo(ostrm);
}*/
#endif;
