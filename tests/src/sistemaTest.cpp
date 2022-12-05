#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "sistema.hpp"

TEST_CASE("Testando a classe Sistema")
{
    Sistema sistema = Sistema();
    SUBCASE("Teste Positivo")
    {
        CHECK_EQ(true, sistema.existeUsuario("anna"));
        CHECK_EQ(true, sistema.verificaSenha("anna", "teste"));
        CHECK_EQ(true, sistema.naoExisteUsuario("teste"));
    }

    SUBCASE("Teste Negativo")
    {
        CHECK_THROWS(sistema.existeUsuario("teste"));
        CHECK_THROWS(sistema.verificaSenha("anna", "anna"));
        CHECK_THROWS(sistema.naoExisteUsuario("anna"));
    }
}
