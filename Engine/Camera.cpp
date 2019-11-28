#include "Core.h"
#include "Camera.h"
#include "RenderSystem.h"
#include "GameObject.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(Camera)

void Camera::initialize()
{
	Component::initialize();
}

void Camera::update(float deltaTime)
{
	Component::update(deltaTime);
	GameObject* cameraObject = getGameObject();
	//RenderSystem::instance().currentView.setCenter(cameraObject->getTransform()->getPosition());
}