#pragma once

#include <iostream>
#include <string>

class HospitalExisteException : public std::exception
{
private:
    std::string _msg;

public:
    HospitalExisteException(std::string nome);
    const char *what() const noexcept;
};