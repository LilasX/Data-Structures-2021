#include <iostream> //C++
#include <stdio.h> //C
#include <cmath> //absolute value
#include <cstdlib> //rand()
#include <ctime> //time()

using namespace std;

/*
Part I) Write an inheritance hierarchy for classes Quadrilateral, Trapezoid,
Parallelogram, rectangle and Square. use Quadrilateral as the base
class of the hierarchy. Make the hierarchy as deep (many levels)
as possible. Specify the instance variables, properties and methods
for each class. The  instance variables of Quadrilateral
should be the x-y coordinate pairs for the four endpoints of the
Quadrilateral. Write an app that instantiates objects of your classes
and outputs each object's area and perimeter.

Part II) Modify Part I by Adding a method Draw
which takes the coordinate pairs of each objects and outputs
the shape of it on the Console.(note: use '*' to draw the shape).


Example: Draw a Rectangle

*******
*     *
*     *
*     *
*******
*/

class Coordinates
{
private:
	int x;
	int y;

public:
	//constructor
	Coordinates(int Cx, int Cy)
	{
		x = Cx;
		y = Cy;
	}

	Coordinates() {}

	//accessors
	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}
};

class Quadrilateral
{
private:
	Coordinates upleft;
	Coordinates upright;
	Coordinates downleft;
	Coordinates downright;

public:
	//constructor
	Quadrilateral(int ulx, int uly, int urx, int ury, int dlx, int dly, int drx, int dry)
	{
		upleft = Coordinates(ulx, uly);
		upright = Coordinates(urx, ury);
		downleft = Coordinates(dlx, dly);
		downright = Coordinates(drx, dry);
	}

	//accessors
	Coordinates getUL()
	{
		return upleft;
	}

	Coordinates getUR()
	{
		return upright;
	}

	Coordinates getDL()
	{
		return downleft;
	}

	Coordinates getDR()
	{
		return downright;
	}
};

class Trapezoid : public Quadrilateral
{
public:

	Trapezoid(int ulx, int uly, int urx, int ury, int dlx, int dly, int drx, int dry) : Quadrilateral(ulx, uly, urx, ury, dlx, dly, drx, dry)
	{
		
	}

	int getHeightT()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY()) //vertical height
		{
			return abs(getUL().getY() - getDL().getY());
		}
		else if (getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX()) //horizontal height
		{
			return abs(getUL().getX() - getUR().getX());
		}
		else
		{
			cout << "This quadrilateral is not a trapezoid, cannot get its height." << endl;
		}
	}

	int getAreaT() //need double for precision
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY()) //horizontal parallel
		{
			return (abs(getUL().getX() - getUR().getX()) + abs(getDL().getX() - getDR().getX())) * getHeightT() / 2;
		}
		else if (getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX()) //vertical parallel
		{
			return (abs(getUL().getY() - getDL().getY()) + abs(getDR().getY() - getUR().getY())) * getHeightT() / 2;
		}
		else
		{
			cout << "This quadrilateral is not a trapezoid, cannot get its area." << endl;
		}
	}

	int getPerimeterT() //need double for precision
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY()) //horizontal parallel
		{
			if (getUL().getX() == getDL().getX() && getUR().getX() != getDR().getX()) //left side straight
			{
				return abs(getUL().getX() - getUR().getX()) + abs(getDL().getX() - getDR().getX()) + abs(getUL().getY() - getDL().getY()) + pow(pow(getHeightT(), 2) + pow(abs(getUR().getX() - getDR().getX()), 2), 0.5);
			}
			else if (getUR().getX() == getDR().getX() && getUL().getX() != getDL().getX()) //right side straight
			{
				return abs(getUL().getX() - getUR().getX()) + abs(getDL().getX() - getDR().getX()) + abs(getUR().getY() - getDR().getY()) + pow(pow(getHeightT(), 2) + pow(abs(getUL().getX() - getDL().getX()), 2), 0.5);
			}
			else //no straight side
			{
				return abs(getUL().getX() - getUR().getX()) + abs(getDL().getX() - getDR().getX()) + pow(pow(getHeightT(), 2) + pow(abs(getUL().getX() - getDL().getX()), 2), 0.5) + pow(pow(getHeightT(), 2) + pow(abs(getUR().getX() - getDR().getX()), 2), 0.5);
			}
			
		}
		else if (getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX()) //vertical parallel
		{
			if (getUL().getY() == getUR().getY() && getDL().getY() != getDR().getY()) //up straight
			{
				return abs(getUL().getY() - getDL().getY()) + abs(getUR().getY() - getDR().getY()) + abs(getUL().getX() - getUR().getX()) + pow(pow(getHeightT(), 2) + pow(abs(getDL().getY() - getDR().getY()), 2), 0.5);
			}
			else if (getUL().getY() != getUR().getY() && getDL().getY() == getDR().getY()) //down straight
			{
				return abs(getUL().getY() - getDL().getY()) + abs(getUR().getY() - getDR().getY()) + abs(getDL().getX() - getDR().getX()) + pow(pow(getHeightT(), 2) + pow(abs(getUL().getY() - getUR().getY()), 2), 0.5);
			}
			else //no straight side
			{
				return abs(getUL().getY() - getDL().getY()) + abs(getUR().getY() - getDR().getY()) + abs(getDL().getX() - getDR().getX()) + pow(pow(getHeightT(), 2) + pow(abs(getUL().getY() - getUR().getY()), 2), 0.5) + pow(pow(getHeightT(), 2) + pow(abs(getDL().getY() - getDR().getY()), 2), 0.5);
			}
		}
		else
		{
			cout << "This quadrilateral is not a trapezoid, cannot get its perimeter." << endl;
		}
	}
};

