#ifndef LISTADEHOTEIS_H
#define LISTADEHOTEIS_H

#include "Usuario.h"
#include <list>
#include <string>

using namespace std;

struct FiltrosHotel
{
    int estrelas;
    float avaliacoes;
    bool cafe;
    bool almoco;
    bool jantar;
    bool quartos2;
    bool quartos3;
    bool quartos4;
};

class ListaDeHoteis
{
  public:
    // Cria uma lista de hotéis vazia
    ListaDeHoteis();

    // Lê os dados do arquivo e os coloca na lista de hotéis
    void Inicializar(FILE *arq);

    // Encontra um hotel de acordo com as preferências do usuário
    list<Hotel>::iterator Buscar(string local, FiltrosHotel filtros);

    // verifica se há disponibilidade na data desejada pelo usuário
    // (nós) no README ficou faltando a iterator
    // (nós) sugiro mudar o nome do método para disponibilidade
    bool ConsultarCalendario(string data, list<Hotel>::iterator it);

    // realiza a reserva, ou seja, diminui o número de vagas disponiveis
    // no periodo desejado e reduz a quantidade de créditos que o usuário
    // possui
    // pensar(nós) situação análoga à classe ListaDeVoos, nesse caso,
    // precisa de um método buscar que busque pelo nome
    void Reservar(string data_inicio, string data_fim, list<Hotel>::iterator it, Usuario user);

    // cancela a reserva, ou seja, reestabelece o número de vagas disponíveis
    // e devolve os créditos ao usuário
    void CancelarReserva(list<Hotel>::iterator it, Usuario user);

    // permite que o usuário avalie o hotel
    void Avaliar(list<Hotel>::iterator it, Usuario user, float avaliacao);

    // grava as informações no arquivo permanente e fecha o arquivo
    void Fechar(FILE *arq);

  private:
    list<Hotel> lista_;
};

#endif
