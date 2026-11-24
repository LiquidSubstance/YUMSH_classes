#pragma once

class BST_node {
private:
    int value;
    BST_node *left;
    BST_node *right;

public:
    BST_node(int v);

    int get_value();

    void set_value(int v);

    BST_node *get_left();

    void set_left(BST_node *l);

    BST_node *get_right();

    void set_right(BST_node *r);
};

class BST {
private:
    BST_node *root;

public:
    BST();

    BST_node *get_root();

    BST_node *contains(int v);

    void insert(int v);

    void erase(int v);

    void print(BST_node *cur);

    bool empty();

    int size(BST_node *cur);

    void clear(BST_node *cur);

    ~BST();
};
