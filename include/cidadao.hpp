#pragma once

#include <iostream>

#include "usuario.hpp"

class Cidadao : public Usuario{
    public:
    Cidadao(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);
    virtual void printMenu() override;
    virtual void menu(std::vector<Usuario*> usuarios, std::vector<Hospital*> hospitais, double *valorTeto) override;
};