#include "FileException.h"

FileException::FileException(const std::string& msg)
	: m_message(msg)
{
}

const char* FileException::what() const noexcept
{
	return m_message.c_str();
}
