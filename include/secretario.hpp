/**
 * @file secretario.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe Secretario
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "usuario.hpp"

#include "gastoException.hpp"

/**
 * @brief Classe Secretario
 * 
 */
class Secretario : public Usuario{
    public:
    /**
     * @brief Construct a new Secretario object
     * 
     * @param nomeDeUsuario 
     * @param senha 
     * @param nomeCompleto 
     * @param tipo 
     */
    Secretario(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);

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

    /**
     * @brief Registrar gasto de um hospital
     * 
     * @param hospitais 
     */
    void registrarGasto(std::vector<Hospital *> hospitais);
};