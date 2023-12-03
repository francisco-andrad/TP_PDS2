#ifndef LISTADEHOTEIS_H
#define LISTADEHOTEIS_H

#include "Usuario.h"
#include <fstream>
#include <list>
#include <string>

using namespace std;

// isso aqui ainda é util?
struct FiltrosHotel
{
    string nome;
    string local;
    int estrelas;
    float avaliacoes;
    bool cafe;
    bool almoco;
    bool jantar;
    bool piscina;
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
    list<Hotel>::iterator Buscar(string nome);

    // Exibe na tela todos os hoteis disponíves no local pesquisado
    void ExibirHoteis(string local);

    // Exibe na tela somente o hotel desejado para que o usuário possa conferir
    // as informações
    void Confirmar(string nome);

    // verifica se há disponibilidade na data desejada pelo usuário
    // (nós) no README ficou faltando a iterator
    // (nós) sugiro mudar o nome do método para disponibilidade
    bool ConsultarCalendario(Data data, list<Hotel>::iterator it, int pessoas);

    // realiza a reserva, ou seja, diminui o número de vagas disponiveis
    // no periodo desejado e reduz a quantidade de créditos que o usuário
    // possui
    // pensar(nós) situação análoga à classe ListaDeVoos, nesse caso,
    // precisa de um método buscar que busque pelo nome
    void Reservar(list<Hotel>::iterator it, Data inicio, Data fim, Usuario &user, int pessoas);

    // cancela a reserva, ou seja, reestabelece o número de vagas disponíveis
    // e devolve os créditos ao usuário
    void CancelarReserva(list<Hotel>::iterator it, Data chegada, Data partida, Usuario &user, int pessoas);

    // permite que o usuário avalie o hotel
    void Avaliar(list<Hotel>::iterator it, Usuario &user, float avaliacao);

    // grava as informações no arquivo permanente e fecha o arquivo
    void Fechar();

  private:
    list<Hotel> lista_;
    fstream arquivo_;
};

struct ExcecaoErroArquivoHoteis
{
};

#endif
