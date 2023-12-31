#ifndef LISTADEVOOS_H
#define LISTADEVOOS_H

#include "Usuario.h"
#include <fstream>
#include <list>
#include <string>

using namespace std;

// isso aqui ainda é útil?
struct FiltrosVoo
{
    string origem;
    string destino;
    string data_partida;
    string hora_partida;
    // string data_chegada;
    // string hora_chegada;
    string companhia;
    // float preco_economica;
    // float preco_executiva;
};

class ListaDeVoos
{
  public:
    // constroi uma lista de voos vazia
    ListaDeVoos();

    // Lê as informações do arquivo e as insere na lista
    void Inicializar();

    // encontra um voo de acordo com as necessidades do usuário
    list<Voo>::iterator Buscar(string codigo);

    // exibe todas as opções disponíveis de acordo com as
    // necessidades do usuário
    void ExibirVoos(string origem, string destino, Data data);

    // Exibe TODOS os voos disponíveis
    void ExibirTodos();

    // exibe na tela as informações do voo que o usuário pretende comprar
    void Confirmar(string codigo);

    // efetua a compra, ou seja, diminui a quantidade de assentos disponiveis no
    // voo e diminui a quantidade de créditos que o usuário possui
    // pensar(nós): talvez seja melhor passar o numero do voo, por
    // exemplo, e depois chamar o método buscar dentro do método Comprar. O mesmo
    // vale para a função CancelarCompra e Avaliar.
    // nesse caso, teria que ter um método buscar que use o número do voo
    // como critério, cai na parte de polimorfismo
    void Comprar(list<Voo>::iterator it, Usuario &user, bool economica);

    // cancela a compra, ou seja, reestabelece o número de assentos disponiveis no
    // voo e a quantidade de créditos que o usuário possui
    void CancelarCompra(list<Voo>::iterator it, Usuario &user, bool economica);

    // permite que o usuário avalie um voo
    void Avaliar(list<Voo>::iterator it, Usuario &user, float avaliacao);

    // registra os dados no arquivo permanente e fecha o arquivo
    void Fechar();

  private:
    list<Voo> lista_;
    fstream arquivo_;
};

struct ExcecaoErroArquivoVoos
{
};

#endif
