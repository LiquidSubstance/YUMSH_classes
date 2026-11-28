#pragma once
using namespace std;
#include <vector>
class SegmentTreeNode {
private:
    int value;
    SegmentTreeNode* left, *right;
    int l, r;
public:
    SegmentTreeNode(int value, int l, int r, SegmentTreeNode *left, SegmentTreeNode *right);

    int get_value();

    int get_l();

    int get_r();

    SegmentTreeNode* get_right();

    SegmentTreeNode* get_left();

    void set_value(int v);

    ~SegmentTreeNode();
};

class SegmentTree {
private:
    SegmentTreeNode* root;
    int n;
    SegmentTreeNode* build_tree(int l, int r, const vector<int>& a);

    int get(SegmentTreeNode* cur, int ql, int qr, int l, int r);

    void update(SegmentTreeNode* cur, int v, int i, int l, int r);

public:
    SegmentTree(const vector<int>& a);

    SegmentTreeNode* get_root();

    int sum(int l, int r);

    void update(int i, int v);
    ~SegmentTree();
};