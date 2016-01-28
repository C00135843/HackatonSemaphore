#include "stdafx.h"

bool InputManager::instanceFlag = false;
InputManager* InputManager::instance = NULL;

InputManager* InputManager::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new InputManager();
		instanceFlag = true;
		return instance;
	}
	else
	{
		return instance;
	}
}

void InputManager::UpdateState()
{
	//Check for keys that were pressed in previous frame
	if (downKeys.size() > 0)
	{
		for each (SDL_Keycode key in downKeys)
		{
			heldKeys.push_back(key);
			downKeys.remove(key);
			if (downKeys.size() == 0)
				break;
		}
	}

	if (releasedKeys.size() > 0)
	{
		for each (SDL_Keycode key in releasedKeys)
		{
			releasedKeys.remove(key);
			if (releasedKeys.size() == 0)
				break;
		}
	}

	//Check for mouse buttons that were clicked in previous frame
	if (downClicks.size() > 0)
	{
		for each (int button in downClicks)
		{
			heldClicks.push_back(button);
			downClicks.remove(button);
			if (downClicks.size() == 0)
				break;
		}
	}

	if (releasedClicks.size() > 0)
	{
		for each (int button in releasedClicks)
		{
			releasedClicks.remove(button);
			if (releasedClicks.size() == 0)
				break;
		}
	}
}

void InputManager::UpdatePolledEvents(SDL_Event e)
{
//Key Input
	//if a new key was pressed
	if (!IsKeyHeld(e.key.keysym.sym))
	{
		if (e.type == SDL_KEYDOWN)
		{
			//std::cout << "Key Pressed\n";
			downKeys.push_back(e.key.keysym.sym);
		}
	}

	//If a key was released
	if (e.type == SDL_KEYUP)
	{
		//std::cout << "Key Released\n";
		heldKeys.remove(e.key.keysym.sym);
		releasedKeys.push_back(e.key.keysym.sym);
	}

//Mouse Input
	//If a mouse button was clicked
	if (!IsMouseButtonHeld(e.button.button))
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			downClicks.push_back(e.button.button);
		}
	}

	//if a mouse button was released
	if (e.type == SDL_MOUSEBUTTONUP)
	{
		heldClicks.remove(e.button.button);
		releasedClicks.push_back(e.button.button);
	}

	//If the mouse cursor moves
	if (e.type == SDL_MOUSEMOTION)
	{
		mousePos.x = e.motion.x;
		mousePos.y = e.motion.y;
		//std::cout << "MousePos: " << mousePos.x << "," << mousePos.y;
	}
}

bool InputManager::IsKeyDown(SDL_Keycode key)
{
	std::list<SDL_Keycode>::iterator iter = std::find(downKeys.begin(), downKeys.end(), key);

	if (iter != downKeys.end())
	{
		return true;
	}

	return false;
}

bool InputManager::IsKeyHeld(SDL_Keycode key)
{
	std::list<SDL_Keycode>::iterator iter = std::find(heldKeys.begin(), heldKeys.end(), key);

	if (iter != heldKeys.end())
	{
		return true;
	}
	return false;
}

bool InputManager::IsKeyReleased(SDL_Keycode key)
{
	std::list<SDL_Keycode>::iterator iter = std::find(releasedKeys.begin(), releasedKeys.end(), key);

	if (iter != releasedKeys.end())
	{
		return true;
	}
	return false;
}



bool InputManager::IsMouseButtonDown(int mouseButtonIndex)
{
	std::list<SDL_Keycode>::iterator iter = std::find(downClicks.begin(), downClicks.end(), mouseButtonIndex);

	if (iter != downClicks.end())
	{
		return true;
	}
	return false;
}

bool InputManager::IsMouseButtonHeld(int mouseButtonIndex)
{
	std::list<SDL_Keycode>::iterator iter = std::find(heldClicks.begin(), heldClicks.end(), mouseButtonIndex);

	if (iter != heldClicks.end())
	{
		return true;
	}
	return false;
}

bool InputManager::IsMouseButtonReleased(int mouseButtonIndex)
{
	std::list<SDL_Keycode>::iterator iter = std::find(releasedClicks.begin(), releasedClicks.end(), mouseButtonIndex);

	if (iter != releasedClicks.end())
	{
		return true;
	}
	return false;
}

SDL_Point InputManager::GetMousePos()
{
	return mousePos;
}
