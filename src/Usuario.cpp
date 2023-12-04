#include "../include/Usuario.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;

Usuario::Usuario()
{
}

void Usuario::login(string nome, string senha)
{
    nome_ = nome;
    senha_ = senha;
    string aux_abrir = "data/" + nome + ".txt";
    arquivo_.open(aux_abrir, ios::in);
    if (arquivo_.is_open())
    {
        string teste_senha;
        getline(arquivo_, teste_senha);
        if (teste_senha != senha)
        {
            // TODO: throw excessão
        }
        senha_ = senha;
        nome_ = nome;
        string aux_creitos;
        if (getline(arquivo_, aux_creitos))
            creditos_ = stof(aux_creitos);
        // cout << creditos_ << endl << senha_ << endl; DEBUG
        string aux_passagens;
        while (getline(arquivo_, aux_passagens))
        {
            if (aux_passagens[0] == 'P')
            {
                passagens_.push_back(aux_passagens);
                // cout << aux_passagens << endl; DEBUG
            }
        }
        arquivo_.clear();
        arquivo_.seekg(0); // se a senha do usuario comecar com H quebra tudo kkkkkj
        string aux_hoteis;
        while (getline(arquivo_, aux_hoteis))
        {
            if (aux_hoteis[0] == 'H')
            {
                hoteis_.push_back(aux_hoteis);
                // cout << aux_hoteis << endl; DEBUG
            }
        }
        arquivo_.close();
    }
    else
    {
        aux_abrir = "data/" + nome + ".txt";
        arquivo_.open(aux_abrir, ios::out);
        arquivo_ << senha << endl;
        nome_ = nome;
        senha_ = senha;
        creditos_ = 0.0;

        arquivo_.close();
    }
}

void Usuario::AdicionarCreditos(float creditos)
{
    if ((creditos < 0.0) || (creditos > 100000.0))
    {
        ExcecaoValorInvalido h;
        throw h;
    }

    creditos_ += creditos;
}

void Usuario::RegistrarCompraPassagem(Voo voo, float preco, bool economica)
{
    // o código que testa se o usuario tem creditos o suficiente
    // para realizar a transação vai ficar na classe ListaDeVoos
    // TODO: talvez colocar "x" ou "c" para diferenciar economica e executiva
    string aux_dados;
    if (!economica)
        aux_dados = "P" + voo.numero + "X";
    else
        aux_dados = "P" + voo.numero + "C";

    passagens_.push_back(aux_dados);
    creditos_ -= preco;
}

void Usuario::RegistrarReservaHotel(Hotel hotel, Data chegada, Data partida, float preco, int pessoas)
{
    // o código que testa se o usuario tem creditos o suficiente
    // para realizar a transação vai ficar na classe ListaDeHoteis
    string aux_dados = "H" + hotel.nome + to_string(chegada.dia) + to_string(chegada.mes) + to_string(partida.dia) +
                       to_string(partida.mes) + to_string(pessoas);
    hoteis_.push_back(aux_dados);
    creditos_ -= preco;
}

void Usuario::ReembolsarCompraPassagem(string codigo, float preco, bool economica)
{
    // TODO: talvez colocar "x" ou "c" para diferenciar economica e executiva DONE
    string aux_dados;
    if (!economica)
        aux_dados = "P" + codigo + "X";
    else
        aux_dados = "P" + codigo + "C";
    passagens_.remove(aux_dados);
    creditos_ += preco;
}

void Usuario::ReembolsarReservaHotel(Hotel hotel, Data chegada, Data partida, float preco, int pessoas)
{
    string aux_dados = "H" + hotel.nome + to_string(chegada.dia) + to_string(chegada.mes) + to_string(partida.dia) +
                       to_string(partida.mes) + to_string(pessoas);
    hoteis_.remove(aux_dados);
    creditos_ += preco;
}

float Usuario::creditos()
{
    return creditos_;
}

void Usuario::ExibirDados()
{
    cout << "nome: " << nome_ << endl;
    cout << "senha: " << senha_ << endl;
    cout << "créditos: " << creditos_ << endl;
    cout << "passagens reservadas: formato  P<número do voo><C para econômica ou X para executiva" << endl;
    for (string x : passagens_)
    {
        cout << x << endl;
    }
    cout << "hotéis reservados: formato H<nome do hotel><data de chegada e saída><número de pessoas por quarto>"
         << endl;
    for (string x : hoteis_)
    {
        cout << x << endl;
    }
}

void Usuario::logoff()
{

    string aux_abrir = "data/" + nome_ + ".txt";
    arquivo_.open(aux_abrir, ios::out);
    if (!arquivo_.is_open())
    {
        // TODO: throw excessão
    }

    arquivo_ << senha_ << endl;
    arquivo_ << creditos_ << endl;
    for (string x : passagens_)
    {
        arquivo_ << x << endl;
    }
    for (string x : hoteis_)
    {
        arquivo_ << x << endl;
    }

    arquivo_.close();
}
