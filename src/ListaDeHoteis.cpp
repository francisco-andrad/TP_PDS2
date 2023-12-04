#include "../include/ListaDeHoteis.h"
#include <cstdio>
#include <iostream>
#include <sstream>
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
    while (getline(arquivo_, buffer))
    {
        Hotel aux_leitura;
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
        // cout << "cheguei até aqui\n";
        // novo

        stringstream ss;
        string aux_data;
        vector<string> tokens;
        int num_vagas;
        vector<int> v_mes;
        // cout << "cheguei até aqui\n"; DEBUG
        for (int i = 0; i < 12; i++)
        {
            getline(arquivo_, buffer);
            ss = stringstream(buffer);
            // cout << buffer << "2" << endl; DEBUG
            while (ss >> aux_data)
            {
                tokens.push_back(aux_data);
                // cout << aux_data << " "; DEBUG
            }
            ss.clear();
            for (int j = 0; j < tokens.size(); j++)
            {
                num_vagas = stoi(tokens[j]);
                v_mes.push_back(num_vagas);
            }
            tokens.clear();
            aux_leitura.quartos2.push_back(v_mes);
            v_mes.clear();
        }
        for (int i = 0; i < 12; i++)
        {
            getline(arquivo_, buffer);
            ss = stringstream(buffer);
            // cout << buffer << "3" << endl; DEBUG
            while (ss >> aux_data)
            {
                tokens.push_back(aux_data);
                // cout << aux_data << " "; DEBUG
            }
            ss.clear();
            for (int j = 0; j < tokens.size(); j++)
            {
                num_vagas = stoi(tokens[j]);
                v_mes.push_back(num_vagas);
            }
            tokens.clear();
            aux_leitura.quartos3.push_back(v_mes);
            v_mes.clear();
        }
        for (int i = 0; i < 12; i++)
        {
            getline(arquivo_, buffer);
            ss = stringstream(buffer);
            // cout << buffer << "4" << endl; DEBUG
            while (ss >> aux_data)
            {
                tokens.push_back(aux_data);
                // cout << aux_data << " "; DEBUG
            }
            ss.clear();
            for (int j = 0; j < tokens.size(); j++)
            {
                num_vagas = stoi(tokens[j]);
                v_mes.push_back(num_vagas);
            }
            tokens.clear();
            aux_leitura.quartos4.push_back(v_mes);
            v_mes.clear();
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
    // DONE: a leitura tá pronta
}

list<Hotel>::iterator ListaDeHoteis::Buscar(string nome)
{
    list<Hotel>::iterator it;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if (it->nome == nome)
            return it;
    }
    if (it == lista_.end())
    {
        // TODO: throw excessão
    }
}

void ListaDeHoteis::ExibirHoteis(string cidade)
{
    list<Hotel>::iterator it;
    int contador = 0;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if (it->local == cidade)
        {
            cout << "nome do hotel: " << it->nome << endl;
            cout << "localização: " << it->local << endl;
            cout << "estrelas: " << it->estrelas << endl;
            cout << "avaliações: " << it->avaliacoes << endl;
            cout << "possui café da manha: sim = 1, não = 0: " << it->cafe << endl;
            cout << "possui almoço: sim = 1, não = 0: " << it->almoco << endl;
            cout << "possui jantar: sim = 1, não = 0: " << it->jantar << endl;
            cout << "possui piscina: sim = 1, não = 0: " << it->piscina << endl;
            cout << "preço do quarto para 2 pessoas: " << it->preco2 << endl;
            cout << "preço do quarto para 3 pessoas: " << it->preco3 << endl;
            cout << "preço do quarto paraa 4 pessoas: " << it->preco4 << endl;
            cout << endl;
            contador++;
        }
    }
    if (contador == 0)
    {
        // TODO: throw excessão
        // nenhum hotel encontrado
    }
}

void ListaDeHoteis::Confirmar(string nome)
{
    list<Hotel>::iterator it;
    int contador = 0;
    for (it = lista_.begin(); it != lista_.end(); it++)
    {
        if (it->nome == nome)
        {
            cout << "nome do hotel: " << it->nome << endl;
            cout << "localização: " << it->local << endl;
            cout << "estrelas: " << it->estrelas << endl;
            cout << "avaliações: " << it->avaliacoes << endl;
            cout << "possui café da manha: sim = 1, não = 0: " << it->cafe << endl;
            cout << "possui almoço: sim = 1, não = 0: " << it->almoco << endl;
            cout << "possui jantar: sim = 1, não = 0: " << it->jantar << endl;
            cout << "possui piscina: sim = 1, não = 0: " << it->piscina << endl;
            cout << "preço do quarto para 2 pessoas: " << it->preco2 << endl;
            cout << "preço do quarto para 3 pessoas: " << it->preco3 << endl;
            cout << "preço do quarto paraa 4 pessoas: " << it->preco4 << endl;
            cout << endl;
            contador = 1;
        }
    }
    if (contador == 0)
    {
        // TODO: throw excessão
        // nenhum hotel encontrado
    }
}

