#ifndef _IRENDERABLE_H_
#define _IRENDERABLE_H_
#pragma once

class IRenderable
{
public:
	IRenderable();
	~IRenderable();

protected:
	virtual void render(sf::RenderWindow* _window) = 0;

	friend class RenderSystem;
};

#endif