#include "secretario.hpp"

Secretario::Secretario(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo)
    : Usuario(nomeDeUsuario, senha, nomeCompleto, tipo) {}

void Secretario::printMenu()
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
    std::cout << "3. Registrar Gasto" << std::endl;
    std::cout << "4. Sair" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

void Secretario::menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto)
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
                try
                {
                    registrarGasto(hospitais);
                }
                catch (HospitalNaoExisteException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                catch (GastoException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 4:
                break;
            default:
                std::cout << "Insira uma opção válida" << std::endl;
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }
        } while (menu != 4);
    }
    catch (MenuException &e)
    {
        std::cout << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void Secretario::registrarGasto(std::vector<Hospital *> hospitais)
{
    std::string nome;
    double valor;
    std::cout << "Digite o nome do hospital que receberá o gasto: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    if (existeHospital(hospitais, nome))
    {
        std::cout << "Digite o valor que será gasto: ";
        std::cin >> valor;
        Hospital *hospital = getHospital(hospitais, nome);
        if (hospital->getValorDisponivel() < valor)
        {
            throw GastoException(valor, hospital->getValorDisponivel());
        }
        hospital->reduzirOrcamento(valor);
        std::cout << "Gasto registrado com sucesso" << std::endl;
    }
}
