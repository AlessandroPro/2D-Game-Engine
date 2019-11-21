///-------------------------------------------------------------------------------------------------
// file: InputManager.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Input Manager
///-------------------------------------------------------------------------------------------------
#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_
#pragma once

#include "ISystem.h"

class InputManager final : public ISystem
{
protected:
    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(InputManager)
};

#endif