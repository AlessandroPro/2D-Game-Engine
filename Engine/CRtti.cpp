#include "Core.h"
#include "CRtti.h"
#include "Object.h"

std::map<STRCODE, CRtti*>* CRtti::mRtti_classTable;

CRtti::CRtti(std::string _className, std::function<Object*()> ctor)
{
	mRtti_className = _className;
	mRtti_classhash = getHashCode(_className.c_str());
	mRtti_ctor = ctor;
	Register();
};

CRtti CRtti::getRtti(std::string _className)
{
	CRtti* _rtti = CRtti::findRttiClass(_className.c_str());
	return *_rtti;
}

Object* CreateObject(const char* _class)
{
	return CRtti::constructObject(_class);
};

Object* CRtti::constructObject() const
{
	return mRtti_ctor ? mRtti_ctor() : 0;
};

Object* CRtti::constructObject(const char* _class)
{
	return constructObject(getHashCode(_class));
};

Object* CRtti::constructObject(const STRCODE _class)
{
	CRtti* _rtti = CRtti::findRttiClass(_class);
	assert(_rtti);
	assert(_rtti->hasConstructor());

	Object* obj = _rtti->constructObject();
	return obj;
};

CRtti* CRtti::findRttiClass(const char* _class)
{
	return findRttiClass(getHashCode(_class));
};

CRtti* CRtti::findRttiClass(const STRCODE _class)
{
	if (mRtti_classTable == NULL)
	{
		return NULL;
	}

	std::map<STRCODE, CRtti*>::iterator _item = mRtti_classTable->find(_class);
	if (_item == mRtti_classTable->end())
	{
		assert(0);
	}

	return (*_item).second;
};

