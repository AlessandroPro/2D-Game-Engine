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

	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			RenderSystem::instance().closeWindow();
			return;
		case sf::Event::KeyPressed:
			//If a modifier key is pressed then the modifier map is updated
			if(modifierKeyMap.find(ev.key.code) != modifierKeyMap.end())
			{
				updateModifier(ev.key.code, true);
			}
			//Do not update the state to down if it's already been set as being held.
			if(keyMap[ev.key.code].state != PushState::Held)
			{
				keyMap[ev.key.code].state = PushState::Down;
			}
			break;
		case sf::Event::KeyReleased:
			//If a modifier key is released then the modifier map is updated
			if (modifierKeyMap.find(ev.key.code) != modifierKeyMap.end())
			{
				updateModifier(ev.key.code, false);
			}

			keyMap[ev.key.code].state = PushState::Up;
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
	//Initializes the key data if it doesn't already exist.
	if (keyMap.find(inKey) == keyMap.end())
	{
		KeyData newKey = { PushState::None, false, false, false };
		keyMap.insert(std::pair<sf::Keyboard::Key, KeyData>(inKey, newKey));
	}
	return keyMap[inKey].state;
}
InputManager::KeyData& InputManager::getKeyData(sf::Keyboard::Key inKey)
{
	//Initializes the key data if it doesn't already exist.
	if (keyMap.find(inKey) == keyMap.end())
	{
		KeyData newKey = { PushState::None, false, false, false };
		keyMap.insert(std::pair<sf::Keyboard::Key, KeyData>(inKey, newKey));
	}
	return keyMap[inKey];
}
InputManager::PushState InputManager::getMouseButtonState(sf::Mouse::Button inMouseBtn)
{
	//Initializes the button state if it doesn't already exist.
	if (mouseBtnMap.find(inMouseBtn) == mouseBtnMap.end())
	{
		mouseBtnMap.insert(std::pair<sf::Mouse::Button, PushState>(inMouseBtn, PushState::None));
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
		if (key.second.state == PushState::Up)
		{
			keyMap[key.first].state = PushState::None;
		}
		//The initial key push is stored for only one iteration of the inputmanager's loop
		//it then shifts to the Held state.
		else if (key.second.state == PushState::Down)
		{
			keyMap[key.first].state = PushState::Held;
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

//Updates the state for all keys if a new modifier state is achieved as a result
//of the provided input modifier key's new value.
void InputManager::updateModifier(sf::Keyboard::Key modifierKey, bool isPressed)
{
	modifierKeyMap[modifierKey] = isPressed;

	if(modifierKey == sf::Keyboard::LShift ||
		modifierKey == sf::Keyboard::RShift)
	{ 
		//We only care about updating the the shift state for all keys if one of the shifts is true
		//and the update to the state was one of them being pushed.
		if((modifierKeyMap[sf::Keyboard::LShift] || modifierKeyMap[sf::Keyboard::RShift])
			&& isPressed)
		{
			for(auto key : keyMap)
			{
				keyMap[key.first].shift = true;
			}
		}
		//We only care about updating the the shift state for all keys if both of the shifts are false
		else if (!modifierKeyMap[sf::Keyboard::LShift] && !modifierKeyMap[sf::Keyboard::RShift])
		{
			for (auto key : keyMap)
			{
				keyMap[key.first].shift = false;
			}
		}
	}
	else if(modifierKey == sf::Keyboard::LControl ||
		modifierKey == sf::Keyboard::RControl)
	{
		//We only care about updating the the control state for all keys if one of the controls is true
		//and the update to the state was one of them being pushed.
		if ((modifierKeyMap[sf::Keyboard::LControl] || modifierKeyMap[sf::Keyboard::RControl])
			&& isPressed)
		{
			for (auto key : keyMap)
			{
				keyMap[key.first].control = true;
			}
		}
		//We only care about updating the the control state for all keys if both of the controls are false
		else if (!modifierKeyMap[sf::Keyboard::LControl] && !modifierKeyMap[sf::Keyboard::RControl])
		{
			for (auto key : keyMap)
			{
				keyMap[key.first].control = false;
			}
		}
	}
	else if(modifierKey == sf::Keyboard::LAlt ||
		modifierKey == sf::Keyboard::RAlt)
	{
		//We only care about updating the the alt state for all keys if one of the alts is true
		//and the update to the state was one of them being pushed.
		if ((modifierKeyMap[sf::Keyboard::LAlt] || modifierKeyMap[sf::Keyboard::RAlt])
			&& isPressed)
		{
			for (auto key : keyMap)
			{
				keyMap[key.first].alt = true;
			}
		}
		//We only care about updating the the alt state for all keys if both of the alts are false
		else if (!modifierKeyMap[sf::Keyboard::LAlt] && !modifierKeyMap[sf::Keyboard::RAlt])
		{
			for (auto key : keyMap)
			{
				keyMap[key.first].alt = false;
			}
		}
	}
}
