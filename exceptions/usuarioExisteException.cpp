#include "usuarioExisteException.hpp"

UsuarioExisteException::UsuarioExisteException(std::string nomeDeUsuario){
    _msg = "O usuário " + nomeDeUsuario + " já está cadastrado no sistema";
}

const char* UsuarioExisteException::what() const noexcept{
    return _msg.c_str(); 
}