#include "Core.h"
#include "Object.h"

IMPLEMENT_ABSTRACT_CLASS(Object)

Object::Object()
	: name()
{
}

Object::~Object()
{
}

void Object::initialize()
{
	initialized = true;
}

