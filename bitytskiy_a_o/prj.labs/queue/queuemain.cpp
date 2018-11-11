
#include <iostream>
#include "queue.h"
using namespace std;
void test1() {
	Queue queue1(5);
	queue1.push(2);
	queue1.push(3);
	queue1.push(4);
	queue1.push(1);

	Queue queue2(queue1);
	cout << queue1.top() << endl;
	cout << queue1.pop() << endl;
	cout << queue1.pop() << endl;
	cout << queue2.pop() << endl;
}
int main() {
	test1();
}