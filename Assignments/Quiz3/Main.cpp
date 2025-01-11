#include <iostream> //C++
#include <stdio.h> //C
#include <cstdlib> //rand()
#include <ctime> //time()

using namespace std;

/*
use random to produce two positive one-digit integers. the program should
then prompt the user with a question, such as:
how much is 6 times 7?
the user then inputs the answer. the program checks the user's answer. if
it's correct, display the message "very good" and ask another multiplication
question. if the answer is wrong, display the message "No. try again" and
let the user try THE SAME QUESTION repeatedly until the user gets it
right ! a separate method should be used to generate each new question.
this method should be called once when the app begins execution and each time
the user answers the question correctly.
*/



void generateQ(int& a, int& b, int& result, int& c) 
{
	a = (rand() % 9) + 1; //random number from 1 to 9
	b = (rand() % 9) + 1; //random number from 1 to 9
	result = a * b;
	cout << "What is the result of " << a << " times " << b << " ? ";
	cin >> c;
}

int main()
{
	srand(time(nullptr)); //initialization of random seed
	int a{ 0 };
	int b{ 0 };
	int c{ 0 };
	int result{ 0 };
	

	generateQ(a, b, result, c);

	if (c == result)
	{
		while (c == result)
		{
			cout << "Very good !" << endl << endl;;
			generateQ(a, b, result, c);
			while (c != result)
			{
				cout << "No, try again..." << endl << endl;
				cout << "What is the result of " << a << " times " << b << " ? ";
				cin >> c;

			}
		}
	}
	else
	{
		while (c != result)
		{
			cout << "No, try again..." << endl << endl;
			cout << "What is the result of " << a << " times " << b << " ? ";
			cin >> c;
			while (c == result)
			{
				cout << "Very good !" << endl << endl;
				generateQ(a, b, result, c);
			}
		}
	}

	return 0;
}