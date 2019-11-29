///-------------------------------------------------------------------------------------------------
// file: GameEngine.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Game Engine
///-------------------------------------------------------------------------------------------------
#ifndef _GAMEENGINE_H_
#define _GAMEENGINE_H_
#pragma once

#include "ISystem.h"

class GameEngine final
{
private:
    ISystem* projectEngine;
	std::string spriteName = "Sprite";
public:
	void initialize(ISystem* _projectEngine = nullptr);
	void gameLoop();

    DECLARE_SINGLETON(GameEngine)
};

#endif