#include "tetoException.hpp"

TetoException::TetoException(double valorOrcado, double valorTeto){
    _msg = "Teto de R$" + std::to_string(valorTeto) + " indisponível, pois o valor orçado é R$" + std::to_string(valorOrcado);
}

const char* TetoException::what() const noexcept{
    return _msg.c_str(); 
}