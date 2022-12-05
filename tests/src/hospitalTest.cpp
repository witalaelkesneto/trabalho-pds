#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "hospital.hpp"

TEST_CASE("Testando a classe Hospital"){
    Hospital hospital("teste", 1000);
    CHECK_EQ("teste", hospital.getNome());
    CHECK_EQ(1000, hospital.getValorDisponivel());
}

