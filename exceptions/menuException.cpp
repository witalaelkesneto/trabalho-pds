#include "menuException.hpp"

const char* MenuException::what() const noexcept{
    return "Erro do sistema, menu não foi apagado"; 
}