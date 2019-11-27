///-------------------------------------------------------------------------------------------------
// file: Object.h
// summary:	The Object
///-------------------------------------------------------------------------------------------------
#ifndef _OBJECT_H_
#define _OBJECT_H_
#pragma once

#include "json.hpp"

class Object
{
	DECLARE_ABSTRACT_BASE_CLASS(Object)

protected:
	bool initialized = false;
	STRCODE id = -1;
	std::string guid;

protected:
    Object();
    virtual ~Object() = default;

public:
	virtual void initialize();
	virtual void load(json::JSON& node);
	bool isInitialized();
	STRCODE getID();
	const std::string& getGUID();
};

#endif