class Parallelogram : public Trapezoid
{
public:
	Parallelogram(int ulx, int uly, int urx, int ury, int dlx, int dly, int drx, int dry) : Trapezoid(ulx, uly, urx, ury, dlx, dly, drx, dry)
	{

	}

	int getHeightP()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && abs(getUL().getX() - getDL().getX()) == abs(getUR().getX() - getDR().getX()))
		{
			return abs(getUL().getY() - getDL().getY());
		}
		else
		{
			cout << "This quadrilateral is not a parallelogram, cannot get its height." << endl;
		}
	}

	int getAreaP()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && abs(getUL().getX() - getDL().getX()) == abs(getUR().getX() - getDR().getX()))
		{
			return (abs(getUL().getY() - getDL().getY()) * abs(getDL().getX() - getDR().getX()));
		}
		else
		{
			cout << "This quadrilateral is not a parallelogram, cannot get its area." << endl;
		}
	}

	int getPerimeterP() //need double for precision
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && abs(getUL().getX() - getDL().getX()) == abs(getUR().getX() - getDR().getX()))
		{
			return (abs(getDL().getX() - getDR().getX()) + pow(pow(getHeightP(), 2) + pow((abs(getUL().getX() - getDL().getX())), 2), 0.5)) * 2;
		}
		else
		{
			cout << "This quadrilateral is not a parallelogram, cannot get its perimeter." << endl;
		}
	}

	void DrawP()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && abs(getUL().getX() - getDL().getX()) == abs(getUR().getX() - getDR().getX()))
		{
			int width = abs(getUL().getX() - getUR().getX());
			int height = getHeightP();

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < height - i; j++)
				{
					cout << "  ";
				}

				for (int j = 0; j < width; j++)
				{
					if (i == 0 || i == height-1 || j == 0 || j == width-1)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << "This quadrilateral is not a parallelogram, cannot draw a parallelogram." << endl;
		}
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(int ulx, int uly, int urx, int ury, int dlx, int dly, int drx, int dry) : Parallelogram(ulx, uly, urx, ury, dlx, dly, drx, dry)
	{

	}

	int getAreaR() //need double for precision
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX())
		{
			return abs(getUL().getX() - getUR().getX()) * abs(getUL().getY() - getDL().getY());
		}
		else
		{
			cout << "This quadrilateral is not a rectangle, cannot get its area." << endl;
		}
	}

	int getPerimeterR() //need double for precision
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX())
		{
			return (abs(getUL().getX() - getUR().getX()) + abs(getUL().getY() - getDL().getY())) * 2;
		}
		else
		{
			cout << "This quadrilateral is not a rectangle, cannot get its perimeter." << endl;
		}
	}

	void DrawR()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX())
		{
			int width = abs(getUL().getX() - getUR().getX());
			int length = abs(getUL().getY() - getDL().getY());

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (j == 0 || j == width - 1 || i == 0 || i == length - 1)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << "This quadrilateral is not a rectangle, cannot draw a rectangle." << endl;
		}
	}
};

class Square : public Rectangle
{
public:
	Square(int ulx, int uly, int urx, int ury, int dlx, int dly, int drx, int dry) : Rectangle(ulx, uly, urx, ury, dlx, dly, drx, dry)
	{
		
	}

