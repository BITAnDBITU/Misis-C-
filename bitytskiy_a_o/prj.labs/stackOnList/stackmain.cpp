#include"stack.h"
#include <iostream>
using namespace std;
void test1() {
	StackOnList<int> stack1;
	stack1.push(2);
	stack1.push(1);
	stack1.push(6);
	stack1.push(7);
	try {
		while (!stack1.isEmpty()) {
			cout << stack1.top() << endl;
			stack1.pop();
		}
	}
	catch (const std::exception&) {
		cout << "smth wrong" << endl;
	}
}
void test2() {
	StackOnList<int> stack1;
	try {
		stack1.top();
	}
	catch (const std::exception&) {
		cout << "smth wrong" << endl;
	}
}
void test3() {
	StackOnList<int> stack1;
	stack1.push(2);
	stack1.push(1);
	stack1.push(6);
	stack1.push(7);
	cout << stack1 << endl;
}
int main() {
	test1();
	test2();
	test3();
};