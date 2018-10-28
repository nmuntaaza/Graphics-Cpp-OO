#include <iostream>
#include "_161511025.hpp"

int main(int argc, char* argv[]) 
{
	initwindow(800, 800, "Graphics");
	Square square(300, 300, 350, 350);
	square.draw(BLUE);
	square.translation(-100, 0);
	square.draw(RED);
	square.dilatation((square.point1.x + square.point2.x)/2, (square.point1.y + square.point2.y)/2, 2.0);
	square.draw(GREEN);
	
	Triangle tri(100, 100, 200, 200, 0, 150);
	tri.draw(YELLOW);
	tri.dilatation((tri.point1.x + tri.point2.x +  tri.point3.x)/3, (tri.point1.y + tri.point2.y +  tri.point3.y)/3, 0.5);
	tri.draw(RED);
	
	system("pause");
	return 0;
}