	int getAreaS()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX() && abs(getUL().getX() - getUR().getX()) == abs(getUL().getY() - getDL().getY()))
		{
			return abs(getUL().getX() - getUR().getX()) * abs(getUL().getY() - getDL().getY());
		}
		else
		{
			cout << "This quadrilateral is not a square, cannot get its area." << endl;
		}
	}

	int getPerimeterS()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX() && abs(getUL().getX() - getUR().getX()) == abs(getUL().getY() - getDL().getY()))
		{
			return (abs(getUL().getX() - getUR().getX()) + abs(getUL().getY() - getDL().getY())) * 2;
		}
		else
		{
			cout << "This quadrilateral is not a square, cannot get its perimeter." << endl;
		}
	}

	void DrawS()
	{
		if (getUL().getY() == getUR().getY() && getDL().getY() == getDR().getY() && getUL().getX() == getDL().getX() && getUR().getX() == getDR().getX() && abs(getUL().getX() - getUR().getX()) == abs(getUL().getY() - getDL().getY()))
		{
			int width = abs(getUL().getX() - getUR().getX());
			int length = abs(getUL().getY() - getDL().getY());

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (j == 0 || j == width - 1 || i == 0 || i == length - 1)
					{
						cout << "* ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
		}
		else
		{
			cout << "This quadrilateral is not a square, cannot draw a square." << endl;
		}
	}
};

int main()
{
	//srand(time(nullptr)); //initialization of random seed

	//int x1 = rand() % 11; //upperLeftX
	//int y1 = rand() % 10 + 1; //upperLeftY
	//int x2 = rand() % 10 + 1; //upperRightX
	//int y2 = rand() % 10 + 1; //upperRightY
	//int x3 = rand() % 11; //downLeftX
	//int y3 = rand() % 11; //downLeftY
	//int x4 = rand() % 10 + 1; //downRightX
	//int y4 = rand() % 11; //downRightY

	////force the coordinates to be in their right place in the grid

	//while (x1 >= x2 || x1 >= x4 || y1 <= y2 || y1 <= y4 || x3 >= x4 || x3 >= x2 || y3 >= y1 || y3 >= y2 || x2<=x1)
	//{
	//	x1 = rand() % 11;
	//	x2 = rand() % 10 + 1;
	//	x4 = rand() % 10 + 1;
	//	y1 = rand() % 10 + 1;
	//	y2 = rand() % 10 + 1;
	//	y4 = rand() % 11;
	//	x3 = rand() % 11;
	//	y3 = rand() % 11;
	//}

	//Trapezoid q = { x1,y1,x2,y2,x3,y3,x4,y4 };

	//printf("%d %d\n", q.getUL());
	//printf("%d %d\n", q.getUR());
	//printf("%d %d\n", q.getDL());
	//printf("%d %d\n", q.getDR());
	//printf("%d %d %d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3, x4, y4);

	Trapezoid q = { 4,8,6,8,2,3,9,3 };
	printf("%d %d\n", q.getUL());
	printf("%d %d\n", q.getUR());
	printf("%d %d\n", q.getDL());
	printf("%d %d\n", q.getDR());
	printf("Trapezoid Height : %d\n", q.getHeightT()); 
	printf("Trapezoid Perimeter : %d\n", q.getPerimeterT()); 
	printf("Trapezoid Area : %d\n\n", q.getAreaT());
	
	Parallelogram p = { 5,7,9,7,1,1,5,1 };
	printf("%d %d\n", p.getUL());
	printf("%d %d\n", p.getUR());
	printf("%d %d\n", p.getDL());
	printf("%d %d\n", p.getDR());
	printf("Parallelogram Height : %d\n", p.getHeightP());
	printf("Parallelogram Perimeter : %d\n", p.getPerimeterP());
	printf("Parallelogram Area : %d\n\n", p.getAreaP());
	p.DrawP();
	cout << endl;

	Rectangle r = { 2,10,9,10,2,1,9,1 };
	printf("%d %d\n", r.getUL());
	printf("%d %d\n", r.getUR());
	printf("%d %d\n", r.getDL());
	printf("%d %d\n", r.getDR());
	printf("Rectangle Perimeter : %d\n", r.getPerimeterR());
	printf("Rectangle Area : %d\n\n", r.getAreaR());
	r.DrawR();
	cout << endl;

	Square s = { 3,7,6,7,3,4,6,4 };
	printf("%d %d\n", s.getUL());
	printf("%d %d\n", s.getUR());
	printf("%d %d\n", s.getDL());
	printf("%d %d\n", s.getDR());
	printf("Square Perimeter : %d\n", s.getPerimeterS());
	printf("Square Area: %d\n\n", s.getAreaS());
	s.DrawS();
	cout << endl;

	return 0;
}