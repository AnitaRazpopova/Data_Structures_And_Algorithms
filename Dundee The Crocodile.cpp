// Dundee The Crocodile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
using namespace std;

int main() {
    string str1;
    string str2;
    getline(cin,str1);
    getline(cin, str2);
    set<string> st;
    set<string> st2;
    set<string> current;

    istringstream ss(str1);
    string temp;
    while (ss >> temp) {
        if (st.count(temp) == 1) {
            current.insert(temp);
            st.erase(temp);
        }
        else if(st.count(temp) == 0 && current.count(temp) == 0){
            st.insert(temp);
        }
    }

    istringstream ss1(str2);
    current.clear();

    while (ss1 >> temp) {
        if (st2.count(temp) == 1) {
            current.insert(temp);
            st2.erase(temp);
        }
        else if (st2.count(temp) == 0 && current.count(temp) == 0) {
            st2.insert(temp);
        }
    }

    current.clear();

    for (auto st_el : st) {
        if (st2.count(st_el) == 0) {
            current.insert(st_el);
        }
    }

    for (auto st_el : st2) {
        if (st.count(st_el) == 0) {
            current.insert(st_el);
        }
    }


    for (auto st_el : current) {
        cout << st_el << endl;

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
