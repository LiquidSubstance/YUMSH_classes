#include "DLL.h"
#include <iostream>
using namespace std;

const double eps = 1e-7;

ListNode::ListNode(double v): value(v), next(nullptr), pred(nullptr) {}

double ListNode::get_value() {
    return value;
}

void ListNode::set_value(double v) {
    value = v;
}

ListNode* ListNode::get_next() {
    return next;
}

void ListNode::set_next(ListNode* n) {
    next = n;
}

ListNode* ListNode::get_pred() {
    return pred;
}

void ListNode::set_pred(ListNode* p) {
    pred = p;
}

void DoubleLinkedList::set_header(ListNode* h) {
    header = h;
}

void DoubleLinkedList::set_tailer(ListNode* t) {
    tailer = t;
}

void DoubleLinkedList::set_size(int c) {
    sz = c;
}

bool DoubleLinkedList::equals(double a, double b) {
    return a - eps <= b && b <= a + eps;
}

void DoubleLinkedList::remove_node(ListNode* node) {
    if (node == nullptr) {
        throw "Trying to delete an unexisting node";
    }

    if (node->get_pred() != nullptr) {
        node->get_pred()->set_next(node->get_next());
    } else {
        header = node->get_next();
    }
    if (node->get_next() != nullptr) {
        node->get_next()->set_pred(node->get_pred());
    } else {
        tailer = node->get_pred();
    }
    node->set_next(nullptr);
    node->set_pred(nullptr);
    delete node;
    sz--;
}
DoubleLinkedList::DoubleLinkedList(): header(nullptr), tailer(nullptr), sz(0) {}

ListNode* DoubleLinkedList::get_header() {
    return header;
}

ListNode* DoubleLinkedList::get_tailer() {
    return tailer;
}

bool DoubleLinkedList::empty() {
    return header == nullptr;
}

int DoubleLinkedList::size() {
    return sz;
}

void DoubleLinkedList::push_front(double v) {
    ListNode* node = new ListNode(v);
    if (empty()) {
        header = node;
        tailer = node;
    } else {
        node->set_next(header);
        header->set_pred(node);
        header = node;
    }
    sz++;
}

void DoubleLinkedList::push_back(double v) {
    ListNode* node = new ListNode(v);
    if (empty()) {
        header = node;
        tailer = node;
    } else {
        node->set_pred(tailer);
        tailer->set_next(node);
        tailer = node;
    }
    sz++;
}

ListNode* DoubleLinkedList::get_element(int i) {
    if (i < 0 || i >= sz) {
        throw " Tried to get element by index out of borders";
    }
    ListNode* cur = header;
    for (int j = 0; j < i; ++j) {
        cur = cur->get_next();
    }
    return cur;
}

void DoubleLinkedList::push_before_i(double v, int i) {
    ListNode* first = get_element(i);
    ListNode* node = new ListNode(v);
    ListNode* second = first->get_pred();
    if (second != nullptr) {
        second->set_next(node);
        node->set_pred(second);
    } else {
        header = node;
    }
    node->set_next(first);
    first->set_pred(node);
    sz++;
}

void DoubleLinkedList::push_after_i(double v, int i) {
    ListNode* first = get_element(i);
    ListNode* node = new ListNode(v);
    ListNode* second = first->get_next();
    if (second != nullptr) {
        second->set_pred(node);
        node->set_next(second);
    } else {
        tailer = node;
    }
    first->set_next(node);
    node->set_pred(first);
    sz++;
}
bool DoubleLinkedList::change_element(int i, double v) {
    ListNode* node = get_element(i);
    node->set_value(v);
    return true;
}

bool DoubleLinkedList::pop_front() {
    if (empty()) {
        throw "Tried to delete an element from an empty list";
    }
    remove_node(header);
    return true;
}

bool DoubleLinkedList::pop_back() {
    if (empty()) {
        throw "Tried to delete an element from an empty list";
    }
    remove_node(tailer);
    return true;
}

bool DoubleLinkedList::pop(int i) {
    ListNode* node = get_element(i);
    remove_node(node);
    return true;
}

bool DoubleLinkedList::delete_by_value(double v) {
    ListNode* cur = header;
    while (cur != nullptr) {
        if (equals(cur->get_value(), v)) {
            remove_node(cur);
            return true;
        }
        cur = cur->get_next();
    }
    throw "No elements with such value";
}

bool DoubleLinkedList::delete_all_by_value(double v) {
    bool removed = false;
    ListNode* cur = header;
    while (cur != nullptr) {
        ListNode* next = cur->get_next();
        if (equals(cur->get_value(), v)) {
            remove_node(cur);
            removed = true;
        }
        cur = next;
    }
    if (removed) {
        return removed;
    } else {
        throw "No elements with such value";
    }
}
int DoubleLinkedList::find_in_list(double v, bool from_begin) {
    if (from_begin) {
        ListNode* cur = header;
        int i = 0;
        while (cur != nullptr) {
            if (equals(cur->get_value(), v)) {
                return i;
            }
            cur = cur->get_next();
            i++;
        }
    } else {
        ListNode* cur = tailer;
        int i = sz - 1;
        while (cur != nullptr) {
            if (equals(cur->get_value(), v)) {
                return i;
            }
            cur = cur->get_pred();
            i--;
        }
    }
    throw "No elements with such value";
}

ListNode* DoubleLinkedList::get_max_element() {
    if (empty()) {
        throw "List is empty";
    }
    ListNode* max_node = header;
    ListNode* cur = header;
    while (cur != nullptr) {
        if (max_node->get_value() <= cur->get_value() - eps) {
            max_node = cur;
        }
        cur = cur->get_next();
    }
    return max_node;
}

bool DoubleLinkedList::is_non_decreasing() {
    ListNode* cur = header;
    while (cur != nullptr && cur->get_next() != nullptr) {
        if (cur->get_value() > cur->get_next()->get_value()) {
            return false;
        }
        cur = cur->get_next();
    }
    return true;
}
void DoubleLinkedList::extend(DoubleLinkedList& other) {
    if (this == &other || other.empty()) {
        throw "Trying to extend list with itself";
    }
    if (empty()) {
        header = other.header;
        tailer = other.tailer;
    } else {
        tailer->set_next(other.header);
        other.header->set_pred(tailer);
        tailer = other.tailer;
    }
    sz += other.sz;
    other.set_header(nullptr);
    other.set_tailer(nullptr);
    other.set_size(0);
}

void DoubleLinkedList::print() {
    ListNode* cur = header;
    while (cur != nullptr) {
        cout << cur->get_value() << " ";
        cur = cur->get_next();
    }
    cout << endl;
}

void DoubleLinkedList::clear() {
    ListNode* cur = header;
    while (cur != nullptr) {
        ListNode* next = cur->get_next();
        delete cur;
        cur = next;
    }
    header = nullptr;
    tailer = nullptr;
    sz = 0;
}

DoubleLinkedList::~DoubleLinkedList() {
    clear();
}