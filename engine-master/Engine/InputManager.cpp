#include "Core.h"
#include "InputManager.h"
#include "RenderSystem.h"

void InputManager::initialize()
{
}

void InputManager::update()
{
	events.clear();

	sf::Event event;
	while (RenderSystem::instance().getWindow()->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			RenderSystem::instance().closeWindow();
			return;
			break;

		default:
			events.push_back(event);
			break;
		}
	}

}
