/**
 * @file tetoException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe TetoException
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <string>

class TetoException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Teto Exception object
     *
     * @param valorOrcado
     * @param valorTeto
     */
    TetoException(double valorOrcado, double valorTeto);
    /**
     * @brief Retorna a mensagem da exceção
     * 
     * @return const char*  _msg
     */
    const char *what() const noexcept;
};