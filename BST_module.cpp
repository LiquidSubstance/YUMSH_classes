#include "BST.h"
#include <iostream>

using namespace std;

BST_node::BST_node(int v) : value(v), left(nullptr), right(nullptr) {
}

int BST_node::get_value() {
    return value;
}

void BST_node::set_value(int v) {
    value = v;
}

BST_node *BST_node::get_left() {
    return left;
}

void BST_node::set_left(BST_node *l) {
    left = l;
}

BST_node *BST_node::get_right() {
    return right;
}

void BST_node::set_right(BST_node *r) {
    right = r;
}

BST::BST() : root(nullptr) {
}

BST_node *BST::get_root() {
    return root;
}

BST_node *BST::contains(int v) {
    BST_node *cur = root;
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

void BST::insert(int v) {
    if (contains(v) != nullptr) {
        throw "Trying to add an already existing element to BST";
    }

    BST_node *cur = root;
    if (cur == nullptr) {
        root = new BST_node(v);
        return;
    }

    while (cur != nullptr) {
        if (v < cur->get_value()) {
            if (cur->get_left() == nullptr) {
                cur->set_left(new BST_node(v));
                return;
            }
            cur = cur->get_left();
        } else {
            if (cur->get_right() == nullptr) {
                cur->set_right(new BST_node(v));
                return;
            }
            cur = cur->get_right();
        }
    }
}

void BST::erase(int v) {
    if (contains(v) == nullptr) {
        throw "Trying to delete an unexisting element from BST";
    }
    BST_node *cur = root;
    BST_node *prev = nullptr;
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
        BST_node *rp = cur;
        BST_node *r = cur->get_right();
        while (r->get_left() != nullptr) {
            rp = r;
            r = r->get_left();
        }
        cur->set_value(r->get_value());
        cur = r;
        prev = rp;
    }
    BST_node *child = nullptr;
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

void BST::print(BST_node *cur) {
    if (cur == nullptr) {
        return;
    }
    print(cur->get_left());
    cout << cur->get_value() << " ";
    print(cur->get_right());
}

bool BST::empty() {
    return root == nullptr;
}

int BST::size(BST_node *cur) {
    if (cur == nullptr) {
        return 0;
    }
    return 1 + size(cur->get_left()) + size(cur->get_right());
}

void BST::clear(BST_node *cur) {
    if (cur == nullptr) {
        return;
    }
    clear(cur->get_left());
    clear(cur->get_right());
    delete cur;
}

BST::~BST() {
    clear(root);
}
