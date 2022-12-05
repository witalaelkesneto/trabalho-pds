/**
 * @file gastoException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe GastoException
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <string>

/**
 * @brief Classe Gastoexception que é lançada quando um gasto ultrapassa o valor disponível pra orçamento
 *
 */
class GastoException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Gasto Exception object
     *
     * @param valorGasto
     * @param valorDisponivel
     */
    GastoException(double valorGasto, double valorDisponivel);

    /**
     * @brief Retorna a mensagem da exceção
     * 
     * @return const char* _msg
     */
    const char *what() const noexcept;
};