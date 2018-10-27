#ifndef _161511025_H_INCLUDED
#define _161511025_H_INCLUDED

#include <cmath>
#include "graphics.h"

class Point
{
	public:
		int x;
		int y;
		float gradien;
		float c;
		
	public:
		Point(int x = 0, int y = 0);
		void translation(int xt = 0, int yt = 0);
		void reflection(float gradien = 1.0, float c = 0);
};

class Circle
{
	public:
		Point point;
		float radius;
		int color;
		
	public:
		Circle(int x = 0, int y = 0, float radius = 50.0, int color = GREEN);
		void draw(int lineColor = WHITE);
		void translation(int xt = 0, int yt = 0);
		void reflection(float gradien = 1.0, float c = 0);
		float area();
};

#endif
