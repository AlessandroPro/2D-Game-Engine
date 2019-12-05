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

class Camera;
class IRenderable;

class RenderSystem final : public ISystem
{
public:
	enum RenderLayer
	{
		Environment, StartingObjects, Enemies, Players, Effects, UI, UIEffects
	};
	std::vector<RenderLayer> layerOrder{ Environment, StartingObjects, Enemies, Players, Effects, UI, UIEffects };
private:
	//Used for controlling the dimensions/positioning of the screen.
	class ViewPoint
	{
	private:
		sf::Vector2f size = sf::Vector2f(350.f, 300.f);
		sf::Vector2f position = sf::Vector2f(0.f, 0.f);
		sf::View windowView = sf::View(position, size);
	public:
		ViewPoint()
		{
			setSize(size);
		}
		void setSize(sf::Vector2f inSize)
		{
			size = inSize;
			windowView.setSize(inSize.x, -inSize.y);
		}
		void setCenter(sf::Vector2f newCenter) 
		{
			windowView.setCenter(newCenter); 
		}
		const sf::Vector2f& getSize() { return size; }
		void setWindowView(sf::RenderWindow* window) 
		{ 
			window->setView(windowView); 
		}
		void resetView(sf::RenderWindow* window)
		{
			windowView = window->getDefaultView();
			size = windowView.getSize();
		}
	};

	ViewPoint currentView;

	std::string name = "";
	bool fullscreen = false;
	sf::RenderWindow* window = nullptr;
	std::map<RenderLayer, std::list<IRenderable*>> renderables;

protected:
	void initialize() override;
	void update(float deltaTime) override;

	friend class GameEngine;
	friend class InputManager;
	friend class Camera;
	DECLARE_SINGLETON(RenderSystem)

public:
	void closeWindow();
	sf::RenderWindow* getRenderWindow() { return window; }
	void addRenderable(IRenderable* _renderable);
	void removeRenderable(IRenderable* _renderable);
	void load(json::JSON loadNode, STRCODE fileId);
	const sf::Vector2f& getViewSize() { return currentView.getSize(); }
	void setRenderLayer(IRenderable* _renderable, RenderSystem::RenderLayer newLayer);
};

#endif