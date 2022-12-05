#include "hospitalExisteException.hpp"

HospitalExisteException::HospitalExisteException(std::string nome){
    _msg = "O hospital " + nome + " já está cadastrado no sistema";
}

const char* HospitalExisteException::what() const noexcept{
    return _msg.c_str(); 
}