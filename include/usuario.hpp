#pragma once

#include <string>
#include <vector>

#include "hospital.hpp"

#include "menuException.hpp"
#include "usuarioExisteException.hpp"
#include "hospitalNaoExisteException.hpp"

class Usuario
{
private:
    std::string _nomeDeUsuario;
    std::string _senha;
    std::string _nomeCompleto;
    std::string _tipo;

public:
    Usuario(std::string nomeDeUsuario, std::string senha, std::string nome, std::string tipo);
    void setNomeDeUsuario(std::string nomeDeUsuario);
    std::string getNomeDeUsuario();
    void setNomeCompleto(std::string nome);
    std::string getNomeCompleto();
    void setSenha(std::string senha);
    std::string getSenha();
    void setTipo(std::string tipo);
    std::string getTipo();
    virtual void printMenu() = 0;
    virtual void menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto) = 0;
    void printHospitais(std::vector<Hospital *> hospitais, double *valorTeto);
    double valorTotalOrcado(std::vector<Hospital *> hospitais);
    void alterarDados(std::vector<Usuario *> usuarios);
    bool naoExisteUsuario(std::vector<Usuario *> usuarios, std::string nomeDeUsuario);
    bool existeHospital(std::vector<Hospital *> hospitais, std::string nome);
    Hospital* getHospital(std::vector<Hospital *> hospitais, std::string nome);
};