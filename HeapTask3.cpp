#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;

int game(Heap h) {
    while (h.size() > 1) {
        int x = h.extract();
        int y = h.extract();
        if (x != y) {
            h.insert(x - y);
        }
    }
    if (h.size() == 0) {
        return 0;
    } else {
        return h.extract();
    }
}

int main() {
    Heap h = Heap();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    cout << game(h) << endl;
}
