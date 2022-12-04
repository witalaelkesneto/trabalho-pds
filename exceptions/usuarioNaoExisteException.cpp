#include "usuarioNaoExisteException.hpp"

UsuarioNaoExisteException::UsuarioNaoExisteException(std::string nomeDeUsuario){
    _msg = "O usuário " + nomeDeUsuario + " não está cadastrado no sistema";
}

const char* UsuarioNaoExisteException::what() const noexcept{
    return _msg.c_str(); 
}