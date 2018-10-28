#include <iostream>
#include "_161511025.hpp"

int main(int argc, char* argv[]) 
{
	initwindow(800, 800, "Graphics");
	Ellips3 ellipse(300, 100, 50, 50);
	ellipse.draw(YELLOW);
	ellipse.reflection(1.0, -50.0);
	ellipse.draw(GREEN);
	ellipse.dilatation(ellipse.point.x, ellipse.point.y, 3.0);
	ellipse.draw(RED);
	Square square(500, 500, 600, 600);
	square.draw(BLUE);
	
	system("pause");
	return 0;
}
