#include <bits/stdc++.h>
#include "DLL.h"

using namespace std;


int main() {
    DoubleLinkedList s = DoubleLinkedList();
    s.push_back(1);
    s.push_back(2);
    s.push_front(0);
    s.push_after_i(5, 1);
    s.push_before_i(7, 0);
    s.print();
    s.delete_all_by_value(2);
    s.print();
    cout << s.find_in_list(5) << " " << s.find_in_list(5, false) << " " << s.get_max_element()->get_value() << endl;
    DoubleLinkedList t;
    t.push_back(10);
    s.extend(t);
    s.print();
    cout << s.size() << " " << t.size() << endl;
}