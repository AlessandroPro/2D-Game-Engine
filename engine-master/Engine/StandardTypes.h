#ifndef _STANDARDTYPES_H_
#define _STANDARDTYPES_H_
#pragma once

#include <cstdlib>

#define USING_SFML			1
#define STRCODE				unsigned int
#define	NoName				0xf06a6692
#define UNIQUEID			int

#define	MATH_HALF_PI		(1.5707963267948966192313216916398f)
#define	MATH_PI				(3.1415926535897932384626433832795f)
#define MATH_2PI			(6.283185307179586476925286766559f)
#define	MATH_180_OVER_PI	(57.295779513082320876798154814105f)
#define	MATH_PI_OVER_180	(0.01745329251994329576923690768489f)

#define	RAD_TO_DEG(rad)		(rad*MATH_180_OVER_PI)
#define	DEG_TO_RAD(deg)		(deg*MATH_PI_OVER_180)

//#define DEBUG_PRINT
#ifdef _DEBUG
	#define LOG(out) std::cout << out << std::endl;
#else
#define LOG(out)
#endif

///-------------------------------------------------------------------------------------------------
/// <summary>	Gets a random float from 0.0 and 1.0. </summary>
///-------------------------------------------------------------------------------------------------
inline float randFloat()
{
	return static_cast<float>((rand()) / (RAND_MAX + 1.0f));
}

///-------------------------------------------------------------------------------------------------
/// <summary>	Gets the a random value clamped between -1.0 and 1.0. </summary>
///-------------------------------------------------------------------------------------------------
inline float randomClamped()
{
	return randFloat() - randFloat();
}

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines maximum. </summary>
///-------------------------------------------------------------------------------------------------
//#define max(a,b)            (((a) > (b)) ? (a) : (b))

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines minimum. </summary>
///-------------------------------------------------------------------------------------------------
//#define min(a,b)            (((a) < (b)) ? (a) : (b))

///-------------------------------------------------------------------------------------------------
/// <summary>	Generates a hash code using FVN-1. </summary>
///-------------------------------------------------------------------------------------------------
inline STRCODE getHashCode(const char* str)
{
	const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	char end = '\0';

	for (const char* ref = str; *ref != end; ref++)
	{
		hash *= fnv_prime;
		hash ^= *ref;
	}

	return hash;
}

inline void CreateUUID(UUID* uid)
{
	UuidCreate(uid);
}

inline std::string GUIDTostring(UUID& guid)
{
	char guid_string[37];
	sprintf_s(
	          guid_string,
	          "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
	          guid.Data1, guid.Data2, guid.Data3,
	          guid.Data4[0], guid.Data4[1], guid.Data4[2],
	          guid.Data4[3], guid.Data4[4], guid.Data4[5],
	          guid.Data4[6], guid.Data4[7]);
	return guid_string;
}

inline STRCODE GUIDToSTRCODE(UUID& guid)
{
	return getHashCode(GUIDTostring(guid).c_str());
}

#define THROW_RUNTIME_ERROR(condition, message)		\
	if (condition)								\
	{											\
		throw std::runtime_error(message);		\
	}


#ifndef NDEBUG
///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines assert. </summary>
///
/// <remarks>	William Barry, 05/02/2013. </remarks>
///
/// <param name="condition">	The condition. </param>
/// <param name="message">  	The message. </param>
///-------------------------------------------------------------------------------------------------
#define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif

#endif

