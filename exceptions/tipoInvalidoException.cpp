#include "tipoInvalidoException.hpp"

TipoInvalidoException::TipoInvalidoException(std::string tipo){
    _msg = "Tipo de usuário " + tipo + " inválido";
}

const char* TipoInvalidoException::what() const noexcept{
    return _msg.c_str(); 
}