#include <iostream>
#include "GameEngine.h"

int main(int argc, char* argv[])
{
	GameEngine* gameEngine = new GameEngine();
    gameEngine->initialize();
	gameEngine->gameLoop();
	gameEngine->display();
	delete gameEngine;

	return -1;
}