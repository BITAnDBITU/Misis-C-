#include <iostream>
#include <priorityqueue/priorityqueue.h>

using namespace std;

int main() {
    PriorityQueue queue1(10);

    try {
        queue1.push(1, 3);
        queue1.push(2, 5);
        queue1.push(3, 10);
        queue1.push(4, 1);
        queue1.push(9, 2);
    }
    catch (const std::exception &) {
        cout << "Queue is full" << endl;
    }
    PriorityQueue queue2(queue1);
    cout << queue1 << endl;
    cout << queue2 << endl;
    try {
        cout << "queue1.top() = " << queue1.top() << endl;
        cout << "queue2.top() = " << queue2.top() << endl;
        cout << "queue1.pop() = " << queue1.pop() << endl;
        cout << "queue2.pop() = " << queue2.pop() << endl;
    }
    catch (const exception &) {
        cout << "Queue is empty" << endl;
    }

    PriorityQueue queue3(10);
    try {
        queue3.pop();
    }
    catch (const std::exception &) {
        cout << "queue3 is empty" << endl;
    }
    return 0;
}