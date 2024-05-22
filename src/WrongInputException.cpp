#include "WrongInputException.h"


WrongInputException::WrongInputException(const std::string& msg)
	: m_message(msg)
{
}

const char* WrongInputException::what() const noexcept
{
	return m_message.c_str();
}