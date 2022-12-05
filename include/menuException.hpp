/**
 * @file menuException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe MenuException
 * @version 0.1
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>

/**
 * @brief Classe MenuException que é lançada quando o menu não é apagado
 *
 */
class MenuException : public std::exception
{
public:
    /**
     * @brief Retorna a mensagem da exceção
     *
     * @return const char*
     */
    const char *what() const noexcept;
};