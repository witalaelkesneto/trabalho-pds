#pragma once

#include <iostream>
#include <vector>

#include "cidadao.hpp"
#include "secretario.hpp"
#include "prefeito.hpp"
#include "hospital.hpp"

#include "menuException.hpp"
#include "usuarioNaoExisteException.hpp"
#include "usuarioExisteException.hpp"
#include "senhaErradaException.hpp"
#include "tipoInvalidoException.hpp"

class Sistema
{
private:
    double *_valorTeto;
    int _quantidadeUsuarios;
    std::string _nomeDeUsuario;
    std::string _senha;
    std::vector<Usuario*> _usuarios;
    std::vector<Hospital*> _hospitais;

public:
    Sistema();
    void menu();
    void printMenuInicial();
    Usuario* getUsuario(std::string nomeDeUsuario);
    Usuario* login();
    void cadastro();
    bool existeUsuario(std::string nomeDeUsuario);
    bool verificaSenha(std::string nomeDeUsuario, std::string senha);
    bool naoExisteUsuario(std::string nomeDeUsuario);
};