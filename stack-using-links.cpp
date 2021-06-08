// stack-using-links.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int data;
    Node* previous = nullptr;

    Node(int data, Node* previous = nullptr) {
        this->data = data;
        this->previous = previous;
    }
};

class Stack {
private:
    Node* top = nullptr;
public:
    Stack() { }

    void _copyStackRecursive(Node* current) {
        if (current != nullptr) {
            _copyStackRecursive(current->previous);
            push(current->data);
        }
    }

    void copyStack(const Stack& rhs) {
        _copyStackRecursive(rhs.top);
    }

    void freeMemory() {
        while (top != nullptr) {
            Node* previous = top->previous;
            delete top;
            top = previous;
        }
    }

    Stack(const Stack& rhs) {
        copyStack(rhs);
    }

    Stack& operator=(const Stack& rhs) {
        if (this != &rhs) {
            freeMemory();
            copyStack(rhs);
        }
        return *this;
    }

    ~Stack() {
        freeMemory();
    }

    void push(int number) {
        if (isEmpty()) {
            top = new Node(number);
        }
        else {
            Node* newTop = new Node(number, top);
            top = newTop;
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node* oldTop = top;
            top = top->previous;
            delete oldTop;
        }
        else {
            throw std::underflow_error("Stack is empty");
        }
    }

    int peek() const {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            throw std::underflow_error("Stack is empty");
        }
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    Stack d(s);
    while (!d.isEmpty()) {
        cout << d.peek();
        d.pop();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
