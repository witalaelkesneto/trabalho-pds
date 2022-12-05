/**
 * @file hospitalExisteException.hpp
 * @author Witalaelkes Neto (witalaelkesneto@icloud.com)
 * @brief Arqivo da classe HospitalExisteException
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
 * @brief Classe HospitalExisteException que é lançada quando um hospital já existe no sistema
 *
 */
class HospitalExisteException : public std::exception
{
private:
    std::string _msg;

public:
    /**
     * @brief Construct a new Hospital Existe Exception object
     *
     * @param nome
     */
    HospitalExisteException(std::string nome);

    /**
     * @brief Retorna a mensagem da exceção
     *
     * @return const char* _msg
     */
    const char *what() const noexcept;
};