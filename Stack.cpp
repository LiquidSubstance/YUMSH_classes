#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack s = Stack();
    cout << s.empty() << endl;
    cout << s.size() << endl;
    s.push_front(12);
    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.get_top()->get_value() << endl;
    s.pop_front();
    s.push_front(100);
    s.push_front(15);
    cout << s.size() << endl;
    cout << s.get_top()->get_value() << endl;
    s.pop_front();
    cout << s.size() << endl;
    cout << s.get_top()->get_value() << endl;
}