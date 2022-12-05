#include "senhaErradaException.hpp"

SenhaErradaException::SenhaErradaException(std::string nomeDeUsuario){
    _msg = "A senha do usuário " + nomeDeUsuario + " está incorreta";
}

const char* SenhaErradaException::what() const noexcept{
    return _msg.c_str(); 
}