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

    StackOnList(const StackOnList &obj);

    StackOnList<T> &operator=(const StackOnList<T> &rhs);

    void push(const T &value);

    void pop();

    bool isEmpty();

    void clear();

    T &top();

    std::ostream &WriteTo(std::ostream &ostrm) const;

private:
    template<class A>
    struct Node {
		Node<A> *next_{ nullptr };
		A data_{ 0 };

        Node<A>() = default;
        Node(Node<A> *next, const A &data)
                : next_(next), data_(data) {

        }
    };

private:
    Node<T> *head_{nullptr};
};

template<class T>
StackOnList<T>::StackOnList(const StackOnList &obj) {
	if (obj.head_ != nullptr){
		head_ = new Node<T>(obj.head_);
		Node<T>* current_this = head_;
		Node<T>* current_copy = obj.head_;
		while (current_copy->nextNode_ != nullptr){
			current_this->nextNode_ = new Node<T>(current_copy->nextNode_);
			current_this = current_this->nextNode_;
			current_copy = current_copy->nextNode_;
		}
	}
}

template<class T>
StackOnList<T> &StackOnList<T>::operator=(const StackOnList<T> &rhs) {
    if (this != &rhs) {
		clear();
		if (head_ == nullptr){
			head_ = new Node<T>();
		}
		head_->data_ = obj.head_->data_;

		Node<T>* current_this = head_;
		Node<T>* current_copy = obj.head_;

		while (current_copy->nextNode_ != nullptr){
			if (current_this->nextNode_ == nullptr){
				current_this->nextNode_ = new Node<T>();
			}
			current_this->nextNode_->nextNode_->data_ = current_copy->nextNode_->data_;
			current_copy = current_copy->nextNode_;
			current_this = current_this->nextNode_;
		}
    }
    return *this;
}

template<class T>
void StackOnList<T>::push(const T &value) {
    head_ = new Node<T>(head_, value);
}

template<class T>
void StackOnList<T>::pop() {
    if (nullptr != head_) {
        Node<T> *deletedNode(head_);
        head_ = head_->next_;
        delete deletedNode;
    }
}

template<class T>
bool StackOnList<T>::isEmpty() {
    return head_ == nullptr;
}

template<class T>
void StackOnList<T>::clear() {
    while (!isEmpty()) {
        pop();
    }
}

template<class T>
T &StackOnList<T>::top() {
    if (head_ == nullptr) {
        throw std::exception("Stack is empty");
    }
    return head_->data_;
}

template<class T>
std::ostream &StackOnList<T>::WriteTo(std::ostream &ostrm) const {
    Node<T> *printed_node(head_);
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

std::ostream &operator<<(std::ostream &ostrm, const StackOnList<int> &stack) {
    return stack.WriteTo(ostrm);
}

#endif; // STACK

