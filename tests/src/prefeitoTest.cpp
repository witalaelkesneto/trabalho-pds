#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "prefeito.hpp"

TEST_CASE("Testando a classe Prefeito")
{
    Prefeito user("nomeDeUsuario", "senha", "nomeCompleto", "Prefeito");
    std::vector<Usuario *> usuarios;
    std::vector<Hospital *> hospitais;
    usuarios.push_back(new Prefeito("carlos", "teste", "Carlos Silva", "Cidadão"));
    hospitais.push_back(new Hospital("teste1", 1000));
    hospitais.push_back(new Hospital("teste2", 1000));

    SUBCASE("Teste Positivo")
    {
        CHECK_EQ("nomeDeUsuario", user.getNomeDeUsuario());
        CHECK_EQ("nomeCompleto", user.getNomeCompleto());
        CHECK_EQ("senha", user.getSenha());
        CHECK_EQ("Prefeito", user.getTipo());
        CHECK_EQ(2000, user.valorTotalOrcado(hospitais));
        CHECK_EQ(true, user.naoExisteUsuario(usuarios, "teste"));
        CHECK_EQ(true, user.existeHospital(hospitais, "teste1"));
        CHECK_EQ(true, user.naoExisteHospital(hospitais, "teste"));
    }

    SUBCASE("Teste negativo")
    {
        CHECK_THROWS(user.naoExisteUsuario(usuarios, "carlos"));
        CHECK_THROWS(user.existeHospital(hospitais, "teste"));
        CHECK_THROWS(user.naoExisteHospital(hospitais, "teste1"));
    }
}
