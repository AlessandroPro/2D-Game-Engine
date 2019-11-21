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
    Object() = default;
    virtual ~Object() = default;

public:
	virtual void initialize();
};

#endif