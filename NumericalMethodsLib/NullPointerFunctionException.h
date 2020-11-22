#pragma once
#include <string>

class NullPointerFunctionException final : std::exception
{
	std::string m_error = "The required function was nullptr";
public:
	NullPointerFunctionException() {}
	const char* what() noexcept { return m_error.c_str(); }
};
