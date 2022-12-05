/**
 * @file hospital.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe Hospital
 * @version 0.1
 * @date 2022-12-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include <iomanip>

/**
 * @brief Classe Hospital
 * 
 */
class Hospital{
    private:
    std::string _nome;
    double _valorDisponivel;

    public:
    /**
     * @brief Construct a new Hospital object
     * 
     * @param nome 
     * @param valorDisponivel 
     */
    Hospital(std::string nome, double valorDisponivel);

    /**
     * @brief Get the Valor Disponivel object
     * 
     * @return double _valorDisponivel
     */
    double getValorDisponivel();

    /**
     * @brief Get the Nome object
     * 
     * @return std::string _nome
     */
    std::string getNome();

    /**
     * @brief Imprime o objeto Hospital
     * 
     */
    void imprimir();

    /**
     * @brief Reduz um valor do orçamento
     * 
     * @param valor 
     */
    void reduzirOrcamento(double valor);

    /**
     * @brief Aumenta um valor do orçamento
     * 
     * @param valor 
     */
    void aumentarOrcamento(double valor);
};