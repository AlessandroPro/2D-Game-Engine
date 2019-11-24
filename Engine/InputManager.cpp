#include "Core.h"
#include "InputManager.h"
#include "RenderSystem.h"

void InputManager::initialize()
{

}

void InputManager::update(float deltaTime)
{
	//These methods update from Up->None and Down->Held
	updateKeyStates();
	updateMouseButtonStates();

	sf::RenderWindow* window = RenderSystem::instance().getRenderWindow();
	sf::Event ev;

	//Return if the window is null.
	if (window == nullptr) 
	{
		return;
	}

	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			RenderSystem::instance().closeWindow();
			return;
		case sf::Event::KeyPressed:
			//Do not update the state to down if it's already been set as being held.
			if(keyMap[ev.key.code] != PushState::Held)
			{
				keyMap[ev.key.code] = PushState::Down;
			}
			break;
		case sf::Event::KeyReleased:
			keyMap[ev.key.code] = PushState::Up;
			break;
		case sf::Event::MouseButtonPressed:
			//Do not update the state to down if it's already been set as being held.
			if (mouseBtnMap[ev.mouseButton.button] != PushState::Held)
			{
				mouseBtnMap[ev.mouseButton.button] = PushState::Down;
			}
			break;
		case sf::Event::MouseButtonReleased:
			mouseBtnMap[ev.mouseButton.button] = PushState::Up;
			break;
		case sf::Event::MouseMoved:
			mousePosition.y = ev.mouseMove.y;
			mousePosition.x = ev.mouseMove.x;

			//Unflip the Y coordinates for uniform mouse position.
			uniformMousePosition.y = 1.00f - (mousePosition.y / window->getSize().y);
			uniformMousePosition.x = mousePosition.x / window->getSize().x;
			
			break;

		default:
			break;
		}
	}
}

InputManager::PushState InputManager::getKeyState(sf::Keyboard::Key inKey)
{
	auto keyIter = keyMap.find(inKey);

	//Initializes the key data if it doesn't already exist.
	if (keyIter == keyMap.end())
	{
		keyMap.insert(keyIter,std::pair<sf::Keyboard::Key, PushState>(inKey, PushState::None));
	}

	return keyMap[inKey];
}

InputManager::PushState InputManager::getMouseButtonState(sf::Mouse::Button inMouseBtn)
{
	auto btnIter = mouseBtnMap.find(inMouseBtn);

	//Initializes the button state if it doesn't already exist.
	if (btnIter == mouseBtnMap.end())
	{
		mouseBtnMap.insert(btnIter, std::pair<sf::Mouse::Button, PushState>(inMouseBtn, PushState::None));
	}

	return mouseBtnMap[inMouseBtn];
}

sf::Vector2f& InputManager::getMousePosition()
{
	return mousePosition;
}
sf::Vector2f& InputManager::getUniformMousePosition()
{
	return uniformMousePosition;
}

//Iterates through all of the currently stored keys and updates their states.
void InputManager::updateKeyStates()
{
	for (auto key : keyMap)
	{
		//The initial key release is stored for only one iteration of the inputmanager's loop
		//it then shifts to the None state.
		if (key.second == PushState::Up)
		{
			keyMap[key.first] = PushState::None;
		}
		//The initial key push is stored for only one iteration of the inputmanager's loop
		//it then shifts to the Held state.
		else if (key.second == PushState::Down)
		{
			keyMap[key.first] = PushState::Held;
		}
	}
}
//Iterates through all of the currently stored buttons and updates their states.
void InputManager::updateMouseButtonStates()
{
	for (auto btn : mouseBtnMap)
	{
		//The initial button release is stored for only one iteration of the inputmanager's loop
		//it then shifts to the None state.
		if (btn.second == PushState::Up)
		{
			mouseBtnMap[btn.first] = PushState::None;
		}
		//The initial button push is stored for only one iteration of the inputmanager's loop
		//it then shifts to the Held state.
		else if (btn.second == PushState::Down)
		{
			mouseBtnMap[btn.first] = PushState::Held;
		}
	}
}