#include <iostream> //C++
#include <stdio.h> //C
#include <cstdlib> //rand()
#include <ctime> //time()
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
There are n workers numbered from 1 to n and two arrays: speed and efficiency, where speed[i] and efficiency[i] represent the speed and efficiency for the i-th worker respectively. Display both arrays and Return the maximum performance of a team composed of at most k workers.
n is randomly chosen from 1 to 10. Then each array is randomly filled from 1 to 10.
k is chosen by the user.
The performance of a team is the sum of their workers' speeds multiplied by the minimum efficiency among their workers.

Example 1:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation:
We have the maximum performance of the team by selecting worker 2 (with speed=10 and efficiency=4) and worker 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
Example 2:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select worker 1, worker 2 and worker 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
Example 3:
Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72
*/



int main()
{
	srand(time(nullptr)); //initialization of random seed

	int n = rand() % 10 + 1;
	/*int n = 6;
	int speed[] = { 2,10,3,1,5,8 };
	int efficiency[] = { 5,4,3,9,7,2 };

	cout << "Input : n = " << n << endl;*/

	vector<pair<int, int>> workers;
	int speed[10];
	int efficiency[10];

	cout << "speed = [ ";
	for (int i = 0; i < n; i++)
	{
		speed[i] = rand() % 10 + 1;
		cout << speed[i] << " ";
	}
	cout << "]" << endl;

	cout << "efficiency = [ ";
	for (int i = 0; i < n; i++)
	{
		efficiency[i] = rand() % 10 + 1;
		cout << efficiency[i] << " ";
	}
	cout << "]" << endl;

	for (int i = 0; i < n; i++)
	{
		workers.push_back(make_pair(efficiency[i], speed[i]));
	}

	sort(workers.rbegin(), workers.rend()); //reverse iterators to sort efficiency in descending order

	cout << "Sorted s = [ ";
	for (int i = 0; i < n; i++)
	{
		cout << workers[i].second << " ";
	}
	cout << "]" << endl;

	cout << "Sorted e = [ ";
	for (int i = 0; i < n; i++)
	{
		cout << workers[i].first << " ";
	}
	cout << "]" << endl;	

	int k;
	cout << "Enter k (Must not be superior to n): ";
	cin >> k;
	cout << endl;
	
	int sumOfSpeed = 0;
	int currentMaxPerformance = 0;
	priority_queue<int>q; //FIFO, first element always the largest

	for (int i = 0; i < n; i++)
	{
		//go through each workers and test if the currentMaxPerformance will be superior than the previous one, if not, keep the current one
		sumOfSpeed += workers[i].second; //adding up speed of workers from the highest efficiency to lowest
		//cout << "Sum after passing " << i+1 << " workers = " << sumOfSpeed << endl;
		if (currentMaxPerformance > sumOfSpeed * workers[i].first) //save the max performance only
		{
			currentMaxPerformance = currentMaxPerformance;
		}
		else
		{
			currentMaxPerformance = sumOfSpeed * workers[i].first;
		}
		//cout << "CurrentMaxPerformance after passing " << i + 1 << " workers = " << currentMaxPerformance << endl << endl;

		q.push(-workers[i].second); //in negative to remove the speed from the sumOfSpeed
		
		if (q.size() == k)
		{
			sumOfSpeed += q.top(); 
			//cout << "Current top() = " << q.top() << endl;
			//cout << "Sum after adding top() passing " << i + 1 << " workers = " << sumOfSpeed << endl;
			q.pop(); //remove top(), reminder smallest negative is the bigger number
			//cout << "top() after pop() = " << q.top() << endl << endl;
		}
	}
	cout << endl;

	cout << "Max performance of a team of " << k << " members from the workers available = " << currentMaxPerformance << endl;

	return 0;
}