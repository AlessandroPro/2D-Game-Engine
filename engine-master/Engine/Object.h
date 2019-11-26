///-------------------------------------------------------------------------------------------------
// file: Object.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Object
///-------------------------------------------------------------------------------------------------
#ifndef _OBJECT_H_
#define _OBJECT_H_
#pragma once

class Object
{
	DECLARE_ABSTRACT_BASE_CLASS(Object)

protected:
	bool initialized = false;
	std::string name;

protected:
    Object();
    virtual ~Object();

public:
	void initialize();

	std::string getName() { return name; }
	bool isInitialized() { return initialized; }
};

#endif