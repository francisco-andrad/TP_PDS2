// #include "Usuario.h"
#include <list>
#include <string>

using namespace std;

struct Voo
{
    string numero;
    string origem;
    string destino;
    string data_partida;
    string hora_partida;
    string data_chegada;
    string hora_chegada;
    string companhia;
    float preco_economica;
    float preco_executiva;
    int assentos_economica;
    int assentos_executiva;
};

struct FiltrosVoo
{
    string data_partida;
    string hora_partida;
    string data_chegada;
    string hora_chegada;
    string companhia;
    float preco_economica;
    float preco_executiva;
};

class ListaDeVoos
{
  public:
    // constroi uma lista de voos vazia
    ListaDeVoos();

    // Lê as informações do arquivo e as insere na lista
    void Inicializar(FILE *arq);

    // encontra um voo de acordo com as necessidades do usuário
    list<Voo>::iterator Buscar(string origem, string destino, FiltrosVoo filtros);

    // efetua a compra, ou seja, diminui a quantidade de assentos disponiveis no
    // voo e diminui a quantidade de créditos que o usuário possui
    // pensar(nós): talvez seja melhor passar o numero do voo, por
    // exemplo, e depois chamar o método buscar dentro do método Comprar. O mesmo
    // vale para a função CancelarCompra e Avaliar.
    // nesse caso, teria que ter um método buscar que use o número do voo
    // como critério, cai na parte de polimorfismo
    void Comprar(list<Voo>::iterator it, Usuario user);

    // cancela a compra, ou seja, reestabelece o número de assentos disponiveis no
    // voo e a quantidade de créditos que o usuário possui
    void CancelarCompra(list<Voo>::iterator it, Usuario user);

    // permite que o usuário avalie um voo
    void Avaliar(list<Voo>::iterator it, Usuario user, float avaliacao);

    // registra os dados no arquivo permanente e fecha o arquivo
    void Fechar(FILE *arq);

  private:
    list<Voo> lista_;
};
