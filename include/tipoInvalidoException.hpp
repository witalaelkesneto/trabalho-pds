/**
 * @file tipoInvalidoException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe TipoInvalidoException
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
 * @brief Classe TipoInvalidoException que é lançada quando um tipo não for reconhecido pelo sistema
 *
 */
class TipoInvalidoException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Tipo Invalido Exception object
     *
     * @param tipo
     */
    TipoInvalidoException(std::string tipo);

    /**
     * @brief Retorna a mensagem da exceção
     * 
     * @return const char* 
     */
    const char *what() const noexcept;
};