#include "Paddle.h"

using namespace pongspace;

Paddle::Paddle(PaddlePosition position)
	:y(SCREEN_HEIGHT/2)
	,color(WHITE)
{
	if (position == PaddlePosition::LEFT)
		x = 50;
	else
		x = SCREEN_WIDTH - 50;
}

Paddle::~Paddle()
{
}

void Paddle::movePaddle(int dir)
{
	y += dir * 300 * GetFrameTime();
}
