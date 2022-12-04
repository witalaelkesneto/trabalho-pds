#pragma once

#include <iostream>

class MenuException : public std::exception
{
public:
    const char *what() const noexcept;
};