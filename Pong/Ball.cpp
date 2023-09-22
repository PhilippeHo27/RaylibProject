#include "Ball.h"

Ball::Ball()
	: x(SCREEN_WIDTH / 2)
	, y(SCREEN_HEIGHT / 2)
	, radius(5)
	, color(WHITE)
	, speedX(300)
	, speedY(300)
{
}

Ball::~Ball()
{
}

void Ball::changeDirection(bool hit)
{
	if (hit)
	{
		speedX *= -1;
	}

	if (x < 0)
	{
		x = 0;
		speedX *= -1;
	}

	if (x > GetScreenWidth())
	{
		x = GetScreenWidth();
		speedX *= -1;
	}	
	
	if (y < 0)
	{
		y = 0;
		speedY *= -1;
	}

	if (y > GetScreenHeight())
	{
		y = GetScreenHeight();
		speedY *= -1;
	}
}

void Ball::moveBall()
{
	x += speedX * GetFrameTime();
	y += speedY * GetFrameTime();
}
