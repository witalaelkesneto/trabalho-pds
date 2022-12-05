/**
 * @file senhaErradaException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe SenhaErradaException
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
 * @brief Classe SenhaErradaException que é lançada quando a senha inserida não é igual a que foi cadastrada
 *
 */
class SenhaErradaException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Senha Errada Exception object
     *
     * @param nomeDeUsuario
     */
    SenhaErradaException(std::string nomeDeUsuario);
    /**
     * @brief Retorna a mensagem da exceção
     *
     * @return const char*
     */
    const char *what() const noexcept;
};