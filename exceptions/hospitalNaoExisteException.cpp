#include "hospitalNaoExisteException.hpp"

HospitalNaoExisteException::HospitalNaoExisteException(std::string nome){
    _msg = "O hospital " + nome + " não está cadastrado no sistema";
}

const char* HospitalNaoExisteException::what() const noexcept{
    return _msg.c_str(); 
}