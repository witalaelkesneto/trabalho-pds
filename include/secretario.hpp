#pragma once

#include "usuario.hpp"

#include "gastoException.hpp"


class Secretario : public Usuario{
    public:
    Secretario(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);
    virtual void printMenu() override;
    virtual void menu(std::vector<Usuario*> usuarios, std::vector<Hospital*> hospitais, double *valorTeto) override;
    void registrarGasto(std::vector<Hospital *> hospitais);
};