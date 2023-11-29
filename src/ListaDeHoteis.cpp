#include "../include/ListaDeHoteis.h"
#include <string>

using namespace std;

ListaDeHoteis::ListaDeHoteis()
{
}

void ListaDeHoteis::Inicializar()
{
    arquivo_.open("data/Hoteis.txt", ios::in);
    if (!arquivo_.is_open())
    {
        // TODO: throw excessão
    }
    string buffer;
    Hotel aux_leitura;
    string aux_data = "";
    while (getline(arquivo_, buffer))
    {
        aux_leitura.nome = buffer;
        getline(arquivo_, buffer);
        aux_leitura.local = buffer;
        getline(arquivo_, buffer);
        aux_leitura.estrelas = stoi(buffer);
        getline(arquivo_, buffer);
        aux_leitura.avaliacoes = stof(buffer);
        getline(arquivo_, buffer);
        aux_leitura.cafe = stoi(buffer);
        getline(arquivo_, buffer);
        aux_leitura.almoco = stoi(buffer);
        getline(arquivo_, buffer);
        aux_leitura.jantar = stoi(buffer);
        getline(arquivo_, buffer);
        aux_leitura.piscina = stoi(buffer);
        for (int i = 0; i < 12; i++)
        {
            getline(arquivo_, buffer);
            for (int j = 0; j < buffer.size(); j++)
            {
                if (buffer[j] == ' ')
                {
                    aux_leitura.quartos2[i].push_back(stoi(aux_data));
                    aux_data = "";
                }
                else
                {
                    aux_data.append(1, buffer[j]);
                }
            }
        }
        for (int i = 0; i < 12; i++)
        {
            getline(arquivo_, buffer);
            for (int j = 0; j < buffer.size(); j++)
            {
                if (buffer[j] == ' ')
                {
                    aux_leitura.quartos3[i].push_back(stoi(aux_data));
                    aux_data = "";
                }
                else
                {
                    aux_data.append(1, buffer[j]);
                }
            }
        }

        for (int i = 0; i < 12; i++)
        {
            getline(arquivo_, buffer);
            for (int j = 0; j < buffer.size(); j++)
            {
                if (buffer[j] == ' ')
                {
                    aux_leitura.quartos4[i].push_back(stoi(aux_data));
                    aux_data = "";
                }
                else
                {
                    aux_data.append(1, buffer[j]);
                }
            }
        }
        getline(arquivo_, buffer);
        aux_leitura.preco2 = stof(buffer);
        getline(arquivo_, buffer);
        aux_leitura.preco3 = stof(buffer);
        getline(arquivo_, buffer);
        aux_leitura.preco4 = stof(buffer);

        lista_.push_back(aux_leitura);
    }
    arquivo_.close();
}

list<Hotel>::iterator ListaDeHoteis::Buscar(string local, FiltrosHotel filtros)
{
    list<Hotel>::iterator it;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if ((it->local == local) && (it->estrelas == filtros.estrelas) &&
            (it->cafe == filtros.cafe)) // talvez pensar melhor nos filtros kkkkkkj
            return it;
    }
    if (it == lista_.end())
    {
        // TODO: throw excessão
    }
}

bool ListaDeHoteis::ConsultarCalendario(string data, list<Hotel>::iterator it, int pessoas)
{
    // ATENÇÃO: o método está errado, obviamente não são todos os meses que tem 30
    // dias, mas se não der tempo de arrumar vai assim mesmo kkkkkkj

    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(2, 2));
    int i = (30 * (mes - 1)) + dia;
    if ((pessoas == 2) && (it->quartos2[i] != 0))
        return true;
    if ((pessoas == 3) && (it->quartos3[i] != 0))
        return true;
    if ((pessoas == 4) && (it->quartos4[i] != 0))
        return true;
    return false;
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
