#pragma once

#include <iostream>
#include <string>

class UsuarioNaoExisteException : public std::exception
{
private:
    std::string _msg;

public:
    UsuarioNaoExisteException(std::string nomeDeUsuario);
    const char *what() const noexcept;
};