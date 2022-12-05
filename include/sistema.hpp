/**
 * @file sistema.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe Sistema
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
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

/**
 * @brief Classe Sistema
 *
 */
class Sistema
{
private:
    double *_valorTeto;
    int _quantidadeUsuarios;
    std::string _nomeDeUsuario;
    std::string _senha;
    std::vector<Usuario *> _usuarios;
    std::vector<Hospital *> _hospitais;

public:
    /**
     * @brief Construct a new Sistema object
     *
     */
    Sistema();

    /**
     * @brief Implementa menu inicial do sistema
     * 
     */
    void menu();

    /**
     * @brief Implementa menu inicial do sistema
     * 
     */
    void printMenuInicial();

    /**
     * @brief Get the Usuario object
     * 
     * @param nomeDeUsuario 
     * @return Usuario* 
     */
    Usuario *getUsuario(std::string nomeDeUsuario);

    /**
     * @brief Realiza o login do usuário
     * 
     * @return Usuario* 
     */
    Usuario *login();

    /**
     * @brief Cadastra um usuário no sistema
     * 
     */
    void cadastro();

    /**
     * @brief Verifica se o usuário existe no sistema
     * 
     * @param nomeDeUsuario 
     * @return true 
     * @return false 
     */
    bool existeUsuario(std::string nomeDeUsuario);

    /**
     * @brief Verifica se a senha informada é igual a senha que foi cadastrada para aquele usuário
     * 
     * @param nomeDeUsuario 
     * @param senha 
     * @return true 
     * @return false 
     */
    bool verificaSenha(std::string nomeDeUsuario, std::string senha);

    /**
     * @brief Verifica se o usuário não está cadastrado no sistema
     * 
     * @param nomeDeUsuario 
     * @return true 
     * @return false 
     */
    bool naoExisteUsuario(std::string nomeDeUsuario);
};