//#include <iostream> //C++
//#include <stdio.h> //C
//#include <cstdlib> //rand()
//#include <ctime> //time()
//#include <vector> //vector
//#include <string> // string

//using namespace std;

//struct CoordinatesR
//{
//	int downleftX;
//	int downleftY;
//	int uprightX;
//	int uprightY;
//};

//bool isOverlapping(vector<int>& r1, vector<int>& r2)
//{
//	if (r1[0] >= r2[2] || r2[0] >= r1[2] || r1[1] >= r2[3] || r2[1] >= r1[3])
//	{
//		return false;
//	}
//	return true;
//}
//
//int main()
//{
//	srand(time(nullptr)); //initialization of random seed
//
//	//string matrix[11][11]; // 0 to 10
//
//	vector<vector<int>> v;
//	/*int x1 = rand() % 11;
//	int y1 = rand() % 11;
//	int x2 = rand() % 11;
//	int y2 = rand() % 11;
//
//	while (x2 <= x1)
//	{
//		x2 = rand() % 11;
//	}
//
//	while (y2 <= y1)
//	{
//		y2 = rand() % 11;
//	}*/
//
//	//vector<vector<int>> v = { {1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4} }; //Test
//
//	if (isOverlapping(v[0], v[1]) || isOverlapping(v[1], v[2]) || isOverlapping(v[2], v[3]) || isOverlapping(v[3], v[0]) || isOverlapping(v[1], v[3]) || isOverlapping(v[2], v[0]) || isOverlapping(v[4], v[0]) || isOverlapping(v[1], v[4]) || isOverlapping(v[4], v[2]) || isOverlapping(v[4], v[3]))
//	{
//		cout << "False" << endl;
//	}
//	else
//	{
//		cout << "True" << endl;
//	}
//
//	//return same rectangle
//	for (auto r : v)
//	{
//		r.at(0) = rand() % 11;
//		r.at(1) = rand() % 11;
//		r.at(2) = rand() % 11;
//		r.at(3) = rand() % 11;
//
//		while (r.at(2) <= r.at(0))
//		{
//			r.at(2) = rand() % 11;
//		}
//
//		while (r.at(3) <= r.at(1))
//		{
//			r.at(3) = rand() % 11;
//		}
//
//		for (int m = 0; m < (r.at(3) - r.at(1)); m++)
//		{
//			for (int n = 0; n < (r.at(2) - r.at(0)); n++)
//			{
//				cout << "*";
//			}
//			cout << endl;
//		}
//		for (int k = 0; k < r.size(); k++)
//		{
//			cout << r.at(k);
//		}
//		cout << endl;
//		v.push_back(r);
//	}
//
//	
//
//	//for (int i = 0; i < 10; i++) //y
//	//{
//	//	for (int j = 0; j < 10; j++) //x
//	//	{
//	//		if (v[0].at(3) == i && v[0].at(1) == i && v[0].at(2) == j && v[0].at(0) == j)
//	//		{
//	//			for (int m = 0; m < (v[0].at(3) - v[0].at(1)); m++)
//	//			{
//	//				for (int n = 0; n < (v[0].at(2) - v[0].at(0)); n++)
//	//				{
//	//					cout << "*";
//	//				}
//	//			}
//	//		}
//	//		else
//	//		{
//	//			cout << "-";
//	//		}
//	//	}
//	//	cout << endl;
//	//}
//	
//
//	/*struct CoordinatesR r1 = { x1,y1,x2,y2 };
//	struct CoordinatesR r2 = { x1,y1,x2,y2 };
//	struct CoordinatesR r3 = { x1,y1,x2,y2 };
//	struct CoordinatesR r4 = { x1,y1,x2,y2 };
//	struct CoordinatesR r5 = { x1,y1,x2,y2 };
//	struct CoordinatesR r6 = { x1,y1,x2,y2 };
//	struct CoordinatesR r7 = { x1,y1,x2,y2 };
//	struct CoordinatesR r8 = { x1,y1,x2,y2 };
//	struct CoordinatesR r9 = { x1,y1,x2,y2 };
//	struct CoordinatesR r10 = { x1,y1,x2,y2 };
//	cout << "[" << r1.downleftX << ", " << r1.downleftY << ", " << r1.uprightX << ", " << r1.uprightY << "]" << endl;
//	cout << "[" << r2.downleftX << ", " << r2.downleftY << ", " << r2.uprightX << ", " << r2.uprightY << "]" << endl;
//	cout << "[" << r3.downleftX << ", " << r3.downleftY << ", " << r3.uprightX << ", " << r3.uprightY << "]" << endl;
//	cout << "[" << r4.downleftX << ", " << r4.downleftY << ", " << r4.uprightX << ", " << r4.uprightY << "]" << endl;
//	cout << "[" << r5.downleftX << ", " << r5.downleftY << ", " << r5.uprightX << ", " << r5.uprightY << "]" << endl;
//	cout << "[" << r6.downleftX << ", " << r6.downleftY << ", " << r6.uprightX << ", " << r6.uprightY << "]" << endl;
//	cout << "[" << r7.downleftX << ", " << r7.downleftY << ", " << r7.uprightX << ", " << r7.uprightY << "]" << endl;
//	cout << "[" << r8.downleftX << ", " << r8.downleftY << ", " << r8.uprightX << ", " << r8.uprightY << "]" << endl;
//	cout << "[" << r9.downleftX << ", " << r9.downleftY << ", " << r9.uprightX << ", " << r9.uprightY << "]" << endl;
//	cout << "[" << r10.downleftX << ", " << r10.downleftY << ", " << r10.uprightX << ", " << r10.uprightY << "]" << endl;*/
//
//	/*for (int j = 0; j < (r.uprightY - r.downleftY); j++)
//	{
//		for (int k = 0; k < (r.uprightX - r.downleftX); k++)
//		{
//			cout << "*";
//		}
//		cout << endl;
//	}*/
//
//	/*for (int j = 0; j < (r.uprightY - r.downleftY); j++)
//	{
//		for (int k = 0; k < (r.uprightX - r.downleftX); k++)
//		{
//			cout << (matrix[j][k] = "*");
//		}
//		cout << endl;
//	}*/
//
//
//
//
//	return 0;
//}

