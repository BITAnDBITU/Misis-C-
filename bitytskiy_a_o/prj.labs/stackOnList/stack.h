#pragma once
#ifndef STACK
#define STACK
#include <stddef.h>
#include <iosfwd>
template<class T>
class StackOnList {
public:
	StackOnList() = default;

	~StackOnList() {
		clear();
	}

	StackOnList(const StackOnList& obj) {

	}

	StackOnList& operator=(const StackOnList& rhs) {
		if (this != &rhs) {

		}
		return *this;
	}

	void push(const T& value) {
		head_ = new Node<T>(head_, value);
	}

	void pop(){
		if (nullptr != head_) {
			Node<T>* deletedNode(head_);
			head_ = head_->next_;
			delete deletedNode;
		}
	}

	bool isEmpty() {
		return head_ == nullptr;
	}

	void clear() {
		while (!isEmpty()) {
			pop();
		}
	}

	T& top() {
		if (head_ == nullptr) {
			throw std::exception("Stack is empty");
		}
		return head_->data_;
	}

	std::ostream& WriteTo(std::ostream& ostrm) const {
		Node<T>* printed_node(head_);
		ostrm << '{';
		while (printed_node) {
			ostrm << printed_node->data_;
			printed_node = printed_node->next_;
			if (printed_node) {
				ostrm << ", ";
			}
		}
		ostrm << '}';
		return ostrm;
	}

private:
	template<class A>
	struct Node {
		Node<A>()= default;
		Node<A>* next_{ nullptr };
		A data_{ 0 };
		Node(Node<A>* next,const A& data) : next_(next), data_(data) {

		}
	};

private:
	Node<T>* head_{ nullptr };
};

std::ostream& operator<<(std::ostream& ostrm, const StackOnList<int>& stack) {
	return stack.WriteTo(ostrm);
}
#endif; // STACK

