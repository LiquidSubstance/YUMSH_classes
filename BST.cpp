#include <bits/stdc++.h>
#include "BST.h"
using namespace std;


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