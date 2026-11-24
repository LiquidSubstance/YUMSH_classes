#pragma once

class Node {
private:
    double value;
    Node* next;
    Node* pred;
public:
    // Конструктор
    Node(double v);
    // Геттеры и Сеттеры
    double get_value();

    void set_value(double v);

    Node* get_next();

    void set_next(Node* n);

    Node* get_pred();

    void set_pred(Node* p);
};

class DoubleLinkedList {
private:
    Node* header;
    Node* tailer;
    int sz;

    void set_header(Node* h);

    void set_tailer(Node* t);

    void set_size(int c);

    bool equals(double a, double b);

    void remove_node(Node* node);
public:
    //Конструктор
    DoubleLinkedList();
    //Геттеры
    Node* get_header();

    Node* get_tailer();

    //Стандартные операции со списком
    bool empty();

    int size();

    void push_front(double v);

    void push_back(double v);

    Node* get_element(int i);

    void push_before_i(double v, int i);

    void push_after_i(double v, int i);

    bool change_element(int i, double v);

    bool pop_front();

    bool pop_back();

    bool pop(int i);

    bool delete_by_value(double v);

    bool delete_all_by_value(double v);

    int find_in_list(double v, bool from_begin = true);

    Node* get_max_element();

    bool is_non_decreasing();

    void extend(DoubleLinkedList& other);

    void print();

    void clear();

    ~DoubleLinkedList();
};