#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <string>

class FileException : public std::exception {
public:
    explicit FileException(const std::string& msg);

    virtual const char* what() const noexcept override;

private:
    std::string m_message;
};