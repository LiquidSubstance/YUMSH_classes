#pragma once

class ListNode {
private:
    double value;
    ListNode* next;
    ListNode* pred;
public:
    // Конструктор
    ListNode(double v);
    // Геттеры и Сеттеры
    double get_value();

    void set_value(double v);

    ListNode* get_next();

    void set_next(ListNode* n);

    ListNode* get_pred();

    void set_pred(ListNode* p);
};

class DoubleLinkedList {
private:
    ListNode* header;
    ListNode* tailer;
    int sz;

    void set_header(ListNode* h);

    void set_tailer(ListNode* t);

    void set_size(int c);

    bool equals(double a, double b);

    void remove_node(ListNode* node);
public:
    //Конструктор
    DoubleLinkedList();
    //Геттеры
    ListNode* get_header();

    ListNode* get_tailer();

    //Стандартные операции со списком
    bool empty();

    int size();

    void push_front(double v);

    void push_back(double v);

    ListNode* get_element(int i);

    void push_before_i(double v, int i);

    void push_after_i(double v, int i);

    bool change_element(int i, double v);

    bool pop_front();

    bool pop_back();

    bool pop(int i);

    bool delete_by_value(double v);

    bool delete_all_by_value(double v);

    int find_in_list(double v, bool from_begin = true);

    ListNode* get_max_element();

    bool is_non_decreasing();

    void extend(DoubleLinkedList& other);

    void print();

    void clear();

    ~DoubleLinkedList();
};