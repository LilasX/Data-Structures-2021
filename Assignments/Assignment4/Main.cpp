//#include <iostream> //C++
//#include <stdio.h> //C
//
//using namespace std;
//
///*
//A password is considered strong if the below conditions are all met:
//It has at least 6 characters and at most 20 characters.
//It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
//It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
//Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
//In one step, you can:
//Insert one character to password,
//Delete one character from password, or
//Replace one character of password with another character.
//
//Example 1:
//Input: password = "a"
//Output: 5
//Example 2:
//Input: password = "aA1"
//Output: 3
//Example 3:
//Input: password = "1337C0d3"
//Output: 0
//*/
//
//
//int main()
//{
//
//
//
//
//
//
//	return 0;
//}


#include<iostream>
#include<vector>

using namespace std;

//function headers
bool HasDigit(vector<char>& pw);
bool HasUpper(vector<char>& pw);
bool HasLower(vector<char>& pw);
bool NbOfChar(vector<char>& pw);
bool HasConsecutiveThree(vector<char>& pw);
void Count(vector<char>& pw, int& count);
bool HaveAll(vector<char>& pw);
bool HaveTwo(vector<char>& pw);
bool HaveOne(vector<char>& pw);

int main()
{

	string pwInput;
	int count = 0;

	cout << "Choose a password between 6 and 20 characters that contains at least :\n- 1 lowercase\n- 1 uppercase\n- 1 digit\nConsecutive same three characters are not allowed\n\n";
	cout << "Enter desired password :\n";
	cin >> pwInput;
	vector<char> pw(pwInput.begin(), pwInput.end());

	cout << "\nDesired password is : [ ";

	for (const char& c : pw)
	{		//print the vector
		cout << c;
	}
	cout << " ]\n\n";

	//output to confirm if its reading properly
	cout << "The password contains a digit : " << boolalpha << HasDigit(pw) << endl;
	cout << "The password contains a lowercase : " << boolalpha << HasLower(pw) << endl;
	cout << "The password contains an uppercase : " << boolalpha << HasUpper(pw) << endl;
	cout << "The password contains the right amount of characters : " << boolalpha << NbOfChar(pw) << endl;
	cout << "The password contains three same consecutive characters : " << boolalpha << HasConsecutiveThree(pw) << endl;

	Count(pw, count);

	cout << "\nYou can do " << count << " action(s) to improve your password\n";

	return 0;
}

//~~~~~~~~~~~~~~~~~ Functions ~~~~~~~~~~~~~~~~~

bool HasDigit(vector<char>& pw)
{	//checks for number

	for (int i = 0; i < pw.size(); i++)
	{
		if (isdigit(pw[i]))
		{
			return true;
		}
	}
	return false;
}
bool HasUpper(vector<char>& pw)
{	//checks for uppercase

	for (int i = 0; i < pw.size(); i++)
	{
		if (isupper(pw[i]))
		{
			return true;
		}
	}
	return false;
}
bool HasLower(vector<char>& pw)
{	//checks for lowercase

	for (int i = 0; i < pw.size(); i++)
	{
		if (islower(pw[i]))
		{
			return true;
		}
	}
	return false;
}
bool HasConsecutiveThree(vector<char>& pw)
{	//checks for 3 consecutive characters
	for (int i = 2; i < pw.size(); i++)
	{
		if (pw[i] == pw[i - 1] && pw[i] == pw[i - 2])
		{
			return true;
		}
	}
	return false;
}
bool NbOfChar(vector<char>& pw)
{	//checks for right amount of characters
	if (pw.size() >= 6 && pw.size() <= 20)
	{
		return true;
	}
	return false;
}
void Count(vector<char>& pw, int& count)
{

	if (pw.size() <= 4)		//count for 4 or less chars *TESTED*
	{
		count += (6 - pw.size());
		if (HasConsecutiveThree(pw))
		{
			count++;
		}
	}
	else if (pw.size() == 5)	//count for 5 chars
	{
		if (!HasConsecutiveThree(pw) && HaveOne(pw) ||
			HasConsecutiveThree(pw) && HaveTwo(pw) ||
			HasConsecutiveThree(pw) && HaveOne(pw) ||
			HasConsecutiveThree(pw) && HaveAll(pw))
		{
			count += 2;
		}
		if (!HasConsecutiveThree(pw) && HaveTwo(pw))
		{
			count++;
		}
	}
	else if (pw.size() >= 6 && pw.size() <= 20)		//count for right amount of char
	{
		if (HasConsecutiveThree(pw) && HaveAll(pw))
		{
			count++;
		}
		if (HaveTwo(pw))
		{
			count++;
		}
		if (HaveOne(pw))
		{
			count += 2;
		}
	}
	else if (pw.size() > 20)	//if pw is over 20
	{
		if (HaveAll(pw))
		{
			count += (pw.size() - 20);
		}
		if (HaveTwo(pw))
		{
			count += (pw.size() - 19);
		}
		if (HaveOne(pw))
		{
			count += (pw.size() - 18);
		}
	}
}
bool HaveAll(vector<char>& pw)
{	//has all required characters
	if (HasDigit(pw) && HasLower(pw) && HasUpper(pw))
	{
		return true;
	}
	return false;
}
bool HaveTwo(vector<char>& pw)
{	//has 2 required characters
	if (HasDigit(pw) && HasLower(pw) && !HasUpper(pw) ||
		HasDigit(pw) && !HasLower(pw) && HasUpper(pw) ||
		!HasDigit(pw) && HasLower(pw) && HasUpper(pw))
	{
		return true;
	}
	return false;
}
bool HaveOne(vector<char>& pw)
{	//has 1 required characters
	if (HasDigit(pw) && !HasLower(pw) && !HasUpper(pw) ||
		!HasDigit(pw) && !HasLower(pw) && HasUpper(pw) ||
		!HasDigit(pw) && HasLower(pw) && !HasUpper(pw))
	{
		return true;
	}
	return false;
}