#include <bits/stdc++.h>

using namespace std;

class Heap {
private:
    vector<int> heap;
public:
    Heap(): heap({}) {}

    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[(i - 1) / 2], heap[i]);
            i = (i - 1) / 2;
        }
    }

    int extract() {
        if (heap.empty()) {
            return -1e9;
        }
        int mn = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 0;
        while (2 * i + 1 < heap.size()) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int m = i;
            if (heap[l] < heap[i]) {
                m = l;
            }
            if (r < heap.size() && heap[r] < heap[m]) {
                m = r;
            }
            if (i == m) {
                break;
            }
            swap(heap[i], heap[m]);
            i = m;
        }
        return mn;
    }

    ~Heap() {}
};

int main() {

}
