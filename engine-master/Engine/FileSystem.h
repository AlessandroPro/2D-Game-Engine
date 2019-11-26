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

class FileSystem
{
public:
    static FileSystem& instance()
    {
        static FileSystem _instance;
        return _instance;
    }

    void initialize();
    void update();

private:
    FileSystem() = default;
    ~FileSystem() = default;
    FileSystem(FileSystem const&) = delete;
};

#endif