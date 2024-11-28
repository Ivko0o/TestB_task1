#include <iostream>
#include <cmath>

using namespace std;

//This program will check how a circle and a square interact with each other with given coordinates by the user

int main()
{
	int x1, y1, r1 = 0;			//These will be the coordinates for the circle
	int x2, y2, a = 0;			//These will be the side of the square

	int closestX = 0;			//These will be the coordinates for the closest point from the square to the center of the circle
	int closestY = 0;			//These will be the coordinates for the closest point from the square to the center of the circle

	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> a;

	int distance = 0;			

	//This  will calculate the closest point from the square to the center of the circle
	if (x1 >= x2 && x1 <= (x2 + a)) {
		closestX = x1;
	}
	else if (x1 < x2) {
		closestX = x2;
	}
	else if(x1 > (x2+a)){
		closestX = x2 + a;
	}


	if (y1 >= y2 && y1 <= (y2 + a)) {
		closestY = y1;
	}
	else if (y1 < y2) {
		closestY = y2;
	}
	else if (y1 > (y2 + a)) {
		closestY = y2 + a;
	}

	//This will find the distance between the closes point and the center of the circle
	distance = sqrt(((x1-closestX)*(x1 - closestX)) + ((y1 - closestY)*(y1 - closestY)));

	//This checks if all of the square corners are inside of the circle
	if (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))) <= r1 &&										//This is for the bottom left corner of the sqare
		sqrt((((x2 + a) - x1) * ((x2 + a) - x1)) + ((y2 - y1) * (y2 - y1))) <= r1 &&							//This is for the bottom right corner
		sqrt(((x2 - x1) * (x2 - x1)) + (((y2 + a) - y1) * ((y2 + a) - y1))) <= r1 &&							//This is for the top left corner
		sqrt((((x2 + a) - x1) * ((x2 + a) - x1)) + (((y2 + a) - y1) * ((y2 + a) - y1)))							//This is for the top right corner
		) {
		cout << "The square is in the circle!";
		return 1;
	}

	if (x1 - r1 >= x2 && x1 + r1 <= x2 + a && y1 - r1 >= y2 && y1 + r1 <= y2 + a) {
		cout << "The circle is inside of the square!";
		return 1;
	}

	if (distance < r1) {
		cout << "The circle and square intersect with each other!";
	}
	else if (distance == r1) {
		cout << "The circle and square touch each other!";   //He-he-he-he :D
	}
	else if (distance > r1) {
		cout << "The circle and square do not touch each other!";
	}


}

