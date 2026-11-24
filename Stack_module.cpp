#include "Stack.h"
#include <iostream>
using namespace std;

StackNode::StackNode(double v): value(v), next(nullptr) {}

double StackNode::get_value() {
    return value;
}

void StackNode::set_value(double v) {
    value = v;
}

StackNode* StackNode::get_next() {
    return next;
}

void StackNode::set_next(StackNode* n) {
    next = n;
}

void Stack::set_top(StackNode* t) {
    top = t;
}

void Stack::set_size(int c) {
    sz = c;
}

Stack::Stack(): top(nullptr), sz(0) {}

bool Stack::empty() {
    return top == nullptr;
}

int Stack::size() {
    return sz;
}

StackNode* Stack::get_top() {
    if (empty()) {
        throw "Tried to get top of an empty stack";
    }
    return top;
}

void Stack::push_front(double v) {
    StackNode* node = new StackNode(v);
    node->set_next(top);
    set_top(node);
    sz++;
}

bool Stack::pop_front() {
    if (empty()) {
        throw "Tried to delete an element from an empty stack";
    }
    StackNode* to_delete = top;
    set_top(to_delete->get_next());
    to_delete->set_next(nullptr);
    delete to_delete;
    sz--;
    return true;
}

void Stack::print() {
    StackNode* cur = top;
    while (cur != nullptr) {
        cout << cur->get_value() << " ";
        cur = cur->get_next();
    }
    cout << endl;
}

void Stack::clear() {
    StackNode* cur = top;
    while (cur != nullptr) {
        StackNode* next = cur->get_next();
        delete cur;
        cur = next;
    }
    set_top(nullptr);
    set_size(0);
}

Stack::~Stack() {
    clear();
}