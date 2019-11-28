#include "Core.h"
#include "Sprite.h"
#include "GameObject.h"
#include "RenderSystem.h"

IMPLEMENT_ABSTRACT_CLASS(Sprite)

void Sprite::initialize()
{
    Component::initialize();
}

void Sprite::render(sf::RenderWindow* _window)
{
}
