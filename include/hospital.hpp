#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Hospital{
    private:
    std::string _nome;
    double _valorDisponivel;

    public:
    Hospital(std::string nome, double valorDisponivel);
    double getValorDisponivel();
    std::string getNome();
    void imprimir();
    void reduzirOrcamento(double valor);
    void aumentarOrcamento(double valor);
};