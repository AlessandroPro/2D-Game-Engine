#pragma once
#include "Component.h"
class Camera : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Camera, Component)

protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& loadNode) override;
};

