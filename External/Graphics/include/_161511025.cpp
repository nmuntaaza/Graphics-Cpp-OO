#include "_161511025.hpp"

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
	this->x = float(2 * d - this->x);
	this->y = float(2 * d * gradien - this->y + 2 * c);
}

void Point::rotation(int a, int b, int angle)
{
	this->x = (cos((angle * PI) / 180) * (this->x - a)) + (-sin((angle * PI) / 180) * (this->y - b)) + a;
	this->y = (sin((angle * PI) / 180) * (this->x - a)) + (cos((angle * PI) / 180) * (this->y - b)) + b;
}

void Point::dilatation(int a, int b, float scale)
{
	this->x = (scale * (this->x - a)) + a;
	this->y = (scale * (this->y - b)) + b;
}

// Line



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
