/**
 * @file usuarioNaoExisteException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe UsuarioNaoExisteException
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
 * @brief Classe UsuarioNaoExisteException que é lançada quando um usuário não esta cadastrado no sistema
 *
 */
class UsuarioNaoExisteException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Usuario Nao Existe Exception object
     *
     * @param nomeDeUsuario
     */
    UsuarioNaoExisteException(std::string nomeDeUsuario);

    /**
     * @brief Retorna a mensagem da exceção
     * 
     * @return const char* _msg
     */
    const char *what() const noexcept;
};