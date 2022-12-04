#include "cidadao.hpp"

Cidadao::Cidadao(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo)
    : Usuario(nomeDeUsuario, senha, nomeCompleto, tipo) {}

void Cidadao::printMenu()
{
    int systemClear = system("clear");
    if (systemClear == -1)
    {
        throw MenuException();
    }
    std::cout << "Olá, " << getNomeCompleto() << std::endl;
    std::cout << "Meu tipo de usuário é: " << getTipo() << std::endl;
    std::cout << "Escolha uma opção, selecionando seu número:" << std::endl;
    std::cout << "1. Verificar Orçamento" << std::endl;
    std::cout << "2. Alterar Dados Cadastrais" << std::endl;
    std::cout << "3. Sair" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

void Cidadao::menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto)
{
    try
    {
        int menu;
        do
        {
            printMenu();
            std::cin >> menu;
            switch (menu)
            {
            case 1:
                printHospitais(hospitais, valorTeto);
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 2:
                try
                {
                    alterarDados(usuarios);
                }
                catch (UsuarioExisteException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 3:
                break;
            default:
                std::cout << "Insira uma opção válida" << std::endl;
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }
        } while (menu != 3);
    }
    catch (MenuException &e)
    {
        std::cout << std::endl;
        std::cout << e.what() << std::endl;
    }
}
