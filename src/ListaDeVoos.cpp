#include "../include/ListaDeVoos.h"

using namespace std;

ListaDeVoos::ListaDeVoos()
{
}

void ListaDeVoos::Inicializar(FILE *arq)
{
}

list<Voo>::iterator ListaDeVoos::Buscar(string origem, string destino, FiltrosVoo filtros)
{
    list<Voo>::iterator it;
    return it;
}

void ListaDeVoos::Comprar(list<Voo>::iterator it, Usuario user)
{
}

void ListaDeVoos::CancelarCompra(list<Voo>::iterator it, Usuario user)
{
}

void ListaDeVoos::Avaliar(list<Voo>::iterator it, Usuario user, float avaliacao)
{
}

void ListaDeVoos::Fechar(FILE *arq)
{
}
