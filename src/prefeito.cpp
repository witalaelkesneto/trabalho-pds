#include "prefeito.hpp"

Prefeito::Prefeito(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo)
    : Usuario(nomeDeUsuario, senha, nomeCompleto, tipo) {}

void Prefeito::printMenu()
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
    std::cout << "4. Movimentar Orcamento" << std::endl;
    std::cout << "5. Definir Teto de Gastos" << std::endl;
    std::cout << "6. Cadastrar Novo Hospital" << std::endl;
    std::cout << "7. Sair" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

void Prefeito::menu(std::vector<Usuario *> usuarios, std::vector<Hospital *> hospitais, double *valorTeto)
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
                try
                {
                    movimentarOrcamento(hospitais);
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
                break;
            case 5:
                try
                {
                    definirTeto(hospitais, valorTeto);
                }
                catch (TetoException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 6:
                try
                {
                    cadastrarHospital(hospitais, valorTeto);
                }
                catch (HospitalExisteException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                catch (TetoException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 7:
                break;
            default:
                std::cout << "Insira uma opção válida" << std::endl;
                std::cout << std::endl;
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }
        } while (menu != 7);
    }
    catch (MenuException &e)
    {
        std::cout << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void Prefeito::registrarGasto(std::vector<Hospital *> hospitais)
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

void Prefeito::definirTeto(std::vector<Hospital *> hospitais, double *valorTeto)
{
    double valor;
    std::cout << "Digite o novo valor do teto de gastos: ";
    std::cin >> valor;
    double valorOrcado = valorTotalOrcado(hospitais);
    if (valorOrcado > valor)
    {
        throw TetoException(valorOrcado, valor);
    }
    else
    {
        *valorTeto = valor;
    }
}

void Prefeito::cadastrarHospital(std::vector<Hospital *> &hospitais, double *valorTeto)
{
    std::string nome;
    double valor;
    std::cout << "Digite o nome do hospital: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    if (naoExisteHospital(hospitais, nome))
    {
        std::cout << "Digite o valor disponível para o orçamento:";
        std::cin >> valor;
        double valorOrcado = valorTotalOrcado(hospitais) + valor;
        if (valorOrcado > *valorTeto)
        {
            throw TetoException(valorOrcado, *valorTeto);
        }
        else
        {
            hospitais.push_back(new Hospital(nome, valor));
            std::cout << "Hospital cadastrado com sucesso" << std::endl;
        }
    }
}

bool Prefeito::naoExisteHospital(std::vector<Hospital *> hospitais, std::string nome)
{
    int quantidadeHospitais = hospitais.size();
    for (int i = 0; i < quantidadeHospitais; i++)
    {
        if (hospitais[i]->getNome() == nome)
        {
            throw HospitalExisteException(nome);
        }
    }
    return true;
}

void Prefeito::movimentarOrcamento(std::vector<Hospital *> hospitais)
{
    std::string nome;
    std::string nomeDestino;
    double valor;
    std::cout << "Digite o nome do hospital que terá a verba reduzida: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    if (existeHospital(hospitais, nome))
    {
        std::cout << "Digite o valor que será movimentado: ";
        std::cin >> valor;
        Hospital *hospital = getHospital(hospitais, nome);
        if (hospital->getValorDisponivel() < valor)
        {
            throw GastoException(valor, hospital->getValorDisponivel());
        }
        else
        {
            std::cout << "Digite o nome do hospital que receberá a verba: ";
            std::cin.ignore();
            std::getline(std::cin, nomeDestino);
            if (existeHospital(hospitais, nomeDestino))
            {
                Hospital *hospitalDestino = getHospital(hospitais, nomeDestino);
                hospital->reduzirOrcamento(valor);
                hospitalDestino->aumentarOrcamento(valor);
                std::cout << "Orçcamento transferido com sucesso" << std::endl;
            }
        }
    }
}