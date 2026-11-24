#include <algorithm>

#include "Stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack s = Stack();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push_front(x);
    }
    Stack b = Stack();
    int cur_mx;
    int pred_mx = 1e9;
    for (int i = 0; i < n; i++) {
        cur_mx = -1000000000;
        while (!s.empty()) {
            int a = s.get_top()->get_value();
            if (a < pred_mx) {
                cur_mx = max(a, cur_mx);
            }
            s.pop_front();
            b.push_front(a);
        }
        while (b.size() != i) {
            int a = b.get_top()->get_value();
            b.pop_front();
            s.push_front(a);
        }
        int cnt = 0;
        StackNode *cur = s.get_top();
        while (cur != nullptr) {
            if (cur->get_value() == cur_mx) {
                cnt++;
            }
            cur = cur->get_next();
        }
        for (int j = 0; j < cnt; j++) {
            i++;
            b.push_front(cur_mx);
        }
        i--;
        pred_mx = cur_mx;
    }
    b.print();
}