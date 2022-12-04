#pragma once

#include <iostream>
#include <string>

class GastoException : public std::exception
{
private:
    std::string _msg;

public:
    GastoException(double valorGasto, double valorDisponivel);
    const char *what() const noexcept;
};