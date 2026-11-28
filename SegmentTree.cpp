#include <bits/stdc++.h>
#include "SegmentTree.h"
using namespace std;


int main() {
    SegmentTree t = SegmentTree({1, 6, 3, 4, 5, 10, 3, 4, 16, 8, 9});
    cout << t.sum(5, 9) << endl;
    t.update(5, -2);
    cout << t.sum(5, 9) << endl;
}