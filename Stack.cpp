#include <iostream>

using namespace std;

const double eps = 1e-7;

struct Node {
    double value;
    Node *next;
};

struct Stack {
    Node *top;
    int size;
};


Node *create_node(double val) {
    Node *new_node = new Node;
    new_node->value = val;
    new_node->next = nullptr;
    return new_node;
}
Stack *create_stack() {
    Stack *stack = new Stack;
    stack->top = nullptr;
    stack->size = 0;
    return stack;
}

bool isEmpty(Stack *stack) {
    if (stack->top == nullptr) {
        return true;
    } else {
        return false;
    }
}
void push_front(Stack *stack, double val) {
    Node *first_node = create_node(val);
    if (isEmpty(stack)) {
        stack->top = first_node;
    } else {
        first_node->next = stack->top;
        stack->top = first_node;
    }
    stack->size++;
}
bool pop_front(Stack *stack) {
    if (isEmpty(stack)) {
        cout << "err" << endl;
        return false;
    }
    Node *to_delete = stack->top;
    stack->top = to_delete->next;
    delete to_delete;
    stack->size--;
    return true;
}
Node* top(Stack *stack) {
    if (isEmpty(stack)) {
        cout << "err" << endl;
        return nullptr;
    }
    return stack->top;
}
void clear_stack(Stack *stack) {
    Node *curr = stack->top;
    while (curr != nullptr) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    stack->size = 0;
    stack->top = stack->top = nullptr;
}
void print(Stack *stack) {
    Node *curr = stack->top;
    while (curr != nullptr) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Stack *stack = create_stack();
    cout << isEmpty(stack) << endl;
    cout << stack->size << endl;
    push_front(stack, 12);
    cout << isEmpty(stack) << endl;
    cout << stack->size << endl;
    cout << top(stack)->value << endl;
    pop_front(stack);
    push_front(stack, 100);
    push_front(stack, 15);
    cout << stack->size << endl;
    cout << top(stack)->value << endl;
    pop_front(stack);
    cout << stack->size << endl;
    cout << top(stack)->value << endl;
    clear_stack(stack);
    delete stack;
}