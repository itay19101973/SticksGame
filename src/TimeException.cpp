#include "TimeException.h"


TimeException::TimeException(const std::string& msg)
	: m_message(msg)
{
}

const char* TimeException::what() const noexcept
{
	return m_message.c_str();
}