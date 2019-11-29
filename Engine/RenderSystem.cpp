#include "Core.h"
#include "RenderSystem.h"
#include "IRenderable.h"
#include "GameObject.h"
#include "Camera.h"


void RenderSystem::initialize()
{
	window = new sf::RenderWindow(sf::VideoMode(currentView.getSize().x, currentView.getSize().y), name);
	window->setFramerateLimit(60);
}

void RenderSystem::load(json::JSON loadNode, STRCODE fileId)
{
	sf::Vector2u dimensions = sf::Vector2u(currentView.getSize().x, currentView.getSize().y);

	if (loadNode.hasKey("Width"))
	{
		dimensions.x = loadNode["Width"].ToFloat();
	}
	if (loadNode.hasKey("Height"))
	{
		dimensions.y = loadNode["Height"].ToFloat();
	}
	if (loadNode.hasKey("Name"))
	{
		name = loadNode["Name"].ToString();
	}
	if (loadNode.hasKey("Fullscreen"))
	{
		fullscreen = loadNode["Fullscreen"].ToBool();
	}

	if (fullscreen)
	{
		window->create(sf::VideoMode(dimensions.x, dimensions.y, 60), name, sf::Style::Fullscreen);
	}
	else
	{
		window->setTitle(name);
		window->setSize(dimensions);
	}
}

void RenderSystem::update(float deltaTime)
{
	if (window != nullptr)
	{
		currentView.setWindowView(window);
		window->clear();

		for (auto renderable : renderables)
		{
			renderable->render(window);
		}

		window->display();
	}
}

void RenderSystem::closeWindow()
{
	window->close();
	delete window;
	window = nullptr;
}

void RenderSystem::addRenderable(IRenderable* _renderable)
{
	renderables.push_back(_renderable);
}

void RenderSystem::removeRenderable(IRenderable* _renderable)
{
	renderables.remove(_renderable);
}