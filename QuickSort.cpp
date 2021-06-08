// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
int Partition(T* arr, int len)
{

	T pivot = arr[len / 2];
	int i = 0, j = len - 1;

	while (true)
	{
		while (arr[j] > pivot)
			j--;

		while (arr[i] < pivot)
			i++;

		if (i < j)
			std::swap(arr[i], arr[j]);
		else
			return j;
	}
}


template <typename T>
void QuickSort(T* arr, int len)
{
	if (len <= 1)
		return;

	int pivotIndex = Partition(arr, len);
	QuickSort(arr, pivotIndex);
	QuickSort(arr + pivotIndex, len - pivotIndex - 1);
}
// Best case: T(n) = 2T(n/2) + n
// Worst case : T(n) = T(n-1) + n;
int main()
{
	int arr1[] = { 10,9,8,7,6,5,4,3,2,1 };
	QuickSort(arr1, 10);

	for (int i = 0; i < 10; i++)
		cout << arr1[i] << " ";
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
