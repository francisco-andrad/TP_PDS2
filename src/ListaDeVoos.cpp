
#include "../include/ListaDeVoos.h"
#include <iostream>
#include <string>

using namespace std;

ListaDeVoos::ListaDeVoos()
{
}

void ListaDeVoos::Inicializar()
{
    arquivo_.open("data/Voos.txt", ios::in);
    if (!arquivo_.is_open())
    {
        ExcecaoErroArquivoVoos f;
        throw f;
    }
    string buffer;
    Voo aux_leitura;
    while (getline(arquivo_, buffer))
    {
        aux_leitura.numero = buffer;
        getline(arquivo_, buffer);
        aux_leitura.origem = buffer;
        getline(arquivo_, buffer);
        aux_leitura.destino = buffer;
        getline(arquivo_, buffer);
        aux_leitura.data_partida = buffer;
        getline(arquivo_, buffer);
        aux_leitura.hora_partida = buffer;
        getline(arquivo_, buffer);
        aux_leitura.data_chegada = buffer;
        getline(arquivo_, buffer);
        aux_leitura.hora_chegada = buffer;
        getline(arquivo_, buffer);
        aux_leitura.companhia = buffer;
        getline(arquivo_, buffer);
        aux_leitura.preco_economica = stof(buffer);
        getline(arquivo_, buffer);
        aux_leitura.preco_executiva = stof(buffer);
        getline(arquivo_, buffer);
        aux_leitura.assentos_economica = stoi(buffer);
        getline(arquivo_, buffer);
        aux_leitura.assentos_executiva = stoi(buffer);
        lista_.push_back(aux_leitura);
        getline(arquivo_, buffer); // linha em branco que separa os voos
    }
    arquivo_.close();
}

list<Voo>::iterator ListaDeVoos::Buscar(string codigo)
{
    list<Voo>::iterator it;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if (it->numero == codigo)
            return it;
    }
    if (it == lista_.end())
    {
        // TODO: throw exceção
    }
}

void ListaDeVoos::ExibirVoos(string origem, string destino, Data data)
{
    list<Voo>::iterator it;
    int contador = 0;
    string aux_data = to_string(data.dia) + "/" + to_string(data.mes) + "/2024";
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if ((it->origem == origem) && (it->destino == destino) && (it->data_partida == aux_data))
        {
            cout << "número do voo: " << it->numero << endl;
            cout << "origem: " << it->origem << endl;
            cout << "destino: " << it->destino << endl;
            cout << "data de partida: " << it->data_partida << endl;
            cout << "hora de partida: " << it->hora_partida << endl;
            cout << "data de chegada: " << it->data_chegada << endl;
            cout << "hora de chegada: " << it->hora_chegada << endl;
            cout << "companhia: " << it->companhia << endl;
            cout << "preço da classe econômica: " << it->preco_economica << endl;
            cout << "preço da classe executiva: " << it->preco_executiva << endl;
            cout << "assentos disponíveis na classe econômica: " << it->assentos_economica << endl;
            cout << "assentos disponíveis na classe executiva: " << it->assentos_executiva << endl;
            cout << endl;
            contador++;
        }
    }
    if (contador == 0)
    {
        // TODO: throw exceção
        // nenhum voo encontrado
    }
}

void ListaDeVoos::Confirmar(string codigo)
{
    list<Voo>::iterator it;
    int contador = 0;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if (it->numero == codigo)
        {
            cout << "número do voo: " << it->numero << endl;
            cout << "origem: " << it->origem << endl;
            cout << "destino: " << it->destino << endl;
            cout << "data de partida: " << it->data_partida << endl;
            cout << "hora de partida: " << it->hora_partida << endl;
            cout << "data de chegada: " << it->data_chegada << endl;
            cout << "hora de chegada: " << it->hora_chegada << endl;
            cout << "companhia: " << it->companhia << endl;
            cout << "preço da classe econômica: " << it->preco_economica << endl;
            cout << "preço da classe executiva: " << it->preco_executiva << endl;
            cout << "assentos disponíveis na classe econômica: " << it->assentos_economica << endl;
            cout << "assentos disponíveis na classe executiva: " << it->assentos_executiva << endl;
            cout << endl;
            contador = 1;
        }
    }
    if (contador == 0)
    {
        // TODO: throw exceção
        // nenhum voo encontrado
    }
}

void ListaDeVoos::Comprar(list<Voo>::iterator it, Usuario &user, bool economica)
{
    if (((user.creditos() < it->preco_executiva) && (!economica)) ||
        ((user.creditos() < it->preco_economica) && economica))
    {
        // TODO: throw exccessão
    }
    if (!economica)
    {
        user.RegistrarCompraPassagem(*(it), it->preco_executiva, false);
        it->assentos_executiva--;
    }
    else
    {
        user.RegistrarCompraPassagem(*(it), it->preco_economica, true);
        it->assentos_economica--;
    }
}

void ListaDeVoos::CancelarCompra(list<Voo>::iterator it, Usuario &user, bool economica)
{
    if (!economica)
    {
        user.ReembolsarCompraPassagem(*(it), it->preco_executiva, false);
        it->assentos_executiva++;
    }
    else
    {
        user.ReembolsarCompraPassagem(*(it), it->preco_economica, true);
        it->assentos_economica++;
    }
}

void ListaDeVoos::Avaliar(list<Voo>::iterator it, Usuario &user, float avaliacao)
{
    // essa função é completamente inútil kkkkk vo tentar improvisar aqui
    // float media = ((avaliacao + it->avaliacao)/2.0);
    // it->avaliacao = media;
}

void ListaDeVoos::Fechar()
{
    arquivo_.open("data/Voos.txt", ios::out);
    if (!arquivo_.is_open())
    {
        ExcecaoErroArquivoVoos f;
        throw f;
    }
    for (Voo x : lista_)
    {
        arquivo_ << x.numero << endl;
        arquivo_ << x.origem << endl;
        arquivo_ << x.destino << endl;
        arquivo_ << x.data_partida << endl;
        arquivo_ << x.hora_partida << endl;
        arquivo_ << x.data_chegada << endl;
        arquivo_ << x.hora_chegada << endl;
        arquivo_ << x.companhia << endl;
        arquivo_ << x.preco_economica << endl;
        arquivo_ << x.preco_executiva << endl;
        arquivo_ << x.assentos_economica << endl;
        arquivo_ << x.assentos_executiva << endl;
        arquivo_ << endl; // linha em branco separando
    }
    arquivo_.close();
}
