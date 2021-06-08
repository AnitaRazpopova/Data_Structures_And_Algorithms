// InsertionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void NaiveInsertionSort(int * arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int elIndex = i;
        while (elIndex > 0 && arr[elIndex] < arr[elIndex - 1])
        {
            swap(arr, elIndex, elIndex - 1);
            elIndex--;
        }

    }
}

void InsertionSort(int* arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int element = arr[i];
        int index = i - 1;
        while (index >= 0 && arr[index] > element)
        {
            arr[index + 1] = arr[index];
            index--;
        }
        arr[index + 1] = element;
    }
}
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    InsertionSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i];
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
