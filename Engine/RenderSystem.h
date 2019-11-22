///-------------------------------------------------------------------------------------------------
// file: RenderSystem.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Render System
///-------------------------------------------------------------------------------------------------
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_
#pragma once

#include "ISystem.h"

class IRenderable;

class RenderSystem final : public ISystem
{
private:
	std::string name = "";
	int width = 300;
	int height = 300;
	bool fullscreen = false;

	sf::RenderWindow* window = nullptr;

	std::list<IRenderable*> renderables;

protected:
	void initialize() override;
	void update(float deltaTime) override;

    friend class GameEngine;
	friend class InputManager;
    DECLARE_SINGLETON(RenderSystem)

public:
	void closeWindow();
	sf::RenderWindow* getRenderWindow() { return window; }
	void addRenderable(IRenderable* _renderable);
	void removeRenderable(IRenderable* _renderable);

	int getHeight() { return height; }
	int getWidth() { return width; }
};

#endif