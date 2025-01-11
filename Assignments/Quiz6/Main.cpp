#include <iostream> //C++
#include <stdio.h> //C
#include <array>
#include <string>

using namespace std;

/*
Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order.
Since the answer may not fit in an integer data type, return the answer as a string.
If there is no answer return an empty string.

Example 1:
Input: digits = [8,1,9]
Output: "981"
Example 2:
Input: digits = [8,6,7,1,0]
Output: "8760"
Example 3:
Input: digits = [1]
Output: ""
Example 4:
Input: digits = [0,0,0,0,0,0]
Output: "0"
*/

/*
Usually if the sum of the numbers making the int is divisible by 3, then the int should be able to be divided by 3
- Making sure that the sum of the numbers in the array is divisible by 3, if so sort the array to the biggest number to the smallest
*/

int getSumArray(int arr[], int n)
{
	int sum = 0;

	cout << "Input : digits = [ ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<< " ";
		sum += arr[i];
	}
	cout << "]" << endl;

	return sum;
}

void sortArraySmall(int arr[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void sortArrayBig(int arr[], int n)
{
	int max;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
}

void largestMultipleof3(int arr[], int n)
{
	int sum = getSumArray(arr, n);
	int remainder = sum % 3;
	int number = 0;
	int positionN = 0;
	bool haveZero = false;
	bool TwoR = false;
	int number2 = 0;
	int positionN2 = 0;

	if (sum < 3)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
			{
				haveZero = true;
				cout << "Largest multiple of 3 = 0" << endl;
				break;
			}
		}

		if (!haveZero)
		{
			cout << "Largest multiple of 3 = \"\"" << endl;
		}
	}
	else if (remainder == 0)
	{
		sortArrayBig(arr, n);
		cout << "[ ";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "]" << endl;
	}
	else if (remainder == 1)
	{
		sortArraySmall(arr, n);
		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 3 == 1)
			{
				number = arr[i];
				positionN = i;
				break;
			}
		}

		for (int i = positionN; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		sortArrayBig(arr, n - 1);
		cout << "Largest multiple of 3 = [ ";
		for (int i = 0; i < n - 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "]" << endl;
	}
	else if (remainder == 2)
	{
		sortArraySmall(arr, n);
		for (int i = 0; i < n; i++)
		{
			if (arr[i] % 3 == 2)
			{
				TwoR = true;
				number = arr[i];
				positionN = i;
				break;
			}
		}

		if (TwoR)
		{
			for (int i = positionN; i < n - 1; i++)
			{
				arr[i] = arr[i + 1];
			}

			sortArrayBig(arr, n - 1);
			cout << "Largest multiple of 3 = [ ";
			for (int i = 0; i < n - 1; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "]" << endl;
		}
		else if (!TwoR)
		{
			for (int i = 0; i < n; i++)
			{
				if (arr[i] % 3 == 1)
				{
					number = arr[i];
					positionN = i;
					break;
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (arr[i] % 3 == 1)
				{
					number2 = arr[i];
					positionN2 = i;
					break;
				}
			}

			for (int i = positionN; i < n - 1; i++)
			{
				arr[i] = arr[i + 1];
			}

			for (int i = positionN2; i < n - 2; i++)
			{
				arr[i] = arr[i + 1];
			}

			sortArrayBig(arr, n - 2);
			cout << "Largest multiple of 3 = [ ";
			for (int i = 0; i < n - 2; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "]" << endl;
		}
	}
}

int main()
{
	//int arr[] = { 8,1,9 }; //no remainder
	//int arr[] = { 8,6,7,1,0 }; //remainder 1
	//int arr[] = { 5,5,1,4,2,6 }; //remainder 2
	//int arr[] = { 4,4,1,1,1,3 }; //remainder 2 but no remainder 2 in the array
	//int arr[] = { 1 }; //sum < 3
	//int arr[] = { 0,0,0,0,0,0 }; //there's 0

	string str;
	cout << "Enter integers from 0 to 9 in the array : " << endl;
	getline(cin, str);
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
	int size = str.size();
	int arr[20];
	for (int i = 0; i < size; i++)
	{
		arr[i] = (int)str[i] - '0';
	}

	largestMultipleof3(arr, size);

	return 0;
}