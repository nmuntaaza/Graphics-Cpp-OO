#include <iostream>
#include "_161511025.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) 
{
	initwindow(800, 800, "Graphics");
	Line line(300, 300, 300, 400);
	line.draw(GREEN);
	line.dilatation(300, 350, 0.5);
	line.translation(50, 0);
	line.draw(RED);
	
	system("pause");
	return 0;
}
