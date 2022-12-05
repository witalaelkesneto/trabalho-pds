/**
 * @file cidadao.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe Cidadao
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>

#include "usuario.hpp"

/**
 * @brief Classe Cidadao
 * 
 */
class Cidadao : public Usuario{
    public:

    /**
     * @brief Construct a new Cidadao object
     * 
     * @param nomeDeUsuario 
     * @param senha 
     * @param nomeCompleto 
     * @param tipo 
     */
    Cidadao(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);
    
    /**
     * @brief Imprime o menu do usuário que está logado
     * 
     */
    virtual void printMenu() override;

    /**
     * @brief Implementa menu do usuário que está logado 
     * 
     * @param usuarios 
     * @param hospitais 
     * @param valorTeto 
     */
    virtual void menu(std::vector<Usuario*> usuarios, std::vector<Hospital*> hospitais, double *valorTeto) override;
};