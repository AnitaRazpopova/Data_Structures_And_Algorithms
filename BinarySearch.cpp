// BinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int* arr, int x, int start, int end) {
	/*if (start > end) {
		return false;
	}*/
	int middle = (end + start) / 2;
	if (arr[middle] == x) {
		return true;
	}
	else if (arr[middle] > x) {
		return binary_search(arr, x, start, middle - 1);
	}
	else if (arr[middle] < x) {
		return binary_search(arr, x, middle + 1, end);
	}
}


int main()
{
	int arr[10];
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	//sort(arr, arr + 10);

	cout << binary_search(arr, n, arr[0], arr[9]);
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
