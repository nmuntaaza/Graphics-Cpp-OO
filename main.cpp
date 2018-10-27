#include <iostream>
#include "_161511025.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) 
{
	initwindow(400, 400, "Graphics");
	Circle c1(100, 100, 50, BLUE);
	c1.draw();
	c1.translation(0, 100);
	c1.draw();
	
	system("pause");
	return 0;
}
