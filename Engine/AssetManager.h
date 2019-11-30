///-------------------------------------------------------------------------------------------------
// file: AssetManager.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Asset Manager
///-------------------------------------------------------------------------------------------------
#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_
#pragma once

#include "ISystem.h"

class AssetManager final : public ISystem
{
protected:
    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(AssetManager)
};

#endif