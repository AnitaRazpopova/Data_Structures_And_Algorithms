// CountingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


void CountSort(int* arr, int len)
{
	int* countArr = new int[5];
	for (int i = 0; i < 5; i++) {
		countArr[i] = 0;
	}
		

	for (int i = 0; i < len; i++) {
		countArr[arr[i]- 2]++;
	}
		

	for (int i = 1; i < 5; i++) {
		countArr[i] += countArr[i - 1];
	}
		

	int* result = new int[len];
	for (int i = 0; i < len; i++)
	{
		int currentStudent = arr[i];
		int index = countArr[currentStudent - 2]--;
		result[index - 1] = currentStudent;
	}
	for (int i = 0; i < len; i++) {
		arr[i] = result[i];
	}
		
	delete[] result;

}

int main()
{
	int arr[] = {4, 6, 4, 5, 5 };

	CountSort(arr, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr[i]<< endl;
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
