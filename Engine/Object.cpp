#include "Core.h"
#include "Object.h"

IMPLEMENT_ABSTRACT_CLASS(Object)


Object::Object()
{
	UUID uid;
	CreateUUID(&uid);

	id = GUIDToSTRCODE(uid);
	guid = GUIDTostring(uid);
}

void Object::initialize()
{
	initialized = true;
}

void Object::load(json::JSON& node)
{
	_ASSERT_EXPR(node.hasKey("guid"), "JSON node missing guid.");

	guid = node["guid"].ToString();
	id = GUIDToSTRCODE(guid);
}

bool Object::isInitialized()
{
	return isInitialized;
}

STRCODE Object::getID()
{
	return id;
}

const std::string& Object::getGUID()
{
	return guid;
}
