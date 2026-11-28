#include <bits/stdc++.h>
#include "Trie.h"

using namespace std;

int main() {
    Trie t = Trie();
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        t.insert(s);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string w;
        cin >> w;
        sort(w.begin(), w.end());
        bool c = t.contains(w);
        if (c) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}