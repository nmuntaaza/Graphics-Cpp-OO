#include <iostream>
#include "_161511025.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) 
{
	initwindow(800, 800, "Graphics");
	Circle c1(300, 100, 50);
	c1.draw(BLUE);
	c1.dilatation();
	c1.draw(RED);
	
	system("pause");
	return 0;
}
