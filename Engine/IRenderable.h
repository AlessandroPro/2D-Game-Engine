#ifndef _IRENDERABLE_H_
#define _IRENDERABLE_H_
#pragma once
#include "RenderSystem.h"


class IRenderable
{
public:
	IRenderable();
	~IRenderable();
protected:
	virtual void render(sf::RenderWindow* _window) = 0;
	RenderSystem::RenderLayer layer = RenderSystem::RenderLayer::Environment;
	friend class RenderSystem;
	void setRenderLayer(RenderSystem::RenderLayer inLayer) { layer = inLayer; }
	RenderSystem::RenderLayer getRenderLayer() { return layer; }
};

#endif