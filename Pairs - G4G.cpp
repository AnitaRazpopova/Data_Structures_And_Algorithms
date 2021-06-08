// Pairs - G4G.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int sum = 0;
        int N;
        cin >> N;
        vector<int> arr;
        arr.resize(N);
        for (int j = 0; j < N; j++) {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.begin() + N);
        int k = N;
        while(k > 1) {
            if (N-1 & 2) {
                sum +=  arr[k-1] * arr[k - 2];
                k--;
            }
            else {
                if (k > 0) {
                    sum += arr[k-1] * arr[k - 2];
                    k--;
                }
                else {
                    sum = sum + arr[k-1];
                }
            }
            k--;
        } 
        cout << sum << endl;
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
