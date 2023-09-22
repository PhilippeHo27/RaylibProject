#include <iostream>
#include <raylib.h>
#include <Code_Utilities_Light_v2.h>

#include "Globals.h"
#include "Pong.h"
#include "Paddle.h"

using namespace std;
using namespace pongspace;

Pong::Pong()
    :leftPaddle(PaddlePosition::LEFT)
    ,rightPaddle(PaddlePosition::RIGHT)
{
    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(FPS);
    //init(_presets[0]);

    BdB::srandInt((uint)time(0));
}

Pong::~Pong()
{
	CloseWindow();
}

void Pong::handleInput()
{
    if (IsKeyDown(KEY_S))
        leftPaddle.movePaddle(1);

    if (IsKeyDown(KEY_W))
        leftPaddle.movePaddle(-1);

    if (IsKeyDown(KEY_DOWN))
        rightPaddle.movePaddle(1);

    if (IsKeyDown(KEY_UP))
        rightPaddle.movePaddle(-1);
}

void Pong::update()
{
    ball.changeDirection(false);
    ball.moveBall();

    Rectangle leftPaddleRect = { leftPaddle.getX(), leftPaddle.getY(), leftPaddle.PADDLE_WIDTH, leftPaddle.PADDLE_HEIGHT };
    Rectangle rightPaddleRect = { rightPaddle.getX(), rightPaddle.getY(), rightPaddle.PADDLE_WIDTH, rightPaddle.PADDLE_HEIGHT };

    if (CheckCollisionCircleRec({ ball.getX(), ball.getY()}, ball.getRadius(), leftPaddleRect))
        ball.changeDirection(true);

    if (CheckCollisionCircleRec({ ball.getX(), ball.getY() }, ball.getRadius(), rightPaddleRect))
        ball.changeDirection(true);

}

void Pong::render() const
{
    BeginDrawing();

    ClearBackground(BLACK);
    DrawText("PONG...", 10, 10, 20, WHITE);

    DrawCircle(ball.getX(), ball.getY(), ball.getRadius(), ball.getColor());

    DrawRectangle(leftPaddle.getX(), leftPaddle.getY(), leftPaddle.PADDLE_WIDTH, leftPaddle.PADDLE_HEIGHT, WHITE);
    DrawRectangle(rightPaddle.getX(), rightPaddle.getY(), rightPaddle.PADDLE_WIDTH, rightPaddle.PADDLE_HEIGHT, WHITE);

    DrawFPS(SCREEN_WIDTH - 100, 10);

    EndDrawing();
}