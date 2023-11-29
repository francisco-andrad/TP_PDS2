
#include "../include/ListaDeVoos.h"
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
        ExcecaoErroArquivoVoos e;
        throw e;
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
        getline(arquivo_, buffer);
    }
    arquivo_.close();
}

list<Voo>::iterator ListaDeVoos::Buscar(string origem, string destino, FiltrosVoo filtros)
{
    list<Voo>::iterator it;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if ((it->origem == origem) && (it->destino == destino) && (it->data_partida == filtros.data_partida) &&
            (it->data_chegada == filtros.data_chegada) && (it->companhia == filtros.companhia))
            return it;
    }
    if (it == lista_.end())
    {
        // TODO: throw excessão
    }
}

void ListaDeVoos::Comprar(list<Voo>::iterator it, Usuario user, bool economica)
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

void ListaDeVoos::CancelarCompra(list<Voo>::iterator it, Usuario user, bool economica)
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

void ListaDeVoos::Avaliar(list<Voo>::iterator it, Usuario user, float avaliacao)
{
    // essa função é completamente inútil kkkkk vo tentar improvisar aqui
    // float media = ((avaliacao + it->avaliacao)/2.0);
    // it->avaliacao = media;
}

void ListaDeVoos::Fechar(FILE *arq)
{
    arquivo_.open("data/Voos.txt", ios::out);
    if (!arquivo_.is_open())
    {
        ExcecaoErroArquivoVoos e;
        throw e;
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
    }
    arquivo_.close();
}
