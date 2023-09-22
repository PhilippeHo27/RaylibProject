#include "Game.h"
#include <raylib.h>
#include <Code_Utilities_Light_v2.h>
#include "GlobalsCore.h"

using namespace std;
using namespace Core;

Game::Game() : _keepPlaying(true) {}

Game::~Game() {}

/*
* 
* Main game Loop
* --------------
* Reference: http://gameprogrammingpatterns.com/game-loop.html
*/
void Game::loop()
{
    while (_keepPlaying && !WindowShouldClose())
    {
        // -- Events --
        handleInput();

        // -- Update --
        update();

        // -- draw --
        render();
    }
}
