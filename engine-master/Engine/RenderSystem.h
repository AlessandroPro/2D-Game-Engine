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

class IRenderable;

class RenderSystem
{
private:
	std::string name = "";
	int width = 300;
	int height = 300;
	bool fullscreen = false;

	sf::RenderWindow* window = nullptr;

	std::list<IRenderable*> renderables;

public:
	static RenderSystem& instance()
	{
		static RenderSystem _instance;
		return _instance;
	}

	sf::RenderWindow* getWindow() { return window; }

	void initialize(json::JSON &document);
	void update();
	void closeWindow();

	void addRenderable(IRenderable* _renderable);
	void removeRenderable(IRenderable* _renderable);

	int getHeight() { return height; }
	int getWidth() { return width; }

private:
    RenderSystem() = default;
    ~RenderSystem() = default;
    RenderSystem(RenderSystem const&) = delete;
};

#endif