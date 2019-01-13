#pragma once
#ifndef QUEUE
#define QUEUE

#include <iostream>

class Queue {
public:

    Queue() = default;

    Queue(const int size);

    Queue(const Queue &rhs);

    ~Queue();

    Queue &operator=(const Queue &rhs);

    bool isEmpty();

    bool isFull();

    void push(const int val);

    int top();

    void pop();

    std::ostream &writeTo(std::ostream &ostrm) const;

private:
    int *data_{nullptr};
	int size_{ 0 };
    int i_first{ 0 };
    int i_last{ 0 };


};

#endif;
