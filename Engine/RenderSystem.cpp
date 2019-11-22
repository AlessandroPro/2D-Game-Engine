#include "Core.h"
#include "RenderSystem.h"
#include "IRenderable.h"


void RenderSystem::initialize()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), name);
	window->setFramerateLimit(60);
}

void RenderSystem::update(float deltaTime)
{
	if (window != nullptr)
	{
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