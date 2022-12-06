#include "sistema.hpp"

Sistema::Sistema()
{
    _valorTeto = new double(10000);
    _usuarios.push_back(new Cidadao("carlos", "teste", "Carlos Silva", "Cidadão"));
    _usuarios.push_back(new Secretario("bruno", "teste", "Bruno Andrade", "Secretário"));
    _usuarios.push_back(new Prefeito("anna", "teste", "Anna Luiza", "Prefeito"));
    _hospitais.push_back(new Hospital("Hospital São Camilo", 1000));
    _hospitais.push_back(new Hospital("Hospital Belo Horizonte", 1000));
    _hospitais.push_back(new Hospital("eu", 1000));
    _hospitais.push_back(new Hospital("ele", 1000));
}

void Sistema::menu()
{
    try
    {
        int menuInicial;
        do
        {
            _quantidadeUsuarios = _usuarios.size();
            printMenuInicial();
            std::cin >> menuInicial;
            switch (menuInicial)
            {
            case 1:
                try
                {
                    Usuario *user = login();
                    user->menu(_usuarios, _hospitais, _valorTeto);
                }
                catch (UsuarioNaoExisteException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                catch (SenhaErradaException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                std::cout << "Aperte enter para prosseguir" << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 2:
                try
                {
                    cadastro();
                }
                catch (UsuarioExisteException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
                catch (TipoInvalidoException &e)
                {
                    std::cout << std::endl;
                    std::cout << e.what() << std::endl;
                }
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
        } while (menuInicial != 3);
    }
    catch (MenuException &e)
    {
        std::cout << std::endl;
        std::cout << e.what() << std::endl;
    }
}

void Sistema::printMenuInicial()
{
    int systemClear = system("clear");
    if (systemClear == -1)
    {
        throw MenuException();
    }
    std::cout << "-------------------BEM VINDO-------------------" << std::endl;
    std::cout << "Escolha uma opção, selecionando seu número:" << std::endl;
    std::cout << "1. Realizar Login" << std::endl;
    std::cout << "2. Cadastrar Novo Usuário" << std::endl;
    std::cout << "3. Sair" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

Usuario *Sistema::getUsuario(std::string nomeDeUsuario)
{
    for (int i = 0; i < _quantidadeUsuarios; i++)
    {
        if (_usuarios[i]->getNomeDeUsuario() == nomeDeUsuario)
        {
            return _usuarios[i];
        }
    }
    return nullptr;
}

Usuario *Sistema::login()
{
    std::cout << "Digite o usuário: ";
    std::cin >> _nomeDeUsuario;
    if (existeUsuario(_nomeDeUsuario))
    {
        std::cout << "Digite a senha: ";
        std::cin >> _senha;
        if (verificaSenha(_nomeDeUsuario, _senha))
        {
            Usuario *user = getUsuario(_nomeDeUsuario);
            return user;
        }
    }
    return nullptr;
}

void Sistema::cadastro()
{
    std::string nome;
    std::string tipo;
    std::cout << "Digite o nome de usuário: ";
    std::cin >> _nomeDeUsuario;
    if (naoExisteUsuario(_nomeDeUsuario))
    {
        std::cout << "Digite a senha: ";
        std::cin >> _senha;
        std::cout << "Digite o nome completo: ";
        std::cin.ignore();
        std::getline(std::cin, nome);
        std::cout << "Digite o tipo de usuário (Cidadão/Secretário/Prefeito): ";
        std::cin >> tipo;
        if (tipo != "Cidadão" && tipo != "Secretário" && tipo != "Prefeito")
        {
            throw TipoInvalidoException(tipo);
        }
        else if (tipo == "Cidadão")
        {
            _usuarios.push_back(new Cidadao(_nomeDeUsuario, _senha, nome, tipo));
        }
        else if (tipo == "Secretário")
        {
            _usuarios.push_back(new Secretario(_nomeDeUsuario, _senha, nome, tipo));
        }
        else if (tipo == "Prefeito")
        {
            _usuarios.push_back(new Prefeito(_nomeDeUsuario, _senha, nome, tipo));
        }
    }
}

bool Sistema::existeUsuario(std::string nomeDeUsuario)
{
    for (int i = 0; i < _quantidadeUsuarios; i++)
    {
        if (_usuarios[i]->getNomeDeUsuario() == nomeDeUsuario)
        {
            return true;
        }
    }
    throw UsuarioNaoExisteException(nomeDeUsuario);
}

bool Sistema::verificaSenha(std::string nomeDeUsuario, std::string senha)
{
    if (existeUsuario(nomeDeUsuario))
    {
        for (int i = 0; i < _quantidadeUsuarios; i++)
        {
            if (_usuarios[i]->getSenha() == senha)
            {
                return true;
            }
        }
    }
    throw SenhaErradaException(nomeDeUsuario);
}

bool Sistema::naoExisteUsuario(std::string nomeDeUsuario)
{
    for (int i = 0; i < _quantidadeUsuarios; i++)
    {
        if (_usuarios[i]->getNomeDeUsuario() == nomeDeUsuario)
        {
            throw UsuarioExisteException(nomeDeUsuario);
        }
    }
    return true;
}