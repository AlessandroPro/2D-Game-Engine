#include "Core.h"
#include "RenderSystem.h"
#include "IRenderable.h"
#include "GameObject.h"
#include "Camera.h"
#include "FileSystem.h"

void RenderSystem::initialize()
{

	window = new sf::RenderWindow(sf::VideoMode(currentView.getSize().x, currentView.getSize().y), name);
	window->setFramerateLimit(60);
	
	sf::Vector2u windowSize = sf::Vector2u(currentView.getSize().x, currentView.getSize().y);
	std::string defaultSettingsPath = "../Assets/SystemSettings/renderSettings.json";
	json::JSON loadNode = FileSystem::instance().loadRenderSettings(defaultSettingsPath);
	if (loadNode.hasKey("Width"))
	{
		windowSize.x = loadNode["Width"].ToInt();
	}
	if (loadNode.hasKey("Height"))
	{
		windowSize.y = loadNode["Height"].ToInt();
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
		window->create(sf::VideoMode(windowSize.x, windowSize.y, 60), name, sf::Style::Fullscreen);
	}
	else
	{
		window->create(sf::VideoMode(windowSize.x, windowSize.y, 60), name, sf::Style::Default);
	}
	currentView.resetView(window);
}

void RenderSystem::load(json::JSON loadNode, STRCODE fileId)
{
	//add code to reset the view if there is no camera
	if (loadNode.dump().find("Camera") == std::string::npos)
	{
		currentView.resetView(window);
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