/**
 * @file hospitalNaoExisteException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arquivo da classe HospitalNaoExisteException
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
 * @brief Classe HospitalNaoExisteException que é lançada quando um hospital não esta cadastrado no sistema
 *
 */
class HospitalNaoExisteException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Hospital Nao Existe Exception object
     *
     * @param nome
     */
    HospitalNaoExisteException(std::string nome);

    /**
     * @brief Retorna a mensagem da exceção
     * 
     * @return const char* _msg
     */
    const char *what() const noexcept;
};