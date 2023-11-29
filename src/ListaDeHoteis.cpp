#include "../include/ListaDeHoteis.h"
#include <ostream>
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
        getline(arquivo_, buffer); // para tirar a linha em branco

        lista_.push_back(aux_leitura);
    }
    arquivo_.close();
}

list<Hotel>::iterator ListaDeHoteis::Buscar(FiltrosHotel filtros)
{
    list<Hotel>::iterator it;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if ((it->local == filtros.local) && (it->estrelas == filtros.estrelas) &&
            (it->cafe == filtros.cafe)) // talvez pensar melhor nos filtros kkkkkkj
            return it;
    }
    if (it == lista_.end())
    {
        // TODO: throw excessão
    }
}

// Estou mudando a interfaçe dos métodos ConsultarCalendario e Reservar para que eles
// recebam a data no formato de inteiro. A conersão de string para inteiro será feita
// na função main no momento que o usuario digita a data.

bool ListaDeHoteis::ConsultarCalendario(int dia, int mes, list<Hotel>::iterator it, int pessoas)
{
    if ((pessoas == 2) && (it->quartos2[mes - 1][dia - 1] != 0))
        return true;
    if ((pessoas == 3) && (it->quartos3[mes - 1][dia - 1] != 0))
        return true;
    if ((pessoas == 4) && (it->quartos4[mes - 1][dia - 1] != 0))
        return true;
    return false;
}

void ListaDeHoteis::Reservar(string data_inicio, string data_fim, list<Hotel>::iterator it, Usuario user, int pessoas)
{
    int dia_i = stoi(data_inicio.substr(0, 2));
    int mes_i = stoi(data_inicio.substr(2, 2));
    int dia_f = stoi(data_fim.substr(0, 2));
    int mes_f = stoi(data_fim.substr(2, 2));

    if (mes_i == mes_f)
    {
        for (int i = dia_i; i < dia_f + 1; i++)
        {
            ConsultarCalendario(string data, list<Hotel>::iterator it, int pessoas)
        }
    }
}

void ListaDeHoteis::CancelarReserva(list<Hotel>::iterator it, Usuario user)
{
}

void ListaDeHoteis::Avaliar(list<Hotel>::iterator it, Usuario user, float avaliacao)
{
    float media = ((it->avaliacoes + avaliacao) / 2.0);
    it->avaliacoes = media;
}

void ListaDeHoteis::Fechar()
{
    arquivo_.open("data/Hoteis.txt", ios::out);
    if (!arquivo_.is_open())
    {
        // TODO: throw excessão
    }

    for (Hotel x : lista_)
    {
        arquivo_ << x.nome << endl;
        arquivo_ << x.local << endl;
        arquivo_ << x.estrelas << endl;
        arquivo_ << x.avaliacoes << endl;
        arquivo_ << x.cafe << endl;
        arquivo_ << x.almoco << endl;
        arquivo_ << x.jantar << endl;
        arquivo_ << x.piscina << endl;

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < x.quartos2[i].size(); i++)
            {
                arquivo_ << x.quartos2[i][j] << " ";
            }
            arquivo_ << endl;
        }
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < x.quartos3[i].size(); i++)
            {
                arquivo_ << x.quartos3[i][j] << " ";
            }
            arquivo_ << endl;
        }
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < x.quartos4[i].size(); i++)
            {
                arquivo_ << x.quartos4[i][j] << " ";
            }
            arquivo_ << endl;
        }
        arquivo_ << x.preco2 << endl;
        arquivo_ << x.preco3 << endl;
        arquivo_ << x.preco4 << endl;
    }
    arquivo_.close();
}