// Estou mudando a interfaçe dos métodos ConsultarCalendario e Reservar para que eles
// recebam a data no formato de inteiro. A conersão de string para inteiro será feita
// na função main no momento que o usuario digita a data.

bool ListaDeHoteis::ConsultarCalendario(Data d, list<Hotel>::iterator it, int pessoas)
{
    if ((pessoas == 2) && (it->quartos2[d.mes - 1][d.dia - 1] != 0))
        return true;
    if ((pessoas == 3) && (it->quartos3[d.mes - 1][d.dia - 1] != 0))
        return true;
    if ((pessoas == 4) && (it->quartos4[d.mes - 1][d.dia - 1] != 0))
        return true;
    return false;
}

void ListaDeHoteis::Reservar(list<Hotel>::iterator it, Data inicio, Data fim, Usuario &user, int pessoas)
{
    if (((pessoas == 2) && (user.creditos() < it->preco2) || ((pessoas == 3) && (user.creditos() < it->preco3)) ||
         ((pessoas == 4) && (user.creditos() < it->preco4))))
    {
        // TODO: créditos insuficientes
    }

    if (inicio.mes == fim.mes)
    {
        Data aux;
        aux.mes = inicio.mes;

        // verifica a disponibilidade
        for (int i = (inicio.dia - 1); i < fim.dia; i++)
        {
            aux.dia = i;
            if (!ConsultarCalendario(aux, it, pessoas))
            {
                // TODO: não é possivel reservar pois não há vagas
            }
        }
        if (pessoas == 2)
        {
            for (int i = (inicio.dia - 1); i < fim.dia; i++)
            {
                it->quartos2[(inicio.mes) - 1][i]--;
            }
            user.RegistrarReservaHotel(*(it), inicio, fim, it->preco2, pessoas);
        }
        if (pessoas == 3)
        {
            for (int i = (inicio.dia - 1); i < fim.dia; i++)
            {
                it->quartos3[(inicio.mes) - 1][i]--;
            }
            user.RegistrarReservaHotel(*(it), inicio, fim, it->preco3, pessoas);
        }
        if (pessoas == 4)
        {
            for (int i = (inicio.dia - 1); i < fim.dia; i++)
            {
                it->quartos4[(inicio.mes) - 1][i]--;
            }
            user.RegistrarReservaHotel(*(it), inicio, fim, it->preco4, pessoas);
        }
    }
    else
    {
        Data aux;
        aux.mes = inicio.mes;
        // poderia ser qualquer quartox, o que importa é o mês
        for (int i = (inicio.dia - 1); i < it->quartos2[aux.mes].size(); i++)
        {
            aux.dia = i;
            if (!ConsultarCalendario(aux, it, pessoas))
            {
                // TODO: não há vagas
            }
        }
        aux.mes++;
        while (aux.mes < fim.mes)
        {
            for (int i = 0; i < it->quartos2[aux.mes].size(); i++)
            {
                aux.dia = i;
                if (!ConsultarCalendario(aux, it, pessoas))
                {
                    // TODO: não há vagas
                }
            }
            aux.mes++;
        }
        for (int i = 0; i < fim.dia; i++)
        {
            aux.dia = i;
            if (!ConsultarCalendario(aux, it, pessoas))
            {
                // TODO: não há vagas
            }
        }
        if (pessoas == 2)
        {
            aux.mes = inicio.mes;
            for (int i = (inicio.dia - 1); i < it->quartos2[inicio.mes].size(); i++)
            {
                it->quartos2[(inicio.mes) - 1][i]--;
            }
            aux.mes++;
            while (aux.mes < fim.mes)
            {
                for (int i = 0; i < it->quartos2[aux.mes].size(); i++)
                {
                    it->quartos2[(aux.mes) - 1][i]--;
                }
                aux.mes++;
            }
            for (int i = 0; i < fim.dia; i++)
            {
                it->quartos2[(aux.mes) - 1][i]--;
            }
            user.RegistrarReservaHotel(*(it), inicio, fim, it->preco2, pessoas);
        }
        if (pessoas == 3)
        {
            aux.mes = inicio.mes;
            for (int i = (inicio.dia - 1); i < it->quartos3[inicio.mes].size(); i++)
            {
                it->quartos3[(inicio.mes) - 1][i]--;
            }
            aux.mes++;
            while (aux.mes < fim.mes)
            {
                for (int i = 0; i < it->quartos3[aux.mes].size(); i++)
                {
                    it->quartos3[(aux.mes) - 1][i]--;
                }
                aux.mes++;
            }
            for (int i = 0; i < fim.dia; i++)
            {
                it->quartos3[(aux.mes) - 1][i]--;
            }
            user.RegistrarReservaHotel(*(it), inicio, fim, it->preco3, pessoas);
        }
        if (pessoas == 4)
        {
            aux.mes = inicio.mes;
            for (int i = (inicio.dia - 1); i < it->quartos4[inicio.mes].size(); i++)
            {
                it->quartos4[(inicio.mes) - 1][i]--;
            }
            aux.mes++;
            while (aux.mes < fim.mes)
            {
                for (int i = 0; i < it->quartos4[aux.mes].size(); i++)
                {
                    it->quartos4[(aux.mes) - 1][i]--;
                }
                aux.mes++;
            }
            for (int i = 0; i < fim.dia; i++)
            {
                it->quartos4[(aux.mes) - 1][i]--;
            }
            user.RegistrarReservaHotel(*(it), inicio, fim, it->preco4, pessoas);
        }
    }
}

