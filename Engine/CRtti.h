#ifndef _RTTI_H_
#define _RTTI_H_
#pragma once

class Object;

class CRtti
{
public:
	CRtti(std::string _className, std::function<Object*()> ctor);

	Object* constructObject() const;

	const bool hasConstructor()
	{
		return mRtti_ctor ? true : false;
	}

	const std::string& getClassName() const
	{
		return mRtti_className;
	}

	const STRCODE getClassHashCode() const
	{
		return mRtti_classhash;
	}

	static CRtti getRtti(std::string _className);

	static Object* constructObject(const char* _class);
	static Object* constructObject(const STRCODE _class);

	static CRtti* findRttiClass(const char* _class);
	static CRtti* findRttiClass(const STRCODE _class);

protected:

	void Register()
	{
		if (mRtti_classTable == nullptr)
		{
			mRtti_classTable = new std::map<STRCODE, CRtti*>();
		}
		mRtti_classTable->insert(mRtti_pair(getHashCode(mRtti_className.c_str()), this));
	};

private:
	static std::map<STRCODE, CRtti*>* mRtti_classTable;

	STRCODE mRtti_classhash;
	std::string mRtti_className;
	std::function<Object*()> mRtti_ctor;

	typedef std::pair<STRCODE, CRtti*> mRtti_pair;
};

///-------------------------------------------------------------------------------------------------
/// <summary>	External Functions for easy implementation. </summary>
///-------------------------------------------------------------------------------------------------
extern Object* CreateObject(const char* _class);

///-------------------------------------------------------------------------------------------------
/// <summary>	Class Definition used by all. </summary>
///-------------------------------------------------------------------------------------------------
#define DECLARE_CLASS_DEFINITION(name)																						\
    public:																													\
		static std::string __class##name;																					\
        static CRtti mRtti_staticClassInfo_##name;																			\
		static const std::string& getClassName() { return name::mRtti_staticClassInfo_##name.getClassName(); }				\
		static const STRCODE getClassHashCode() { return name::mRtti_staticClassInfo_##name.getClassHashCode(); }			\
		virtual const std::string& getDerivedClassName() { return name::__class##name; }									\
		virtual const STRCODE getDerivedClassHashCode() { return name::mRtti_staticClassInfo_##name.getClassHashCode(); }

///-------------------------------------------------------------------------------------------------
/// <summary>	IsA Definition used by all. </summary>
///-------------------------------------------------------------------------------------------------
#define IS_A_BASE_DEFINITION(name)																								\
		virtual bool isA(STRCODE className)																					\
		{																													\
			return (className == name::mRtti_staticClassInfo_##name.getClassHashCode() ? true : false);														\
		}

#define IS_A_DEFINITION(name, base)																							\
		virtual bool isA(STRCODE className)																					\
		{																													\
			return (className == getClassHashCode() ? true : base::isA(className));											\
		}

///-------------------------------------------------------------------------------------------------
/// <summary>	Declaration for Abstract Classes. </summary>
///-------------------------------------------------------------------------------------------------
#define DECLARE_ABSTRACT_BASE_CLASS(name)																						\
    public:																													\
		DECLARE_CLASS_DEFINITION(name)																						\
		IS_A_BASE_DEFINITION(name)

#define DECLARE_ABSTRACT_DERIVED_CLASS(name, base)																					\
    public:																													\
		DECLARE_CLASS_DEFINITION(name)																						\
		IS_A_DEFINITION(name, base)


#define IMPLEMENT_ABSTRACT_CLASS(name)																						\
	std::string name::__class##name = #name;																				\
    CRtti name::mRtti_staticClassInfo_##name(std::string(#name), nullptr);

#define REGISTER_ABSTRACT_CLASS(name)																						\
   name::mRtti_staticClassInfo_##name = CRtti::getRtti(std::string(#name));	

///-------------------------------------------------------------------------------------------------
/// <summary>	Declaration for Dynamic Classes. </summary>
///-------------------------------------------------------------------------------------------------
#define DECLARE_CREATE_CLASS(name)																							\
		static Object* Rtti_createObject();																					\
		static name* Create() { return new name; }

#define DECLARE_DYNAMIC_BASE_CLASS(name)																							\
    public:																													\
		DECLARE_CLASS_DEFINITION(name)																						\
		DECLARE_CREATE_CLASS(name)																							\
		IS_A_BASE_DEFINITION(name)

#define DECLARE_DYNAMIC_DERIVED_CLASS(name, base)																					\
    public:																													\
		DECLARE_CLASS_DEFINITION(name)																						\
		DECLARE_CREATE_CLASS(name)																							\
		IS_A_DEFINITION(name, base)

#define IMPLEMENT_DYNAMIC_CLASS(name)																						\
	std::string name::__class##name = #name;																				\
	CRtti name::mRtti_staticClassInfo_##name(std::string(#name), name::Rtti_createObject);									\
    Object* name::Rtti_createObject() { return new name; }

#define REGISTER_DYNAMIC_CLASS(name)																						\
   name::mRtti_staticClassInfo_##name = CRtti::getRtti(std::string(#name));	


#endif

