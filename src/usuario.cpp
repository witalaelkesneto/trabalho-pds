#include "usuario.hpp"

Usuario::Usuario(std::string nomeDeUsuario, std::string senha, std::string nomeCompleto, std::string tipo)
{
    _nomeDeUsuario = nomeDeUsuario;
    _senha = senha;
    _nomeCompleto = nomeCompleto;
    _tipo = tipo;
}

void Usuario::setNomeDeUsuario(std::string nomeDeUsuario)
{
    _nomeDeUsuario = nomeDeUsuario;
}

std::string Usuario::getNomeDeUsuario()
{
    return _nomeDeUsuario;
}

void Usuario::setNomeCompleto(std::string nomeCompleto)
{
    _nomeCompleto = nomeCompleto;
}

std::string Usuario::getNomeCompleto()
{
    return _nomeCompleto;
}

void Usuario::setSenha(std::string senha)
{
    _senha = senha;
}

std::string Usuario::getSenha()
{
    return _senha;
}

void Usuario::setTipo(std::string tipo)
{
    _tipo = tipo;
}

std::string Usuario::getTipo()
{
    return _tipo;
}

void Usuario::printHospitais(std::vector<Hospital *> hospitais, double *valorTeto)
{
    int quantidadeHospitais = hospitais.size();
    for (int i = 0; i < quantidadeHospitais; i++)
    {
        hospitais[i]->imprimir();
    }

    double valorOrcado = valorTotalOrcado(hospitais);

    std::cout << std::endl;
    std::cout << "Valor total orçado: R$" << valorOrcado << std::endl;
    std::cout << "Valor do teto de gastos: R$" << *valorTeto << std::endl;
    std::cout << "Valor disponível para gastos: R$" << (*valorTeto - valorOrcado) << std::endl;
}

double Usuario::valorTotalOrcado(std::vector<Hospital *> hospitais)
{
    double valor = 0;
    int quantidadeHospitais = hospitais.size();
    for (int i = 0; i < quantidadeHospitais; i++)
    {
        valor += hospitais[i]->getValorDisponivel();
    }
    return valor;
}

void Usuario::alterarDados(std::vector<Usuario *> usuarios)
{
    std::string nomeDeUsuario;
    std::string senha;
    std::string nome;
    std::cout << "Digite o nome de usuário: ";
    std::cin >> nomeDeUsuario;
    if (naoExisteUsuario(usuarios, nomeDeUsuario))
    {
        setNomeDeUsuario(nomeDeUsuario);
        std::cout << "Digite a senha: ";
        std::cin >> senha;
        setSenha(senha);
        std::cout << "Digite o nome completo: ";
        std::cin.ignore();
        std::getline(std::cin, nome);
        setNomeCompleto(nome);
        std::cout << "Usuário cadastrado com sucesso";
    }
}

bool Usuario::naoExisteUsuario(std::vector<Usuario *> usuarios, std::string nomeDeUsuario)
{
    int quantidadeUsuarios = usuarios.size();
    for (int i = 0; i < quantidadeUsuarios; i++)
    {
        if (usuarios[i]->getNomeDeUsuario() == nomeDeUsuario)
        {
            throw UsuarioExisteException(nomeDeUsuario);
        }
    }
    return true;
}

bool Usuario::existeHospital(std::vector<Hospital *> hospitais, std::string nome)
{
    int quantidadeHospitais = hospitais.size();
    for (int i = 0; i < quantidadeHospitais; i++)
    {
        if (hospitais[i]->getNome() == nome)
        {
            return true;
        }
    }
    throw HospitalNaoExisteException(nome);
}

Hospital *Usuario::getHospital(std::vector<Hospital *> hospitais, std::string nome)
{
    int quantidadeHospitais = hospitais.size();
    for (int i = 0; i < quantidadeHospitais; i++)
    {
        if (hospitais[i]->getNome() == nome)
        {
            return hospitais[i];
        }
    }
    return nullptr;
}