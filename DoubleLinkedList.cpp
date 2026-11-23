#include <bits/stdc++.h>

using namespace std;

double eps = 1e-7;

class Node {
private:
    double value;
    Node* next;
    Node* pred;
public:
    Node(double v): value(v), next(nullptr), pred(nullptr) {}

    double get_value() {
        return value;
    }

    void set_value(double v) {
        value = v;
    }

    Node* get_next() {
        return next;
    }

    void set_next(Node* n) {
        next = n;
    }

    Node* get_pred() {
        return pred;
    }

    void set_pred(Node* p) {
        pred = p;
    }
};

class DoubleLinkedList {
private:
    Node* header;
    Node* tailer;
    int sz;

    void set_header(Node* h) {
        header = h;
    }

    void set_tailer(Node* t) {
        tailer = t;
    }

    void set_size(int c) {
        sz = c;
    }

    bool equals(double a, double b) {
        return a - eps <= b && b <= a + eps;
    }

    void remove_node(Node* node) {
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
public:
    DoubleLinkedList(): header(nullptr), tailer(nullptr), sz(0) {}

    Node* get_header() {
        return header;
    }

    Node* get_tailer() {
        return tailer;
    }

    bool empty() {
        return header == nullptr;
    }

    int size() {
        return sz;
    }

    void push_front(double v) {
        Node* node = new Node(v);
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

    void push_back(double v) {
        Node* node = new Node(v);
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

    Node* get_element(int i) {
        if (i < 0 || i >= sz) {
            throw " Tried to get element by index out of borders";
        }
        Node* cur = header;
        for (int j = 0; j < i; ++j) {
            cur = cur->get_next();
        }
        return cur;
    }

    void push_before_i(double v, int i) {
        Node* first = get_element(i);
        Node* node = new Node(v);
        Node* second = first->get_pred();
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

    void push_after_i(double v, int i) {
        Node* first = get_element(i);
        Node* node = new Node(v);
        Node* second = first->get_next();
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

    bool change_element(int i, double v) {
        Node* node = get_element(i);
        node->set_value(v);
        return true;
    }

    bool pop_front() {
        if (empty()) {
            throw "Tried to delete an element from an empty list";
        }
        remove_node(header);
        return true;
    }

    bool pop_back() {
        if (empty()) {
            throw "Tried to delete an element from an empty list";
        }
        remove_node(tailer);
        return true;
    }

    bool pop(int i) {
        Node* node = get_element(i);
        remove_node(node);
        return true;
    }

    bool delete_by_value(double v) {
        Node* cur = header;
        while (cur != nullptr) {
            if (equals(cur->get_value(), v)) {
                remove_node(cur);
                return true;
            }
            cur = cur->get_next();
        }
       throw "No elements with such value";
    }

    bool delete_all_by_value(double v) {
        bool removed = false;
        Node* cur = header;
        while (cur != nullptr) {
            Node* next = cur->get_next();
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

    int find_in_list(double v, bool from_begin = true) {
        if (from_begin) {
            Node* cur = header;
            int i = 0;
            while (cur != nullptr) {
                if (equals(cur->get_value(), v)) {
                    return i;
                }
                cur = cur->get_next();
                i++;
            }
        } else {
            Node* cur = tailer;
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

    Node* get_max_element() {
        if (empty()) {
            throw "List is empty";
        }
        Node* max_node = header;
        Node* cur = header;
        while (cur != nullptr) {
            if (max_node->get_value() <= cur->get_value() - eps) {
                max_node = cur;
            }
            cur = cur->get_next();
        }
        return max_node;
    }

    bool is_non_decreasing() {
        Node* cur = header;
        while (cur != nullptr && cur->get_next() != nullptr) {
            if (cur->get_value() > cur->get_next()->get_value()) {
                return false;
            }
            cur = cur->get_next();
        }
        return true;
    }

    void extend(DoubleLinkedList& other) {
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

    void print() {
        Node* cur = header;
        while (cur != nullptr) {
            cout << cur->get_value() << " ";
            cur = cur->get_next();
        }
        cout << endl;
    }

    void clear() {
        Node* cur = header;
        while (cur != nullptr) {
            Node* next = cur->get_next();
            delete cur;
            cur = next;
        }
        header = nullptr;
        tailer = nullptr;
        sz = 0;
    }

    ~DoubleLinkedList() {
        clear();
    }
};

int main() {
    DoubleLinkedList a = DoubleLinkedList();
}