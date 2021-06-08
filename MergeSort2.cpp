// MergeSort2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T>
void  Merge(T* arr1, int len1, T* arr2, int len2)
{

    T* result = new T[len1 + len2];
    int cursor1 = 0;
    int cursor2 = 0;
    int resultCursor = 0;
    while (cursor1 < len1 && cursor2 < len2)
    {
        if (arr1[cursor1] <= arr2[cursor2])
            result[resultCursor++] = arr1[cursor1++];
        else
            result[resultCursor++] = arr2[cursor2++];
    }
    while (cursor1 < len1)
        result[resultCursor++] = arr1[cursor1++];


    while (cursor2 < len2)
        result[resultCursor++] = arr2[cursor2++];


    //Въпреки,че arr1 е с по-малка големина, можем да си ползволим това да излезем извън масива, понеже знаем, че arr1 с arr2 са слепени     
    for (int i = 0; i < (len1 + len2); i++)
        arr1[i] = result[i];
    delete[] result;

}

template <class T>
void MergeSort(T* arr, int len)
{

    if (len <= 1)
        return;

    int mid = len / 2;

    MergeSort(arr, mid);
    MergeSort(arr + mid, len - mid);

    Merge<T>(arr, mid, arr + mid, len - mid);


}

int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1 };
    MergeSort<int>(arr, 9);
    for (int i = 0; i < 9; i++)
        std::cout << arr[i] << " ";

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
