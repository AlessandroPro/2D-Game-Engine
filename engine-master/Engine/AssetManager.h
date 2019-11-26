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

class AssetManager
{
public:
    static AssetManager& instance()
    {
        static AssetManager _instance;
        return _instance;
    }

    void initialize();
    void update();

private:
    AssetManager() = default;
    ~AssetManager() = default;
    AssetManager(AssetManager const&) = delete;
};

#endif