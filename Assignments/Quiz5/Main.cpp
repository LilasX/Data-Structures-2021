#include <iostream> //C++
#include <stdio.h> //C
#include <string>

using namespace std;

/*
ex1)

Mark and John are trying to compare their BMI (Body Mass Index),
which is calculated using the formula:
 BMI = mass / height^2 = mass / (height * height).
 (mass in kg and height in meter).

1. Store Mark's and John's mass and height in variables
2. Calculate both their BMIs
3. Create a boolean variable containing information about whether Mark has a higher BMI than John.
4. Print a string to the console
containing the variable from step 3. (Something like "Is Mark's BMI higher than John's? true").

ex2)
John and Mike both play basketball in different teams. In the latest 3 games,
  John's team scored 89, 120 and 103 points, while Mike's team scored 116, 94 and
   123 points.
1. Calculate the average score for each team
2. Decide which teams wins in average (highest average score),
and print the winner to the console.
Also include the average score in the output.
3. Then change the scores to show different winners.
Don't forget to take into account there might be a draw (the same average score)
4. Mary also plays basketball, and her team scored 97, 134 and 105 points.
Like before, log the average winner to the console.

5. Like before, change the scores to generate different winners,
   keeping in mind there might be draws.

ex3)
John and his family went on a holiday and went to 3 different
restaurants. The bills were $124, $48 and $268.
To tip the waiter a fair amount, John created a simple tip calculator (as a
function). He likes to tip 20% of the bill when the bill is less than $50,
15% when the bill is between $50 and $200, and 10% if the bill is more
than $200.
In the end, John would like to have 2 arrays:
1) Containing all three tips (one for each bill)
2) Containing all three final paid amounts (bill + tip).
(NOTE: To calculate 20% of a value, simply multiply it with 20/100 = 0.2)

ex4)

Mark and John compared their BMIs. Now implement the same functionality with objects and methods.

1. For each of them, create an object with properties for their full name, mass, and height
2. Then, add a method to each object to calculate the BMI. Save the BMI to the object and also return it from the method.
3. In the end, log to the console who has the highest BMI, together with the full name and the respective BMI. Don't forget they might have the same BMI.
Remember: BMI = mass / height^2 = mass / (height * height). (mass in kg and height in meter).

ex 5)

create a class called Auto.
give the Auto class a constructor that defines
properties for model and cylinder.
create get methods for each of the properties.
create methods that start the engine, accelerate the car
and break the car. have the methods return a string
that shows the method was called.
create classes for 3 cars of your choice.
Override the start, accelerate, and break methods.
create an output that will show the car's name, model,
and action called

*/




//Example 3
//void TipsCalculator(float &a, float &b)
//{
//	if (a < 50)
//	{
//		b = (a * 0.2 + a);
//	}
//	else if (a >= 50 && a <= 200)
//	{
//		b = (a * 0.15 + a);
//	}
//	else if (a > 200)
//	{
//		b = (a * 0.1 + a);
//	}
//}

//Example 4
//struct MarkBMI
//{
//	string name = "Mark";
//	float mass = 60;
//	float height = 1.78;
//
//	int BMIM()
//	{
//		return mass / (height * height);
//	}
//};
//
//struct JohnBMI
//{
//	string name = "John";
//	float mass = 63;
//	float height = 1.8;
//
//	int BMIJ()
//	{
//		return mass / (height * height);
//	}
//};

//Example 5
class Auto
{
private:
	string model;
	int cylinders;

public:
	Auto(string name, int number)
	{
		this->model = name;
		this->cylinders = number;
	}

	string getModel()
	{
		return this->model;
	}

	int getCylinders()
	{
		return this->cylinders;
	}

	virtual void startEngine()
	{
		cout << "startEngine was called !" << endl;
	}

	virtual void accelerate()
	{
		cout << "accelerate was called !" << endl;
	}

	virtual void breakCar()
	{
		cout << "breakCar was called !" << endl;
	}
};

class Toyota : public Auto
{
public:
	Toyota(string name, int number) : Auto(name, number)
	{

	}

	void startEngine() override
	{
		cout << "startEngine has been called from Toyota !" << endl;
	}

