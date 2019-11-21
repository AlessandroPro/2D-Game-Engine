///-------------------------------------------------------------------------------------------------
// file: RenderSystem.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Render System
///-------------------------------------------------------------------------------------------------
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_
#pragma once

#include "ISystem.h"

class IRenderable;

class RenderSystem final : public ISystem
{
protected:
	void initialize() override;
	void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(RenderSystem)
};

#endif