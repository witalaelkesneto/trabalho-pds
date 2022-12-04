#pragma once

#include <iostream>
#include <string>

class SenhaErradaException : public std::exception
{
private:
    std::string _msg;

public:
    SenhaErradaException(std::string nomeDeUsuario);
    const char *what() const noexcept;
};