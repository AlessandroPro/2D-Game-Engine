#include "Core.h"
#include "Camera.h"
#include "RenderSystem.h"
#include "GameObject.h"
#include "Transform.h"
#include "Component.h"

IMPLEMENT_DYNAMIC_CLASS(Camera)

void Camera::initialize()
{
	Component::initialize();

	if (transform == nullptr)
	{
		transform = getGameObject()->getTransform();
	}
}

void Camera::update(float deltaTime)
{
	if(transform != nullptr)
	{
		//Update the position of the view on the window to be equal to the position of the transform of the camera object
		RenderSystem::instance().currentView.setCenter(transform->getPosition());
	}
}

void Camera::load(json::JSON loadNode)
{
	Component::load(loadNode);
}