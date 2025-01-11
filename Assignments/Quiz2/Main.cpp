#include <iostream> //C++
#include <stdio.h> //C

using namespace std;

/*
Imagine a relation between 2 numbers in such :
the sum of factors including 1 (but not the number itself) of one number
is equal to the other number and vice versa.
for example, (220,284) have such a relation. the factors of 220 are
1,2,4,5,10,11,20,22,44,55, and 110 whose sum equals 284. the factors of 284
are 1,2,4,71,142 whose sum equals 220.

Write a function checkRelation which you call from main() and checks
whether a pair of numbers entered has this relation or has not. Display
the factors of each number to confirm your answer.
*/

void checkRelation(int x, int y) //passing two int as parameters
{
	int i; //factors of 'x'
	int j; //factors of 'y'
	int sumx{ 0 }; //the sum of all factors of number 'x'
	int sumy{ 0 }; //the sum of all factors of number 'y'

	cout << "Factors of " << x << " : ";
	for (i = 1; i < x; i++) //starting at 1 because the factor can't be 0 and it can't be bigger than the number itself
	{
		if (x % i == 0) //using modulo to determine the remainder of number 'x' divide by 'i', if the remainder is 0, it means that 'i' is a factor of 'x'
		{
			cout << i << " "; //display the factors of 'x'
			sumx += i; //add i to the sum of all factors of number 'x'
		}
	}

	cout << endl << endl;

	cout << "Factors of " << y << " : ";
	for (j = 1; j < y; j++) //starting at 1 because the factor can't be 0 and it can't be bigger than the number itself
	{
		if (y % j == 0) //using modulo to determine the remainder of number 'y' divide by 'j', if the remainder is 0, it means that 'j' is a factor of 'y'
		{
			cout << j << " "; //display the factors of 'y'
			sumy += j; //add j to the sum of all factors of number 'y'
		}
	}

	cout << endl << endl;

	if (sumx == y && sumy == x) //if the sum of all factors of 'x' is equal to 'y' and vice-versa
	{
		cout << x << " and " << y << " are a match ! " << endl << endl;
	}
	else
	{
		cout << x << " and " << y << " are not a match !" << endl << endl;
	}
}

int main()
{
	int first{ 0 }; 
	int second{ 0 };

	cout << "Enter the first integer : ";
	cin >> first;
	cout << endl << endl;

	cout << "Enter the second integer : ";
	cin >> second;
	cout << endl << endl;

	checkRelation(first,second); //passing the two integers entered by user as arguments

	return 0;
}