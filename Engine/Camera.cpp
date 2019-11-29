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
}

void Camera::update(float deltaTime)
{
	GameObject* cameraObject = getGameObject();
	sf::Vector2f cameraPosition = cameraObject->getTransform()->getPosition();
	RenderSystem::instance().currentView.setCenter(cameraPosition);
}