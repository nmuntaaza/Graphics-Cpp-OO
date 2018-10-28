#include <iostream>
#include "_161511025.hpp"

int main(int argc, char* argv[]) 
{
	initwindow(800, 800, "Graphics");
	Square square(300, 300, 350, 350);
	square.draw(BLUE);
	square.translation(-100, 0);
	square.draw(RED);
	square.dilatation(square.origin().x, square.origin().y, 2.0);
	square.draw(GREEN);
	
	Triangle tri(100, 100, 200, 200, 0, 150);
	tri.draw(YELLOW);
	tri.dilatation(tri.origin().x, tri.origin().y, 0.5);
	tri.draw(RED);
	
	system("pause");
	return 0;
}
