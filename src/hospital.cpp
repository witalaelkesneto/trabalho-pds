#include "hospital.hpp"

Hospital::Hospital(std::string nome, double valorDisponivel)
{
    _nome = nome;
    _valorDisponivel = valorDisponivel;
}

void Hospital::imprimir(){
    std::cout << "Nome: " << _nome << ", Orçamento disponível: R$ " << std::fixed << std::setprecision(2) << _valorDisponivel << std::endl;
}

double Hospital::getValorDisponivel(){
    return _valorDisponivel;
}

std::string Hospital::getNome(){
    return _nome;
}

void Hospital::reduzirOrcamento(double valor){
    _valorDisponivel -= valor;
}

void Hospital::aumentarOrcamento(double valor){
    _valorDisponivel += valor;
}

