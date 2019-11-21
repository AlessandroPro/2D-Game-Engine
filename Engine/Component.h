///-------------------------------------------------------------------------------------------------
// file: Component.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	Component
///-------------------------------------------------------------------------------------------------
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#pragma once

#include "Object.h"

class GameObject;

class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object)

public:
    void initialize() override;
	virtual void update(float deltaTime);
};

#endif 