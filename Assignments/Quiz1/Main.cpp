#include <iostream> //C++
#include <stdio.h> //C
#include <cstdlib> //rand()
#include <ctime> //time()
#include <vector> //vector
#include <algorithm> //find()
//#include <map> //map

using namespace std;

/*
The number of rows(M) and the number of columns(N) that makes the grid (MxN) are randomized.
The grid is a multidimensional array in which each cell has the value 0 or 1 stored randomly.
A cluster is made when at least two 1 are adjacent to each other and diagonal 1s are not considered part of a cluster.
The output shows the grid and the number of clusters in the grid.
*/


int main()
{
	cout << "Welcome to Downtown Techlandia !" << endl;
	cout << endl;

	//To avoid a repetitive sequence, we use srand() taking as parameter a seed value of type unsigned (positive) int
	//The "seed" is a starting point for the sequence and the guarantee is that if you start from the same seed you will get the same sequence of numbers.
	//That's why we use time() (current time) as seed (parameter of srand()) so the generated random number will always be different
	//The parameter of time() can be a null pointer, in which case the parameter is not used
	//But time() still returns a value of type time_t (current calendar time) with the result
	srand(time(nullptr)); //initialization of random seed

	//variables declaration
	int rows; 
	int columns;

	//declaration of the matrix (grid)
	int matrix[10][10]; //initialized with max rows = 10 and max columns = 10

	//initializing the number of rows/columns
	//choosing the number of indexes randomly (min = 1 and max = 10)
	rows = rand() % 10 + 1; 
	columns = rand() % 10 + 1;

	//display number of rows and columns
	cout << "Number of rows : " << rows << endl;
	cout << "Number of columns : " << columns << endl;
	cout << endl;

	cout << "Index"; //Display "Index" in the upper left corner of the grid

	for (int a = 0; a < columns; a++) //Display the index number for each column on the same row as "Index"
	{
		cout << "  [" << a << "]  "; // a = index number of the column
	}
	cout << endl; 
	cout << endl; //The grid starts officially on the next row 

	for (int i = 0; i < rows; i++) //Going through each row
	{
		cout << " [" << i << "] "; //For each row, we display the index number of the row before the column with index 0

		for (int j = 0; j < columns; j++) //Going throught each column of the current row
		{
			cout <<" | " << (matrix[i][j] = rand() % 2) << " | "; //Each column of the current row will have the number 0 or 1 displayed
		}
		cout << endl; //Going to the next row
	}

	int count{ 0 }; //number of '1'
	int total{ 0 }; //number of '1' belonging to a cluster

	int label[10][10]; //matrix copy
	int current{1}; //label to identify the '1' belonging to a cluster

	/*
	Maps are associative containers that store elements in a mapped fashion. 
	Each element has a key value and a mapped value. 
	In a map, the key values are generally used to sortand uniquely identify the elements, 
	while the mapped values store the content associated to this key.
	The types of keyand mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both
	*/
	/*map<int, int> firstscan; */

	for (int i = 0; i < rows; i++) //Going through each row
	{
		for (int j = 0; j < columns; j++) //Going throught each column of the current row
		{
			label[i][j] = matrix[i][j];
			if (matrix[i][j] == 1) //if there's a '1' stored there
			{
				if (((matrix[i - 1][j] == 1) || (matrix[i][j - 1] == 1) || (matrix[i + 1][j] == 1) || (matrix[i][j + 1] == 1)) && i >= 0 && i < rows && j >= 0 && j < columns) //if there's a '1' adjacent, it counts the cell once
				{
					if ((matrix[i][j-1] == 1) || (matrix[i-1][j] == 1)) //if there's a '1' on top or on the left, it counts the cell once
					{
						if (matrix[i - 1][j] == 1) //if there's a '1' on the left
						{
							label[i][j] = label[i - 1][j]; //current cell will have the same label as the cell on their left
						}
						else if (matrix[i][j - 1] == 1) //if there's a '1' on top
						{
							label[i][j] = label[i][j - 1]; //current cell will have the same label as the cell on top
						}

						//if ((matrix[i][j - 1] == 1) && (matrix[i - 1][j] == 1)) //if there's a '1' on top and on the left
						//{
						//	firstscan.insert(pair<int, int>(label[i][j - 1], label[i][j])); //Adds a new element to the map
						//}
					}
					else
					{
						label[i][j] = current; //put a label
						current++; //passing a different label next
					}

					total++; //number of '1' belonging to a cluster +1
				}
				else
				{
					label[i][j] = 0; //'1' with no neighbor is the same as 0
				}
				count++; //number of '1' present in the matrix +1
			}
		}
	}

	//After first scan
	for (int i = 0; i < rows; i++) //matrix copy where changes are visible
	{
		for (int j = 0; j < columns; j++)
		{
			cout << label[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] == 1) //if there's a '1' stored there
			{
				if (((matrix[i - 1][j] == 1) || (matrix[i][j - 1] == 1) || (matrix[i + 1][j] == 1) || (matrix[i][j + 1] == 1)) && i >= 0 && i < rows && j >= 0 && j < columns) //if there's a '1' adjacent, it counts the cell once
				{
					if ((matrix[i][j - 1] == 1) && (matrix[i - 1][j] == 1)) //if there's a '1' on top and on the left
					{
						//around current cell
						if (label[i][j - 1] < label[i - 1][j]) //left < up
						{
							/*int x = label[i - 1][j];
							int y = label[i][j - 1];*/
							label[i - 1][j] = label[i][j - 1]; //up = left
							/*for (int i = 0; i < rows; i++)
							{
								for (int j = 0; j < columns; j++)
								{
									if ((label[i][j] = x) && (label[i][j] != y) && (matrix[i][j] == 1) && (label[i][j] != 0))
									{
										x = y;
										label[i][j] = x;
									}
								}
							}*/
						}
						else if (label[i - 1][j] < label[i][j - 1]) //up < left
						{
							/*int x = label[i][j - 1];
							int y = label[i - 1][j];*/
							label[i][j - 1] = label[i - 1][j]; //left = up
							/*for (int i = 0; i < rows; i++)
							{
								for (int j = 0; j < columns; j++)
								{
									if ((label[i][j] = x) && (label[i][j] != y) && (matrix[i][j] == 1) && (label[i][j] != 0))
									{
										x = y;
										label[i][j] = x;
									}
								}
							}*/
						}

						//current cell
						if (label[i][j] < label[i - 1][j]) //current < up
						{
							label[i - 1][j] = label[i][j]; //up = current
						}
						else if (label[i][j] < label[i][j - 1]) //current < left
						{
							label[i][j - 1] = label[i][j]; //left = current
						}
						else if (label[i - 1][j] < label[i][j]) //up < current
						{
							label[i][j] = label[i - 1][j]; //current = up
						}
						else if (label[i][j - 1] < label[i][j]) //left < current
						{
							label[i][j] = label[i][j - 1]; //current = left
						}
					}
				}
			}
		}
	}

	

	//After second scan
	for (int i = 0; i < rows; i++) //matrix copy where changes are visible
	{
		for (int j = 0; j < columns; j++)
		{
			cout << label[i][j];
		}
		cout << endl;
	}
	cout << endl;

	vector<int> clusters{}; //To insert distinct number labels in the matrix
	for (int i = 0; i < rows; i++) //Counting the number of clusters
	{
		for (int j = 0; j < columns; j++)
		{
			if (label[i][j] != 0) //if the label isn't 0 aka if it's part of a cluster
			{
				if ((find(clusters.begin(), clusters.end(), label[i][j])) != clusters.end())
				{
					clusters.insert(clusters.begin(), label[i][j]);
				}
				
				/*
				The auto keyword specifies that the type of the variable that is begin declared will automatically be deduced from its initializer 
				and for functions if their return type is auto then that will be evaluated by return type expression at runtime.
				*/
				//for (auto nums : clusters) //foreach loop for elements in the vector
				//{
				//	if (element == nums) //if the number exist in the vector
				//	{
				//		same = true;
				//	}
				//	else if (element != nums) //if the number doesn't exist in the vector
				//	{
				//		clusters.push_back(element);
				//	}
				//}
			}
		}
	}

	for (int i = 0; i < rows; i++) //making sure the matrix didn't change
	{
		for (int j = 0; j < columns; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << count << endl; //number of '1'
	cout << total << endl; //number of '1' belonging to a cluster
	cout << int(clusters.size()) << endl; //number of elements aka clusters

	return 0;
}
