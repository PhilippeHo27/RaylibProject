#pragma once
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
//#include "Globals.h"
//#include "GlobalsCore.h"

using namespace std;
using namespace Core;

namespace pongspace
{
	class Pong final : public Game
	{
	public: 
		Pong();
		~Pong();

		void handleInput() override;
		void update() override;
		void render() const override;
	private:

		Ball ball;
		Paddle leftPaddle, rightPaddle;
	};
}