#include <iostream> //C++
#include <stdio.h> //C
#include <cstdlib> //rand()
#include <ctime> //time()
#include <vector> //vector
#include <string> // string


using namespace std;


struct CoordinatesR
{
    int downleftX;
    int downleftY;
    int uprightX;
    int uprightY;
};

bool isOverlapping(CoordinatesR& r1, CoordinatesR& r2)
{
	if (r1.downleftX >= r2.uprightX || r2.downleftX >= r1.uprightX || r1.downleftY >= r2.uprightY || r2.downleftY >= r1.uprightY)
	{
		return false;
	}
	return true;
}

int main()
{
    srand(time(nullptr)); //initialization of random seed

    vector<CoordinatesR> v;

    for (int i = 0; i < 10; i++)
    {
        int x1 = rand() % 11;
        int y1 = rand() % 11;
        int x2 = rand() % 11;
        int y2 = rand() % 11;

        while (x2 <= x1)
        {
            x2 = rand() % 11;
        }

        while (y2 <= y1)
        {
            y2 = rand() % 11;
        }

        struct CoordinatesR r = { x1,y1,x2,y2 };
        v.push_back(r);
        cout << "[" << r.downleftX << ", " << r.downleftY << ", " << r.uprightX << ", " << r.uprightY << "]" << endl;
        //int rows = (r.uprightY - r.downleftY);
        //int columns = (r.uprightX - r.downleftX);
        ///*string matrix[11][11];*/

        //for (int j = 0; j < 10; j++)
        //{
        //    for (int k = 0; k < 10; k++)
        //    {
        //        if ((j <= r.downleftY || j >= rows) || (k <= r.downleftX || k >= columns))
        //        {
        //            cout << "-";
        //        }
        //        else
        //        {
        //            cout << "*";
        //        }
        //    }
        //    cout << endl;
        //}
        for (int j = 0; j < (r.uprightY - r.downleftY); j++)
        {
            for (int k = 0; k < (r.uprightX - r.downleftX); k++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    /*for (auto rec : v)
    {
        cout << "[" << rec.downleftX << ", " << rec.downleftY << ", " << rec.uprightX << ", " << rec.uprightY << "]" << endl;
    }*/


    return 0;
}