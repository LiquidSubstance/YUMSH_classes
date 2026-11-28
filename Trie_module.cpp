#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

TrieNode::TrieNode(char ch): symbol(ch), ends_with(0), h(-1) {
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

int TrieNode::get_ends_with() {
    return ends_with;
}

char TrieNode::get_symbol() {
    return symbol;
}

auto TrieNode::get_children() {
    return children;
}

int TrieNode::get_h() {
    return h;
}

void TrieNode::set_h(int height) {
    h = height;
}

void TrieNode::set_child(int i, TrieNode* child) {
    children[i] = child;
}

void TrieNode::increase_get_ends_with() {
    ends_with++;
}

bool TrieNode::is_leaf() {
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (children[i] != nullptr) {
            flag = false;
            break;
        }
    }
    return flag;
}

TrieNode::~TrieNode() {
    for (int i = 0; i < 26; i++) {
        delete children[i];
    }
}

Trie::Trie(): root(new TrieNode()) {}

TrieNode* Trie::get_root() {
    return root;
}

void Trie::insert(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->get_children()[c - 'a'] == nullptr) {
            cur->set_child(c - 'a', new TrieNode(c));
            cur->get_children()[c - 'a']->set_h(cur->get_h() + 1);
        }
        cur = cur->get_children()[c - 'a'];
    }
    cur->increase_get_ends_with();
}

TrieNode* Trie::find_root_for_prefix(const string& prefix) {
    TrieNode* cur = root;
    for (char c : prefix) {
        if (cur->get_children()[c - 'a'] == nullptr) {
            return nullptr;
        }
        cur = cur->get_children()[c - 'a'];
    }
    return cur;
}

bool Trie::contains(const string& word) {
    TrieNode* cur = root;
    for (char c : word) {
        if (cur->get_children()[c - 'a'] == nullptr) {
            return false;
        }
        cur = cur->get_children()[c - 'a'];
    }
    return cur->is_leaf();
}

Trie::~Trie() {
    delete root;
}