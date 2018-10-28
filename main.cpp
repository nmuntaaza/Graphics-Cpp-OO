#include <iostream>
#include "_161511025.hpp"

int main(int argc, char* argv[]) 
{
	initwindow(800, 800, "Graphics");
	Line line(300, 300, 300, 400);
	Ellips3 ellipse(100, 100, 50, 100);
	line.draw(GREEN);
	line.dilatation(300, 350, 0.5);
	line.translation(50, 0);
	line.draw(RED);
	ellipse.draw(YELLOW);
	
	system("pause");
	return 0;
}
