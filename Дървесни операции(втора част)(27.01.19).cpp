// Дървесни операции(втора част)(27.01.19).cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) :key(key), left(nullptr), right(nullptr) {}

};

Node* root;

Node* add(Node* root, int key) {
    if (root == nullptr) {
        root = new Node(key);
    }
    else if (key == root->key) {
        return root;
    }
    else if (key < root->key) {
        root->left = add(root->left, key);
    }
    else if (key > root->key) {
        root->right = add(root->right, key);
    }
    return root;
}

void print(Node* root) {
    if (root != nullptr) {
        cout << root->key << ' ';
        print(root->left);
        print(root->right);
    }
}
void print_odd_layers(Node* root) {
    if (root != nullptr) {
        queue<Node*> q;
        q.push(root);
        int layer = 1;

        while (!q.empty()) {
            int s = (int)q.size();
            while (s--) {
                Node* current = q.front();
                q.pop();
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                if (current->right != nullptr) {
                    q.push(current->right);
                }
                if (layer % 2 != 0) {
                    cout << current->key << " ";
                }
            }
            ++layer;
        }
    }

}

Node* minDataNode(Node* root) {
    if (root == nullptr || root->left == nullptr)
        return root;
    return minDataNode(root->left);
}

Node* remove(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }
    else if (key > root->key) {
        root->right = remove(root->right, key);
    }
    else if (key < root->key) {
        root->left = remove(root->left, key);
    }
    else {
        if (root->left && root->right) {
            Node* temp = minDataNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
        else if (root->left) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->right) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else {
            delete root;
            root = nullptr;
        }


    }
    return root;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "add") {
            int number;
            cin >> number;
            root = add(root, number);
        }
        else if (str == "print") {
            print(root);
        }
        else if (str == "remove") {
            int number;
            cin >> number;
            root = remove(root, number);
        }
        else if (str == "print_odd_layers") {
            print_odd_layers(root);
        }
    }
    return 0;
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
