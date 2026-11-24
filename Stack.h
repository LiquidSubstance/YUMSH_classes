#pragma once

class StackNode {
private:
    double value;
    StackNode* next;
public:

    StackNode(double v);

    double get_value();

    void set_value(double v);

    StackNode* get_next();

    void set_next(StackNode* n);
};

class Stack {
private:
    StackNode* top;
    int sz;

    void set_top(StackNode* t);

    void set_size(int c);
public:

    Stack();

    bool empty();

    int size();

    StackNode* get_top();

    void push_front(double v);

    bool pop_front();

    void print();

    void clear();

    ~Stack();
};