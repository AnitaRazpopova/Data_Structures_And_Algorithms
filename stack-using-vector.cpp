// stack-using-vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> data;
public:
    void push(int number) {
        data.push_back(number);
    }

    void pop() {
        data.pop_back();
    }

    int peek() const {
        if (data.size() > 0) {
            return data.back();
        }
        else {
            throw std::underflow_error("Stack is empty");
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    // s.push(4); // overflow
    cout << s.peek(); // 3
    s.pop();
    cout << s.peek(); // 2
    s.pop();
    cout << s.peek(); // 1
    s.pop();
    // s.pop(); // underflow
    cout << s.isEmpty(); // 1 = true, is indeed empty
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
