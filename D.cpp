#include <bits/stdc++.h>
#include "SegmentTree.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    SegmentTree a = SegmentTree(a);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << a.sum(l, r + 1) << endl;
    }
}