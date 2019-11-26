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

