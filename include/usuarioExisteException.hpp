/**
 * @file usuarioExisteException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief
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
 * @brief Classe UsuarioExisteException que é lançada quando um usuário ja esta cadastrado no sistema
 *
 */
class UsuarioExisteException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Usuario Existe Exception object
     *
     * @param nomeDeUsuario
     */
    UsuarioExisteException(std::string nomeDeUsuario);
    /**
     * @brief Retorna a mensagem da exceção
     *
     * @return const char* _msg
     */
    const char *what() const noexcept;
};