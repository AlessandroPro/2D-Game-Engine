///-------------------------------------------------------------------------------------------------
// file: GameObject.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Transform
///-------------------------------------------------------------------------------------------------
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#pragma once

#include "Object.h"

class Component;

class GameObject final : public Object
{    
    DECLARE_DYNAMIC_DERIVED_CLASS(GameObject, Object)

public:
	void initialize() override;
    virtual void update(float deltaTime);

private:
    GameObject() = default;
    ~GameObject();

    friend class GameObjectManager;
};

#endif