
#include <iostream>
#include <queue/queue.h>

using namespace std;

void test1() {
    Queue queue1(5);
    try {
        queue1.push(2);
        queue1.push(3);
        queue1.push(4);
        queue1.push(1);
        queue1.push(6);

    }
    catch (const exception &) {
        cout << "Queue is full" << endl;
    }
    try {
        queue1.push(4);
    }
    catch (const exception &) {
        cout << "Queue is full" << endl;
    }

    Queue queue2(queue1);
    try {
        cout << queue1.top() << endl;
		queue1.pop();
        cout << queue1.top() << endl;
        queue1.pop();
        cout << queue1.top() << endl;
        queue2.pop();
    }
    catch (const exception &) {
        cout << "Queue is empty" << endl;
    }

    Queue queue3(5);
    try {
        cout << queue3.top() << endl;
    }
    catch (const exception &) {
        cout << " top: Queue is empty" << endl;
    }
    
}

int main() {
    test1();
}