	void accelerate() override
	{
		cout << "accelerate has been called from Toyota !" << endl;
	}

	void breakCar() override
	{
		cout << "breakCar has been called from Toyota !" << endl;
	}
};

class BMW : public Auto
{
public:
	BMW(string name, int number) : Auto(name, number)
	{

	}

	void startEngine() override
	{
		cout << "startEngine has been called from BMW !" << endl;
	}

	void accelerate() override
	{
		cout << "accelerate has been called from BMW !" << endl;
	}

	void breakCar() override
	{
		cout << "breakCar has been called from BMW !" << endl;
	}
};

class Subaru : public Auto
{
public:
	Subaru(string name, int number) : Auto(name, number)
	{

	}

	void startEngine() override
	{
		cout << "startEngine has been called from Subaru !" << endl;
	}

	void accelerate() override
	{
		cout << "accelerate has been called from Subaru !" << endl;
	}

	void breakCar() override
	{
		cout << "breakCar has been called from Subaru !" << endl;
	}
};

int main()
{
	//Example 1
	/*float massM = 60;
	float massJ = 63;
	float heightM = 1.78;
	float heightJ = 1.8;
	float bmiM = massM / (heightM * heightM);
	float bmiJ = massJ / (heightJ * heightJ);
	bool bmi = false;

	cout << "Mark's BMI = " << bmiM << endl;
	cout << "John's BMI = " << bmiJ << endl;

	if (bmiM > bmiJ)
	{
		bmi = true;
		cout << "Is Mark's BMI higher than John's ? " << boolalpha << bmi << endl;
	}
	else
	{
		cout << "Is Mark's BMI higher than John's ? " << boolalpha << bmi << endl;
	}*/

	//Example 2
	/*int scoreM1 = 116;
	int scoreM2 = 94;
	int scoreM3 = 123;

	int scoreJ1 = 89;
	int scoreJ2 = 120;
	int scoreJ3 = 103;

	int scoreMa1 = 97;
	int scoreMa2 = 134;
	int scoreMa3 = 105;

	float averageM = (scoreM1 + scoreM2 + scoreM3) / 3;
	float averageJ = (scoreJ1 + scoreJ2 + scoreJ3) / 3;
	float averageMa = (scoreMa1 + scoreMa2 + scoreMa3) / 3;

	cout << "Average score of Mike's team : " << averageM << endl;
	cout << "Average score of John's team : " << averageJ << endl;
	cout << "Average score of Mary's team : " << averageMa << endl;

	if (averageJ > averageM && averageJ > averageMa)
	{
		cout << "John's team won !" << endl;
	}
	else if (averageMa > averageJ && averageMa > averageM)
	{
		cout << "Mary's team won !" << endl;
	}
	else if(averageM > averageJ && averageM > averageMa)
	{
		cout << "Mike's team won !" << endl;
	}
	else
	{
		cout << "There's a tie !" << endl;
	}*/

	//Example 3
	/*float bills[] = { 124,48,268 };
	float billsT[3];

	for (int i = 0; i < 3; i++)
	{
		TipsCalculator(bills[i], billsT[i]);

		cout << billsT[i] << endl;
	}*/

	//Example 4
	/*struct MarkBMI m;
	struct JohnBMI j;

	if (m.BMIM() > j.BMIJ())
	{
		cout << m.name << " has the highest BMI with a mass of " << m.mass << "kg and a height of " << m.height << "m !" << endl;
	}
	else if(m.BMIM() < j.BMIJ())
	{
		cout << j.name << " has the highest BMI with a mass of " << j.mass << "kg and a height of " << j.height << "m !" << endl;
	}
	else
	{
		cout << m.name << " with a mass of " << m.mass << "kg and a height of " << m.height << "m has the same BMI as " << j.name << " with a mass of " << j.mass << "kg and a height of " << j.height << "m !" << endl;
	}*/

	//Example 5
	Auto a = { "Auto", 6 };
	a.accelerate();
	
	Toyota car1 = { "Toyota", 4 };
	car1.accelerate();
	cout << car1.getModel();
	
	BMW car2 = { "Toyota", 6 };
	car2.breakCar();
	
	Subaru car3 = { "Subaru", 6 };
	car3.startEngine();

	return 0;
}