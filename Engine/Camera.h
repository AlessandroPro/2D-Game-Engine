#pragma once
#include "Component.h"
#include "Transform.h"

class Camera : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Camera, Component)

private:
	Transform* transform;

public:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON loadNode);
};

