/**
 * @file usuario.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe Usuario
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <string>
#include <vector>

#include "hospital.hpp"

#include "menuException.hpp"
#include "usuarioExisteException.hpp"
#include "hospitalNaoExisteException.hpp"

/**
 * @brief Classe Usuario
 *
 */
class Usuario
{
private:
    std::string _nomeDeUsuario;
    std::string _senha;
    std::string _nomeCompleto;
    std::string _tipo;

public:
    /**
     * @brief Construct a new Usuario object
     *
     * @param nomeDeUsuario
     * @param senha
     * @param nomeCompleto
     * @param tipo
     */
    Usuario(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);

    /**
     * @brief Set the Nome De Usuario object
     * 
     * @param nomeDeUsuario 
     */
    void setNomeDeUsuario(std::string nomeDeUsuario);

    /**
     * @brief Get the Nome De Usuario object
     * 
     * @return std::string _nomeDeUsuario
     */
    std::string getNomeDeUsuario();

    /**
     * @brief Set the Nome Completo object
     * 
     * @param nomeCompleto 
     */
    void setNomeCompleto(std::string nomeCompleto);

    /**
     * @brief Get the Nome Completo object
     * 
     * @return std::string _nomeCompleto
     */
    std::string getNomeCompleto();

    /**
     * @brief Set the Senha object
     * 
     * @param senha 
     */
    void setSenha(std::string senha);

    /**
     * @brief Get the Senha object
     * 
     * @return std::string _senha
     */
    std::string getSenha();

    /**
     * @brief Set the Tipo object
     * 
     * @param tipo 
     */
    void setTipo(std::string tipo);

    /**
     * @brief Get the Tipo object
     * 
     * @return std::string _tipo
     */
    std::string getTipo();

    /**
     * @brief Imprime o menu do usuário que está logado
     * 
     */
    virtual void printMenu() = 0;

    /**
     * @brief Implementa menu do usuário que está logado 
     * 
     * @param usuarios 
     * @param hospitais 
     * @param valorTeto 
     */
    virtual void menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto) = 0;

    /**
     * @brief Imprime todos os hospitais
     * 
     * @param hospitais 
     * @param valorTeto 
     */
    void printHospitais(std::vector<Hospital *> hospitais, double *valorTeto);

    /**
     * @brief Calcula o valor total orçado
     * 
     * @param hospitais 
     * @return double 
     */
    double valorTotalOrcado(std::vector<Hospital *> hospitais);

    /**
     * @brief Altera os dados dos usuários
     * 
     * @param usuarios 
     */
    void alterarDados(std::vector<Usuario *> usuarios);

    /**
     * @brief Verifica se o usuário não está cadastrado
     * 
     * @param usuarios 
     * @param nomeDeUsuario 
     * @return true 
     * @return false 
     */
    bool naoExisteUsuario(std::vector<Usuario *> usuarios, std::string nomeDeUsuario);

    /**
     * @brief Verifica se o hospital está cadastrado
     * 
     * @param hospitais 
     * @param nome 
     * @return true 
     * @return false 
     */
    bool existeHospital(std::vector<Hospital *> hospitais, std::string nome);

    /**
     * @brief Get the Hospital object
     * 
     * @param hospitais 
     * @param nome 
     * @return Hospital* 
     */
    Hospital *getHospital(std::vector<Hospital *> hospitais, std::string nome);
};