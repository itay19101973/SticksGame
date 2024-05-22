#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <string>

class TimeException : public std::exception {
public:
    explicit TimeException(const std::string& msg);

    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};