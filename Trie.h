#pragma once
#include <bits/stdc++.h>
using namespace std;
class TrieNode {
private:
    int ends_with;
    char symbol;
    int h;
    TrieNode* children[26];
public:
    TrieNode(char ch = '\0');

    int get_ends_with();

    char get_symbol();

    auto get_children();

    int get_h();

    void set_h(int height);

    void set_child(int i, TrieNode* child);

    void increase_get_ends_with();

    bool is_leaf();

    ~TrieNode();
};

class Trie {
private:
    TrieNode* root;
public:
    Trie();

    TrieNode* get_root();

    void insert(const string& word);

    TrieNode* find_root_for_prefix(const string& prefix);

    bool contains(const string& word);

    ~Trie();
};