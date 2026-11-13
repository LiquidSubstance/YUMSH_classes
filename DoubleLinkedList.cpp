#include <iostream>

using namespace std;

const double eps = 1e-7;

struct Node {
    double value;
    Node *next;
    Node *pred;
};

struct List {
    Node *header;
    Node *tailer;
};


Node *create_node(double val) {
    Node *new_node = new Node;
    new_node->value = val;
    new_node->next = nullptr;
    new_node->pred = nullptr;
    return new_node;
}
List *create_list() {
    List *list = new List;
    list->header = nullptr;
    list->tailer = nullptr;
    return list;
}

bool isEmpty(List *list) {
    if (list->header == nullptr) {
        return true;
    } else {
        return false;
    }
}

void push_front(List *list, double val) {
    Node *first_node = create_node(val);
    if (isEmpty(list)) {
        list->header = first_node;
        list->tailer = first_node;
    } else {
        Node *last = list->header;
        list->header = first_node;
        list->header->next = last;
        last->pred = first_node;
    }
}
void push_back(List *list, double val) {
    Node *first_node = create_node(val);
    if (isEmpty(list)) {
        list->header = first_node;
        list->tailer = first_node;
    } else {
        Node *last = list->tailer;
        list->tailer = first_node;
        list->tailer->pred = last;
        last->next = first_node;
    }
}
int size(List *list) {
    if (isEmpty(list)) {
        return 0;
    } else {
        int s = 1;
        Node* last = list->header;
        while (last->next != nullptr) {
            s++;
            last = last->next;
        }
        return s;
    }
}
void push_before_i(List *list, double val, int i) {
    if (0 <= i && i < size(list) && !isEmpty(list)) {
        Node *new_node = create_node(val);
        Node *first = list->header;
        for (int j = 0; j < i; ++j) {
            first = first->next;
        }
        Node* second = first->pred;
        if (second != nullptr) {
            second->next = new_node;
            new_node->pred = second;
            first->pred = new_node;
            new_node->next = first;
        } else {
            list->header = new_node;
            list->header->next = first;
            first->pred = new_node;
        }
    } else {
        cout << "err" << endl;
    }
}
void push_after_i(List *list, double val, int i) {
    if (0 <= i && i < size(list) && !isEmpty(list)) {
        Node *new_node = create_node(val);
        Node *first = list->header;
        for (int j = 0; j < i; ++j) {
            first = first->next;
        }
        Node* second = first->next;
        if (second != nullptr) {
            second->pred = new_node;
            new_node->next = second;
            first->next = new_node;
            new_node->pred = first;
        } else {
            first->next = new_node;
            new_node->pred = first;
            list->tailer = new_node;
        }
    } else {
        cout << "err" << endl;
    }
}
bool change_element(List *list, int i, double val) {
    if (0 <= i && i < size(list) && !isEmpty(list)) {
        Node *first = list->header;
        for (int j = 0; j < i; ++j) {
            first = first->next;
        }
        first->value = val;
        return true;
    } else {
        cout << "err" << endl;
        return false;
    }
}

Node *get_element(List *list, int i) {
    if (0 <= i && i < size(list) && !isEmpty(list)) {
        Node *first = list->header;
        for (int j = 0; j < i; ++j) {
            first = first->next;
        }
        return first;
    } else {
        cout << "err" << endl;
        return nullptr;
    }
}

