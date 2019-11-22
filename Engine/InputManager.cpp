#include "Core.h"
#include "InputManager.h"
#include "RenderSystem.h"

void InputManager::initialize()
{
	//initialize all of the key states?
}

void InputManager::update(float deltaTime)
{
	sf::Event event;
	//while (RenderSystem::instance().getRenderWindow()->pollEvent(event))
	//{
	//	switch (event.type)
	//	{
	//	case sf::Event::Closed:
	//		RenderSystem::instance().closeWindow();
	//
	//		return;

	//		break;

	//	case sf::Event::KeyReleased:
	//		
	//		break;

	//	case sf::Event::MouseButtonPressed:
	//
	//		break;

	//	default:
	//		break;
	//	}
	//}
}

InputManager::InputState InputManager::getKeyState(sf::Keyboard::Key inKey) 
{
	return keyMap[inKey];
}

InputManager::InputState InputManager::getMouseButtonState(sf::Mouse::Button inMouseBtn) 
{
	return mouseBtnMap[inMouseBtn];
}

sf::Vector2<float> InputManager::getMousePosition()
{
	return mousePosition;
}
