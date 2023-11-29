#ifndef LISTADEHOTEIS_H
#define LISTADEHOTEIS_H

#include "Usuario.h"
#include <fstream>
#include <list>
#include <string>

using namespace std;

struct FiltrosHotel
{
    string nome;
    string local;
    int estrelas;
    float avaliacoes;
    bool cafe;
    bool almoco;
    bool jantar;
    int quartos2;
    int quartos3;
    int quartos4;
};

class ListaDeHoteis
{
  public:
    // Cria uma lista de hotéis vazia
    ListaDeHoteis();

    // Lê os dados do arquivo e os coloca na lista de hotéis
    void Inicializar();

    // Encontra um hotel de acordo com as preferências do usuário
    list<Hotel>::iterator Buscar(FiltrosHotel filtros);

    // verifica se há disponibilidade na data desejada pelo usuário
    // (nós) no README ficou faltando a iterator
    // (nós) sugiro mudar o nome do método para disponibilidade
    bool ConsultarCalendario(int dia, int mes, list<Hotel>::iterator it, int pessoas);

    // realiza a reserva, ou seja, diminui o número de vagas disponiveis
    // no periodo desejado e reduz a quantidade de créditos que o usuário
    // possui
    // pensar(nós) situação análoga à classe ListaDeVoos, nesse caso,
    // precisa de um método buscar que busque pelo nome
    void Reservar(string data_inicio, string data_fim, list<Hotel>::iterator it, Usuario user, int pessoas);

    // cancela a reserva, ou seja, reestabelece o número de vagas disponíveis
    // e devolve os créditos ao usuário
    void CancelarReserva(list<Hotel>::iterator it, Usuario user);

    // permite que o usuário avalie o hotel
    void Avaliar(list<Hotel>::iterator it, Usuario user, float avaliacao);

    // grava as informações no arquivo permanente e fecha o arquivo
    void Fechar();

  private:
    list<Hotel> lista_;
    fstream arquivo_;
};

#endif
