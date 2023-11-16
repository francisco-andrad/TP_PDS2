#include "../include/ListaDeHoteis.h"

using namespace std;

ListaDeHoteis::ListaDeHoteis()
{
}

void ListaDeHoteis::Inicializar(FILE *arq)
{
}

list<Hotel>::iterator ListaDeHoteis::Buscar(string local, FiltrosHotel filtros)
{
    list<Hotel>::iterator it;
    return it;
}

bool ListaDeHoteis::ConsultarCalendario(string data, list<Hotel>::iterator it)
{
}

void ListaDeHoteis::Reservar(string data_inicio, string data_fim, list<Hotel>::iterator it, Usuario user)
{
}

void ListaDeHoteis::CancelarReserva(list<Hotel>::iterator it, Usuario user)
{
}

void ListaDeHoteis::Avaliar(list<Hotel>::iterator it, Usuario user, float avaliacao)
{
}

void ListaDeHoteis::Fechar(FILE *arq)
{
}