bool pop_front(List *list) {
    if (isEmpty(list)) {
        cout << "err" << endl;
        return false;
    }
    Node *to_delete = list->header;
    list->header = to_delete->next;
    if (list->header != nullptr) {
        list->header->pred = nullptr;
    }
    delete to_delete;
    return true;
}
bool pop_back(List *list) {
    if (isEmpty(list)) {
        cout << "err" << endl;
        return false;
    }
    Node *to_delete = list->tailer;
    list->tailer = to_delete->pred;
    if (list->tailer != nullptr) {
        list->tailer->next = nullptr;
    }
    delete to_delete;
    return true;
}
bool pop(List *list, int i) {
    if (0 <= i && i < size(list) && !isEmpty(list)) {
        if (i == 0) {
            pop_front(list);
            return true;
        }
        if (i == size(list) - 1) {
            pop_back(list);
            return true;
        }
        Node *first = list->header;
        for (int j = 0; j < i; ++j) {
            first = first->next;
        }
        Node* p = first->pred;
        Node* n = first->next;
        delete first;
        p->next = n;
        n->pred = p;
        return true;
    } else {
        cout << "err" << endl;
        return false;
    }
}
void delete_by_value(List *list, double value) {
    int j = 0;
    for (Node* i = list->header; i->next != nullptr; i = i->next) {
        double v = i->value;
        if (value - eps <= v && v <= value + eps) {
            pop(list, j);
            return;
        }
        j++;
    }
}
bool delete_all_by_value(List *list, double value) {
    int j = 0;
    for (Node* i = list->header; i->next != nullptr; i = i->next) {
        double v = i->value;
        if (value - eps <= v && v <= value + eps) {
            pop(list, j);
        }
        j++;
    }
    return false;
}
int find_in_list(List *list, double value, bool fromBegin) {
    if (fromBegin) {
        Node *last = list->header;
        for (int i = 0; i < size(list); i++) {
            double v = last->value;
            if (value - eps <= v && v >= value + eps) {
                return i;
            }
            last = last->next;
        }
        return -1;
    } else {
        Node *last = list->tailer;
        for (int i = size(list) - 1; i >= 0; i--) {
            double v = last->value;
            if (value - eps <= v && v >= value + eps) {
                return i;
            }
            last = last->pred;
        }
        return -1;
    }
}

Node *get_max_element(List *list) {
    if (isEmpty(list)) {
        return nullptr;
    } else {
        Node *last = list->header;
        Node *max_Node = last;
        for (int i = 0; i < size(list); i++) {
            if (max_Node->value <= last->value - eps) {
                max_Node = last;
            }
            last = last->next;
        }
        return max_Node;
    }
}

bool is_non_decreasing(List *list) {
    Node *last = list->header;
    for (int i = 0; i < size(list) - 1; ++i) {
        if (last->value > last->next->value) {
            return false;
        }
        last = last->next;
    }
    return true;
}

List *extend(List *list1, List *list2) {
    if (isEmpty(list1)) {
        return list2;
    }
    if (isEmpty(list2)) {
        return list1;
    }
    Node *last = list1->tailer;
    Node *first = list2->header;
    last->next = first;
    first->pred = last;
    return list1;
}


void clear_list(List *list) {
    Node *curr = list->header;
    while (curr != nullptr) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    list->header = list->tailer = nullptr;
}
void print(List *list) {
    Node *last = list->header;
    int n = size(list);
    for (int i = 0; i < n; ++i) {
        cout << last->value << " ";
        last = last->next;
    }
    cout << endl;
}
int main() {
    List *list = create_list();
    cout << "#######################" << endl;

    push_front(list, 3.14);
    push_front(list, 2.71);
    push_back(list, 1.61);
    print(list);
    cout << "#######################" << endl;
    push_before_i(list, 0.5, 1);
    print(list);
    cout << "#######################" << endl;

    push_after_i(list, 4.2, 2);
    print(list);
    cout << "#######################" << endl;

    change_element(list, 3, 9.99);
    print(list);
    cout << "#######################" << endl;

    cout << find_in_list(list, 9.99, true) << endl;
    cout << "#######################" << endl;

    pop(list, 1);
    print(list);
    cout << "#######################" << endl;

    delete_by_value(list, 3.14);
    print(list);
    cout << "#######################" << endl;

    push_back(list, 5.5);
    push_front(list, 5.5);
    print(list);
    delete_all_by_value(list, 5.5);
    print(list);
    cout << "#######################max" << endl;

    Node *max_node = get_max_element(list);
    if (max_node) cout << max_node->value << endl;
    cout << "#######################" << endl;

    cout << is_non_decreasing(list) << endl;

    cout << "#######################" << endl;

    List *list2 = create_list();
    push_back(list2, 7.7);
    push_back(list2, 8.8);
    extend(list, list2);
    print(list);

    cout << "#######################" << endl;

    clear_list(list);
    print(list);

    cout << isEmpty(list) << endl;
    delete list;
    return 0;
}