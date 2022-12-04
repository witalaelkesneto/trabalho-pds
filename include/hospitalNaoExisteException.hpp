#pragma once

#include <iostream>
#include <string>

class HospitalNaoExisteException : public std::exception
{
private:
    std::string _msg;

public:
    HospitalNaoExisteException(std::string nome);
    const char *what() const noexcept;
};