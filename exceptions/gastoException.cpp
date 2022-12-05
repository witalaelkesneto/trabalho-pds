#include "gastoException.hpp"

GastoException::GastoException(double valorGasto, double valorDisponivel){
    _msg = "Gasto de R$" + std::to_string(valorGasto) + " não pode ser realizado, pois o valor disponível é R$" + std::to_string(valorDisponivel);
}

const char* GastoException::what() const noexcept{
    return _msg.c_str(); 
}