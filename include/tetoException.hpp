#pragma once

#include <iostream>
#include <string>

class TetoException : public std::exception
{
private:
    std::string _msg;

public:
    TetoException(double valorOrcado, double valorTeto);
    const char *what() const noexcept;
};