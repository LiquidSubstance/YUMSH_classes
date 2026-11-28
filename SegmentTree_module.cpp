#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

SegmentTreeNode::SegmentTreeNode(int value, int l, int r, SegmentTreeNode *left, SegmentTreeNode *right): value(value), l(l), r(r), left(left), right(right) {}

int SegmentTreeNode::get_value() {
    return value;
}

int SegmentTreeNode::get_l() {
    return l;
}

int SegmentTreeNode::get_r() {
    return r;
}

SegmentTreeNode* SegmentTreeNode::get_right() {
    return right;
}

SegmentTreeNode* SegmentTreeNode::get_left() {
    return left;
}

void SegmentTreeNode::set_value(int v) {
    value = v;
}

SegmentTreeNode::~SegmentTreeNode() {
    delete left;
    delete right;
}

SegmentTreeNode* SegmentTree::build_tree(int l, int r, const vector<int>& a) {
    if (r - l == 1) {
        int v = 0;
        if (pow(sqrt(a[l]), 2) == a[l]) {
            v = 1;
        }
        return new SegmentTreeNode(v, l, r, nullptr, nullptr);
    }
    int m = (l + r) / 2;
    SegmentTreeNode* left = build_tree(l, m, a);
    SegmentTreeNode* right = build_tree(m, r, a);
    return new SegmentTreeNode(left->get_value() + right->get_value(), l, r, left, right);

}

int SegmentTree::get(SegmentTreeNode* cur, int ql, int qr, int l, int r) {
    if (ql <= l && r <= qr) {
        return cur->get_value();
    }
    if (qr <= l || ql >= r) {
        return 0;
    }

    int m = (l + r) / 2;
    return get(cur->get_left(), ql, qr, l, m) + get(cur->get_right(), ql, qr, m, r);
}

void SegmentTree::update(SegmentTreeNode* cur, int v, int i, int l, int r) {
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

SegmentTreeNode* SegmentTree::get_root() {
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