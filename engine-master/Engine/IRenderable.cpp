#include "Core.h"
#include "IRenderable.h"
#include "RenderSystem.h"

IRenderable::IRenderable()
{
	RenderSystem::instance().addRenderable(this);
}

IRenderable::~IRenderable()
{
	RenderSystem::instance().removeRenderable(this);
}
