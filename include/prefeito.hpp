/**
 * @file prefeito.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe Prefeito
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "usuario.hpp"

#include "gastoException.hpp"
#include "tetoException.hpp"
#include "hospitalExisteException.hpp"

/**
 * @brief Classe Prefeito
 * 
 */
class Prefeito : public Usuario
{
public:
    /**
     * @brief Construct a new Prefeito object
     *
     * @param nomeDeUsuario
     * @param senha
     * @param nomeCompleto
     * @param tipo
     */
    Prefeito(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo);

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
    virtual void menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto) override;

    /**
     * @brief Registrar gasto de um hospital
     * 
     * @param hospitais 
     */
    void registrarGasto(std::vector<Hospital *> hospitais);

    /**
     * @brief Definir o teto de gastos
     * 
     * @param hospitais 
     * @param valorTeto 
     */
    void definirTeto(std::vector<Hospital *> hospitais, double *valorTeto);

    /**
     * @brief Cadastrar um novo hospital
     * 
     * @param hospitais 
     * @param valorTeto 
     */
    void cadastrarHospital(std::vector<Hospital *> &hospitais, double *valorTeto);

    /**
     * @brief Verifica se um hospital não está cadastrado no sistema
     * 
     * @param hospitais 
     * @param nome 
     * @return true 
     * @return false 
     */
    bool naoExisteHospital(std::vector<Hospital *> hospitais, std::string nome);

    /**
     * @brief Movimenta o orçamento entre hospitais
     * 
     * @param hospitais 
     */
    void movimentarOrcamento(std::vector<Hospital *> hospitais);
};