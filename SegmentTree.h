#pragma once
using namespace std;
#include <vector>
class Node {
private:
    int value;
    Node* left, *right;
    int l, r;
public:
    Node(int value, int l, int r, Node *left, Node *right);

    int get_value();

    int get_l();

    int get_r();

    Node* get_right();

    Node* get_left();

    void set_value(int v);

    ~Node();
};

class SegmentTree {
private:
    Node* root;
    int n;
    Node* build_tree(int l, int r, const vector<int>& a);

    int get(Node* cur, int ql, int qr, int l, int r);

    void update(Node* cur, int v, int i, int l, int r);

public:
    SegmentTree(const vector<int>& a);

    Node* get_root();

    int sum(int l, int r);

    void update(int i, int v);
    ~SegmentTree();
};