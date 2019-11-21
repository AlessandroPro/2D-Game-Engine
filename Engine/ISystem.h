///-------------------------------------------------------------------------------------------------
// file: GameEngine.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Game Engine
///-------------------------------------------------------------------------------------------------
#ifndef _ISYSTEM_H_
#define _ISYSTEM_H_
#pragma once

class ISystem
{
protected:
    virtual void initialize() = 0;
    virtual void update(float deltaTime) = 0;

    friend class GameEngine;
};

#endif