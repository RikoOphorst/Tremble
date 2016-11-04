#pragma once

#include <iostream>
#define _WINSOCK2API_
#define _WINSOCKAPI_   /* Prevent inclusion of winsock.h in windows.h */
#include <Windows.h>
#undef _WINSOCK2API_
#undef _WINSOCKAPI_

#include <assert.h>

#define ASSERT assert

/**
* @def DLOG(s)
* Outputs a string to visual studio's output window and to the console
*/
#define DLOG( s )            \
{                             \
	OutputDebugStringA("\nDEBUG LOG: "); \
	OutputDebugStringA(s); \
	OutputDebugStringA("\n"); \
	std::cout << "DEBUG LOG: " << s << std::endl; \
}

#define DEBUG_LOG(s) DLOG(s)

/**
* helper function for showing bits
* @param[in] val The value you want to convert to a bit string
*/
template<typename T>
inline std::string ConvertToBinaryString(T val)
{
	std::string result = "";

	const char* beg = reinterpret_cast<const char*>(&val);
	const char* end = beg + sizeof(val);
	while (beg != end)
	{
		result += std::bitset<8>(*--end).to_string() + ' ';
	}

	return result;
}