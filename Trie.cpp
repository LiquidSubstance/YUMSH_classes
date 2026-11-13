#include <bits/stdc++.h>

using namespace std;

class Node {
private:
    int ends_with;
    char symbol;
    int h;
    Node* children[26];
public:
    Node(char ch = '\0'): symbol(ch), ends_with(0), h(-1) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }

    int get_ends_with() {
        return ends_with;
    }

    char get_symbol() {
        return symbol;
    }

    auto get_children() {
        return children;
    }

    int get_h() {
        return h;
    }

    void set_h(int height) {
        h = height;
    }

    void set_child(int i, Node* child) {
        children[i] = child;
    }

    void increase_get_ends_with() {
        ends_with++;
    }

    bool is_leaf() {
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    ~Node() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
};

class Trie {
private:
    Node* root;
public:
    Trie(): root(new Node()) {}

    Node* get_root() {
        return root;
    }

    void insert(const string& word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->get_children()[c - 'a'] == nullptr) {
                cur->set_child(c - 'a', new Node(c));
                cur->get_children()[c - 'a']->set_h(cur->get_h() + 1);
            }
            cur = cur->get_children()[c - 'a'];
        }
        cur->increase_get_ends_with();
    }

    Node* find_root_for_prefix(const string& prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (cur->get_children()[c - 'a'] == nullptr) {
                return nullptr;
            }
            cur = cur->get_children()[c - 'a'];
        }
        return cur;
    }

    bool contains(const string& word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->get_children()[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->get_children()[c - 'a'];
        }
        return cur->get_ends_with() > 0;
    }

    ~Trie() {
        delete root;
    }
};

int main() {

}