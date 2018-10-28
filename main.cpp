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
	
	system("pause");
	return 0;
}
