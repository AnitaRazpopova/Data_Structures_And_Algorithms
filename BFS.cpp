// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

void BFS(int s, list<int>* adj) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    list<int> queue;
  +
    queue.push_back(s);
    visited[s] = true;
    list<int>::iterator i;
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        // Проверка на специфично условие, което се търси.
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
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