void ListaDeHoteis::CancelarReserva(list<Hotel>::iterator it, Data inicio, Data fim, Usuario &user, int pessoas)
{
    if (inicio.mes == fim.mes)
    {
        if (pessoas == 2)
        {
            for (int i = (inicio.dia - 1); i < fim.dia; i++)
            {
                it->quartos2[(inicio.mes) - 1][i]++;
            }
            user.ReembolsarReservaHotel(*(it), inicio, fim, it->preco2, pessoas);
        }
        if (pessoas == 3)
        {
            for (int i = (inicio.dia - 1); i < fim.dia; i++)
            {
                it->quartos3[(inicio.mes) - 1][i]++;
            }
            user.ReembolsarReservaHotel(*(it), inicio, fim, it->preco3, pessoas);
        }
        if (pessoas == 4)
        {
            for (int i = (inicio.dia - 1); i < fim.dia; i++)
            {
                it->quartos4[(inicio.mes) - 1][i]++;
            }
            user.ReembolsarReservaHotel(*(it), inicio, fim, it->preco4, pessoas);
        }
    }
    else
    {
        Data aux;
        if (pessoas == 2)
        {
            aux.mes = inicio.mes;
            for (int i = (inicio.dia - 1); i < it->quartos2[inicio.mes].size(); i++)
            {
                it->quartos2[(inicio.mes) - 1][i]++;
            }
            aux.mes++;
            while (aux.mes < fim.mes)
            {
                for (int i = 0; i < it->quartos2[aux.mes].size(); i++)
                {
                    it->quartos2[(aux.mes) - 1][i]++;
                }
                aux.mes++;
            }
            for (int i = 0; i < fim.dia; i++)
            {
                it->quartos2[(aux.mes) - 1][i]++;
            }
            user.ReembolsarReservaHotel(*(it), inicio, fim, it->preco2, pessoas);
        }
        if (pessoas == 3)
        {
            aux.mes = inicio.mes;
            for (int i = (inicio.dia - 1); i < it->quartos3[inicio.mes].size(); i++)
            {
                it->quartos3[(inicio.mes) - 1][i]++;
            }
            aux.mes++;
            while (aux.mes < fim.mes)
            {
                for (int i = 0; i < it->quartos3[aux.mes].size(); i++)
                {
                    it->quartos3[(aux.mes) - 1][i]++;
                }
                aux.mes++;
            }
            for (int i = 0; i < fim.dia; i++)
            {
                it->quartos3[(aux.mes) - 1][i]++;
            }
            user.ReembolsarReservaHotel(*(it), inicio, fim, it->preco3, pessoas);
        }
        if (pessoas == 4)
        {
            aux.mes = inicio.mes;
            for (int i = (inicio.dia - 1); i < it->quartos4[inicio.mes].size(); i++)
            {
                it->quartos4[(inicio.mes) - 1][i]++;
            }
            aux.mes++;
            while (aux.mes < fim.mes)
            {
                for (int i = 0; i < it->quartos4[aux.mes].size(); i++)
                {
                    it->quartos4[(aux.mes) - 1][i]++;
                }
                aux.mes++;
            }
            for (int i = 0; i < fim.dia; i++)
            {
                it->quartos4[(aux.mes) - 1][i]++;
            }
            user.ReembolsarReservaHotel(*(it), inicio, fim, it->preco4, pessoas);
        }
    }
}

void ListaDeHoteis::Avaliar(list<Hotel>::iterator it, Usuario &user, float avaliacao)
{
    if (avaliacao > 10.0)
    {
        // TODO: digite um valor válido
    }
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
            for (int l : x.quartos2[i])
            {
                arquivo_ << l << " ";
            }
            arquivo_ << endl;
        }
        for (int i = 0; i < 12; i++)
        {
            for (int l : x.quartos3[i])
            {
                arquivo_ << l << " ";
            }
            arquivo_ << endl;
        }
        for (int i = 0; i < 12; i++)
        {
            for (int l : x.quartos4[i])
            {
                arquivo_ << l << " ";
            }
            arquivo_ << endl;
        }
        arquivo_ << x.preco2 << endl;
        arquivo_ << x.preco3 << endl;
        arquivo_ << x.preco4 << endl;
        arquivo_ << endl;
    }
    arquivo_.close();
}
