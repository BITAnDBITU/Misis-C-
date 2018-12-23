#include <iostream>
#include <priorityqueue/priorityqueue.h>

using namespace std;

int main() {
	PriorityQueue queue1(10);
	
	try {
		queue1.enqueue(1, 3);
		queue1.enqueue(2, 5);
		queue1.enqueue(3, 10);
		queue1.enqueue(4, 1);
		queue1.enqueue(9, 0);
	}
	catch (const std::exception&) {
		cout << "Queue is full" << endl;
	}
	PriorityQueue queue2(queue1);
	
	cout << "queue2.pop() = " << queue2.pop() << endl;
	queue1.enqueue(10, 11);
	cout << "queue1.enqueue(10) = " << queue1.top() << endl;
	cout << "queue1.top() = " << queue1.top() << endl;
	queue1.pop();
	queue1.enqueue(11, 3);
	cout << "queue1.top() = " << queue1.top() << endl;

	PriorityQueue queue3(10);
	try {
		queue3.pop();
	}
	catch (const std::exception&) {
		cout << "queue3 is empty" << endl;
	}
	return 0;
}