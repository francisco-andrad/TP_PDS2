#ifndef USUARIO_H
#define USUARIO_H

#include <fstream>
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

struct Hotel
{
    string nome;
    string local;
    int estrelas;
    float avaliacoes;
    bool cafe;
    bool almoco;
    bool jantar;
    bool piscina;
    int quartos2[365];
    int quartos3[365];
    int quartos4[365];
    double preco2;
    double preco3;
    double preco4;
};

class Usuario
{
  public:
    // cria um usuário vazio
    Usuario();

    // enontra, abre e lê o arquivo que contém os dados do usuário
    void login(string nome, string senha);

    // adiciona créditos ao usuário
    void AdicionarCreditos(float creditos);

    // registra a compra de uma passagem feita pelo usuário
    void RegistrarCompraPassagem(Voo voo, float preco);

    // registra a reserva de um hotél feita pelo usuário
    void RegistrarReservaHotel(Hotel hotel, string data_chegada, string data_partida, float preco);

    // remove do arquivo do usuário o registro de determinado voo e
    // devolve os créditos gastos
    void ReembolsarCompraPassagem(Voo voo, float preco);

    // remove do arquivo do ususário o registro de determinada reserva e
    // devosve os créditos gastos
    void ReembolsarReservaHotel(Hotel hotel, string data_chegada, string data_partida, float preco);

    // retorna a quantidade de créditos disponiveis
    float creditos();

    // escreve os   dados no arquivo permanente do usuário e fecha o arquivo
    void logoff();

  private:
    string nome_;
    string senha_;
    float creditos_;
    list<string> hoteis_;
    list<string> passagens_;
    fstream arquivo_;
};

#endif
