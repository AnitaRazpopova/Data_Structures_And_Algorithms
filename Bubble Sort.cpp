// Bubble Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void BubbleSort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        bool isSwapped = false;
        for (int j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                isSwapped = true;
            }
        }
        if (!isSwapped) {
            return;
        }
    }
}



int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    BubbleSort(arr, 10);

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
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
