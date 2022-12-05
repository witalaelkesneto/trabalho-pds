#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "cidadao.hpp"

TEST_CASE("Testando a classe Cidadao")
{
    Cidadao user("nomeDeUsuario", "senha", "nomeCompleto", "Cidadão");
    std::vector<Usuario *> usuarios;
    std::vector<Hospital *> hospitais;
    usuarios.push_back(new Cidadao("carlos", "teste", "Carlos Silva", "Cidadão"));
    hospitais.push_back(new Hospital("teste1", 1000));
    hospitais.push_back(new Hospital("teste2", 1000));

    SUBCASE("Teste Positivo")
    {
        CHECK_EQ("nomeDeUsuario", user.getNomeDeUsuario());
        CHECK_EQ("nomeCompleto", user.getNomeCompleto());
        CHECK_EQ("senha", user.getSenha());
        CHECK_EQ("Cidadão", user.getTipo());
        CHECK_EQ(2000, user.valorTotalOrcado(hospitais));
        CHECK_EQ(true, user.naoExisteUsuario(usuarios, "teste"));
        CHECK_EQ(true, user.existeHospital(hospitais, "teste1"));
    }

    SUBCASE("Teste Negativo")
    {
        CHECK_THROWS(user.naoExisteUsuario(usuarios, "carlos"));
        CHECK_THROWS(user.existeHospital(hospitais, "teste"));
    }
}
