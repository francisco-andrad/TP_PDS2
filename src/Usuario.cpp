#include "../include/Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario()
{
}

void Usuario::login(string nome, string senha)
{
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
        getline(arquivo_, aux_creitos);
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
    if (creditos < 0.0)
    {
        // TODO: throw excessão
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

void Usuario::RegistrarReservaHotel(Hotel hotel, string data_chegada, string data_partida, float preco)
{
    // o código que testa se o usuario tem creditos o suficiente
    // para realizar a transação vai ficar na classe ListaDeHoteis
    string aux_dados = "H" + hotel.nome + data_chegada + data_partida;
    hoteis_.push_back(aux_dados);
    creditos_ -= preco;
}

void Usuario::ReembolsarCompraPassagem(Voo voo, float preco, bool economica)
{
    // TODO: talvez colocar "x" ou "c" para diferenciar economica e executiva
    string aux_dados;
    if (!economica)
        aux_dados = "P" + voo.numero + "X";
    else
        aux_dados = "P" + voo.numero + "E";
    passagens_.remove(aux_dados);
    creditos_ += preco;
}

void Usuario::ReembolsarReservaHotel(Hotel hotel, string data_chegada, string data_partida, float preco)
{
    string aux_dados = "H" + hotel.nome + data_chegada + data_partida;
    hoteis_.remove(aux_dados);
    creditos_ += preco;
}

float Usuario::creditos()
{
    return creditos_;
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
