#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

Node::Node(int value, int l, int r, Node *left, Node *right): value(value), l(l), r(r), left(left), right(right) {}

int Node::get_value() {
    return value;
}

int Node::get_l() {
    return l;
}

int Node::get_r() {
    return r;
}

Node* Node::get_right() {
    return right;
}

Node* Node::get_left() {
    return left;
}

void Node::set_value(int v) {
    value = v;
}

Node::~Node() {
    delete left;
    delete right;
}

Node* SegmentTree::build_tree(int l, int r, const vector<int>& a) {
    if (r - l == 1) {
        return new Node(a[l], l, r, nullptr, nullptr);
    }
    int m = (l + r) / 2;
    Node* left = build_tree(l, m, a);
    Node* right = build_tree(m, r, a);
    return new Node(left->get_value() + right->get_value(), l, r, left, right);

}

int SegmentTree::get(Node* cur, int ql, int qr, int l, int r) {
    if (ql <= l && r <= qr) {
        return cur->get_value();
    }
    if (qr <= l || ql >= r) {
        return 0;
    }

    int m = (l + r) / 2;
    return get(cur->get_left(), ql, qr, l, m) + get(cur->get_right(), ql, qr, m, r);
}

void SegmentTree::update(Node* cur, int v, int i, int l, int r) {
    if (r - l == 1) {
        cur->set_value(v);
        return;
    }
    int m = (l + r) / 2;
    if (i < m) {
        update(cur->get_left(), v, i, l, m);
    } else {
        update(cur->get_right(), v, i, m, r);
    }
    cur->set_value(cur->get_left()->get_value() + cur->get_right()->get_value());
}
SegmentTree::SegmentTree(const vector<int>& a) {
    n = a.size();
    root = build_tree(0, a.size(), a);
}

Node* SegmentTree::get_root() {
    return root;
}

int SegmentTree::sum(int l, int r) {
    return get(root, l, r, 0, n);
}

void SegmentTree::update(int i, int v) {
    update(root, v, i, 0, n);
}
SegmentTree::~SegmentTree() {
    delete root;
}