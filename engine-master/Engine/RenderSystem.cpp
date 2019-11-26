#include "Core.h"
#include "RenderSystem.h"
#include "IRenderable.h"

void RenderSystem::initialize(json::JSON &document)
{
	_ASSERT_EXPR(document.hasKey("RenderSystem"), "GameSettings Node missing RenderSystem");
    json::JSON renderSystemNode = document["RenderSystem"];

	if (renderSystemNode.hasKey("Name"))
	{
		name = renderSystemNode["Name"].ToString();
	}
	if (renderSystemNode.hasKey("width"))
	{
		width = renderSystemNode["width"].ToInt();
	}
	if (renderSystemNode.hasKey("height"))
	{
		height = renderSystemNode["height"].ToInt();
	}
	if (renderSystemNode.hasKey("fullscreen"))
	{
		fullscreen = renderSystemNode["fullscreen"].ToBool();
	}

	window = new sf::RenderWindow(sf::VideoMode(width, height), "Hello");
	window->setFramerateLimit(60);
}

void RenderSystem::update()
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
