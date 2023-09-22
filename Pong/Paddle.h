#pragma once
#include <raylib.h>
//#include <iostream>
#include "Globals.h"

enum class PaddlePosition {
	LEFT,
	RIGHT
};

class Paddle
{

public:
	Paddle(PaddlePosition);
	~Paddle();

	void movePaddle(int);


	int getX() const { return x; }
	int getY() const { return y; }

	Color getColor() const { return color; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	void setColor(const Color& color) { this->color = color; }

	static constexpr int PADDLE_WIDTH = 10;
	static constexpr int PADDLE_HEIGHT = 100;

private:
	
	int x;
	int y;

	Color color;
};

