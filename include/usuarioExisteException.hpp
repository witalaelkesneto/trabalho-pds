#pragma once

#include <iostream>
#include <string>

class UsuarioExisteException : public std::exception
{
private:
    std::string _msg;

public:
    UsuarioExisteException(std::string nomeDeUsuario);
    const char *what() const noexcept;
};