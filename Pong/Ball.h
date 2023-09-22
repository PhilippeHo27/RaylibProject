#pragma once
#include <raylib.h>
#include <iostream>
#include "Globals.h"
//#include "GlobalsCore.h"

using namespace std;
using namespace pongspace;

class Ball
{
public:
	Ball();
	~Ball();

	void changeDirection(bool);
	void moveBall();

	float getX() const { return x; }
	float getY() const { return y; }
	float getRadius() const { return radius; }
	Color getColor() const { return color; }

	void setX(float x) { this->x = x; }
	void setY(float y) { this->y = y; }

	void setRadius(float radius) { this->radius = radius; }
	void setColor(const Color& color) { this->color = color; }

private:

	float x;
	float y;
	float radius;
	Color color;
	float speedX;
	float speedY;
};

