#pragma once

#include <iostream>
#include <string>

class TipoInvalidoException : public std::exception
{
private:
    std::string _msg;

public:
    TipoInvalidoException(std::string tipo);
    const char *what() const noexcept;
};