#include "Core.h"
#include "InputManager.h"
#include "RenderSystem.h"

void InputManager::initialize()
{
	//initialize all of the key states?
}

void InputManager::update(float deltaTime)
{
	for(auto key : keyMap)
	{
		if(key.second == InputManager::Up)
		{
			keyMap[key.first] = InputManager::None;
		}
		else if (key.second == InputManager::Down)
		{
			keyMap[key.first] = InputManager::Held;
		}
	}

	for (auto btn : mouseBtnMap)
	{
		if (btn.second == InputManager::Up)
		{
			mouseBtnMap[btn.first] = InputManager::None;
		}
		else if (btn.second == InputManager::Down)
		{
			mouseBtnMap[btn.first] = InputManager::Held;
		}
	}

	sf::Event ev;
	while (RenderSystem::instance().getRenderWindow()->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			RenderSystem::instance().closeWindow();
			return;
		case sf::Event::KeyPressed:
			if(keyMap[ev.key.code] != InputState::Held)
			{
				keyMap[ev.key.code] = InputState::Down;
			}
			break;
		case sf::Event::KeyReleased:
			keyMap[ev.key.code] = InputState::Up;
			break;
		case sf::Event::MouseButtonPressed:
			if (mouseBtnMap[ev.mouseButton.button] != InputState::Held)
			{
				mouseBtnMap[ev.mouseButton.button] = InputState::Down;
			}
			break;
		case sf::Event::MouseButtonReleased:
			mouseBtnMap[ev.mouseButton.button] = InputState::Up;
			break;
		case sf::Event::MouseMoved:
			mousePosition.x = ev.mouseMove.x;
			mousePosition.y = ev.mouseMove.y;
			break;
		default:
			break;
		}
	}
}

InputManager::InputState InputManager::getKeyState(sf::Keyboard::Key inKey) 
{
	if (keyMap.find(inKey) == keyMap.end())
	{
		keyMap.insert(std::pair<sf::Keyboard::Key, InputState>(inKey, InputState::None));
	}
	return keyMap[inKey];
}

InputManager::InputState InputManager::getMouseButtonState(sf::Mouse::Button inMouseBtn) 
{
	if (mouseBtnMap.find(inMouseBtn) == mouseBtnMap.end())
	{
		mouseBtnMap.insert(std::pair<sf::Mouse::Button, InputState>(inMouseBtn, InputState::None));
	}
	return mouseBtnMap[inMouseBtn];
}

sf::Vector2<float> InputManager::getMousePosition()
{
	return mousePosition;
}
