#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;

int main() {
    Heap h = Heap();
    h.insert(1);
    h.insert(2);
    h.insert(-10);
    h.insert(20);
    cout << h.extract() << endl;
    cout << h.extract() << endl;
    cout << h.extract() << endl;
    cout << h.extract() << endl;
    cout << h.extract() << endl;
}
