#pragma once

#include "usuario.hpp"

#include "gastoException.hpp"
#include "tetoException.hpp"
#include "hospitalExisteException.hpp"

class Prefeito : public Usuario
{
public:
    Prefeito(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);
    virtual void printMenu() override;
    virtual void menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto) override;
    void registrarGasto(std::vector<Hospital *> hospitais);
    void definirTeto(std::vector<Hospital *> hospitais, double *valorTeto);
    void cadastrarHospital(std::vector<Hospital *> &hospitais, double *valorTeto);
    bool naoExisteHospital(std::vector<Hospital *> hospitais, std::string nome);
    void movimentarOrcamento(std::vector<Hospital *> hospitais);
};