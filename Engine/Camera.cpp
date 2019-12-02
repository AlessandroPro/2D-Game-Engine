#include "Core.h"
#include "RenderSystem.h"
#include "GameObject.h"
#include "Transform.h"
#include "Camera.h"

IMPLEMENT_DYNAMIC_CLASS(Camera)

void Camera::initialize()
{
	if (!isEnabled())
	{
		return;
	}
	Component::initialize();
}


void Camera::update(float deltaTime)
{
	if (!getGameObject()->isEnabled() || !enabled)
	{
		return;
	}

	if(getGameObject()->getTransform() != nullptr)
	{
		//Update the position of the view on the window to be equal to the position of the transform of the camera object
		RenderSystem::instance().currentView.setCenter(getGameObject()->getTransform()->getPosition());
	}
}

void Camera::load(json::JSON& loadNode)
{
	Component::load(loadNode);
}