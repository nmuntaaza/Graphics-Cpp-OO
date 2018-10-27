#include "_161511025.hpp"

#define PI 3.14159265359

int abs(int n)
{
  return ((n > 0) ? n : (n * (-1)));
}

// Point

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::translation(int xt, int yt)
{
	this->x = this->x + xt;
	this->y = this->y + yt;
}

void Point::reflection(float gradien, float c)
{
	float d = (this->x + (this->y - c) * gradien) / (1 + pow(gradien, 2));
	float x = 2 * d - this->x;
	float y = 2 * d * gradien - this->y + 2 * c;
	
	this->x = x;
	this->y = y;
}

void Point::rotation(int a, int b, int angle)
{
	float x = (cos((angle * PI) / 180) * (this->x - a)) + (-sin((angle * PI) / 180) * (this->y - b));
	float y = (sin((angle * PI) / 180) * (this->x - a)) + (cos((angle * PI) / 180) * (this->y - b));
	
	this->x = (int) x + a;
	this->y = (int) y + b;
}

void Point::dilatation(int a, int b, float scale)
{
	this->x = (scale * (this->x - a)) + a;
	this->y = (scale * (this->y - b)) + b;
}

// Line

Line::Line(int x1, int y1, int x2, int y2)
{
	this->point1.x = x1;
	this->point1.y = y1;
	this->point2.x = x2;
	this->point2.y = y2;
}

void Line::draw(int lineColor)
{
	int x1 = point1.x, x2 = point2.x, y1 = point1.y, y2 = point2.y;
	int dx =  abs (x2 - x1), sx = x1 < x2 ? 1 : -1;
  int dy = -abs (y2 - y1), sy = y1 < y2 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
    putpixel(x1, y1, lineColor);
    if (x1 == x2 && y1 == y2) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
  }
}

void Line::translation(int xt, int yt)
{
	point1.translation(xt, yt);
	point2.translation(xt, yt);
}

void Line::reflection(float gradien, float c)
{
	point1.reflection(gradien, c);
	point2.reflection(gradien, c);
}

void Line::rotation(int a, int b, int angle)
{
	point1.rotation(a, b, angle);
	point2.rotation(a, b, angle);
}

void Line::dilatation(int a, int b, float scale)
{
	point1.dilatation(a, b, scale);
	point2.dilatation(a, b, scale);
}

// Circle

Circle::Circle(int x, int y, float radius, int color)
{
	this->point.x 	= x;
	this->point.y 	= y;
	this->radius 		= radius;
	this->color 		= color;
}

void Circle::draw(int lineColor)
{
	int x = -radius, y = 0, err = 2 - 2 * radius, r = radius; /* II. Quadrant */
  do {
		putpixel(point.x - x, point.y + y, lineColor); /*   I. Quadrant */
    putpixel(point.x - y, point.y - x, lineColor); /*  II. Quadrant */
    putpixel(point.x + x, point.y - y, lineColor); /* III. Quadrant */
    putpixel(point.x + y, point.y + x, lineColor); /*  IV. Quadrant */
    r = err;
    if (r >  x) err += ++x * 2 + 1; /* e_xy+e_x > 0 */
    if (r <= y) err += ++y * 2 + 1; /* e_xy+e_y < 0 */
  } while (x < 0);
}

void Circle::translation(int xt, int yt)
{
	point.translation(xt, yt);
}

void Circle::reflection(float gradien, float c)
{
	point.reflection(gradien, c);
}

void Circle::rotation(int a, int b, int angle)
{
	point.rotation(a, b, angle);
}

void Circle::dilatation(int a, int b, float scale)
{
	point.dilatation(a, b, scale);
	this->radius = this->radius * scale;
}

float Circle::area()
{
	return pow(this->radius, 2) * 3.14;
}
