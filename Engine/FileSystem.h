///-------------------------------------------------------------------------------------------------
// file: FileSystem.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The File System
///-------------------------------------------------------------------------------------------------
#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_
#pragma once

#include "ISystem.h"

class FileSystem final : public ISystem
{
protected:
    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(FileSystem)
};

#endif