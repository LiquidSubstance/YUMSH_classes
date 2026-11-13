#include <bits/stdc++.h>

using namespace std;

class Node {
private:
    int value;
    Node* left;
    Node* right;
public:
    Node(int v): value(v), left(nullptr), right(nullptr) {}

    int get_value() {
        return value;
    }

    void set_value(int v) {
        value = v;
    }

    Node* get_left() {
        return left;
    }

    void set_left(Node* l) {
        left = l;
    }

    Node* get_right() {
        return right;
    }

    void set_right(Node* r) {
        right = r;
    }
};

class BST {
private:
    Node* root;
public:
    BST(): root(nullptr) {}

    Node* get_root() {
        return root;
    }

    Node* contains(int v) {
        Node* cur = root;
        while (cur != nullptr) {
            if (cur->get_value() == v) {
                return cur;
            }
            if (cur->get_value() < v) {
                cur = cur->get_right();
            } else {
                cur = cur->get_left();
            }
        }
        return cur;
    }

    void insert(int v) {
        if (contains(v) != nullptr) {
            return;
        }

        Node* cur = root;
        if (cur == nullptr) {
            root = new Node(v);
            return;
        }

        while (cur != nullptr) {
            if (v < cur->get_value()) {
                if (cur->get_left() == nullptr) {
                    cur->set_left(new Node(v));
                    return;
                }
                cur = cur->get_left();
            } else {
                if (cur->get_right() == nullptr) {
                    cur->set_right(new Node(v));
                    return;
                }
                cur = cur->get_right();
            }
        }
    }

    void erase(int v) {
        if (contains(v) == nullptr) {
            return;
        }
        Node* cur = root;
        Node* prev = nullptr;
        while (cur != nullptr) {
            if (cur->get_value() == v) {
                break;
            }
            prev = cur;
            if (v < cur->get_value()) {
                cur = cur->get_left();
            } else {
                cur = cur->get_right();
            }
        }
        if (cur->get_left() != nullptr && cur->get_right() != nullptr) {
            Node* rp = cur;
            Node* r = cur->get_right();
            while (r->get_left() != nullptr) {
                rp = r;
                r = r->get_left();
            }
            cur->set_value(r->get_value());
            cur = r;
            prev = rp;
        }
        Node* child = nullptr;
        if (cur->get_left() != nullptr) {
            child = cur->get_left();
        } else {
            child = cur->get_right();
        }
        if (prev == nullptr) {
            root = child;
        } else if (prev->get_left() == cur) {
            prev->set_left(child);
        } else {
            prev->set_right(child);
        }

        cur->set_left(nullptr);
        cur->set_right(nullptr);
        delete cur;
    }

    void print(Node* cur) {
        if (cur == nullptr) {
            return;
        }
        print(cur->get_left());
        cout << cur->get_value() << " ";
        print(cur->get_right());
    }

    bool empty() {
        return root == nullptr;
    }

    int size(Node* cur) {
        if (cur == nullptr) {
            return 0;
        }
        return 1 + size(cur->get_left()) + size(cur->get_right());
    }

    void clear(Node* cur) {
        if (cur == nullptr) {
            return;
        }
        clear(cur->get_left());
        clear(cur->get_right());
        delete cur;
    }

    ~BST() {
        clear(root);
    }
};

int main() {
    BST s = BST();
    // cout << s.empty() << endl;
    s.insert(10);
    s.insert(20);
    s.insert(5);
    s.insert(8);
    s.insert(30);
    s.insert(24);
    s.insert(1);
    s.print(s.get_root());
    cout << endl;
    s.erase(20);
    s.print(s.get_root());
    cout << endl;
    s.erase(10);
    s.print(s.get_root());
    cout << endl;
    s.erase(5);
    s.print(s.get_root());
    cout << endl;
}