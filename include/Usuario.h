#include <string>
#include <vector>

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
    void RegistrarCompraPassagem(FILE *usu_arq, Voo voo);

    // registra a reserva de um hotél feita pelo usuário
    void RegistrarReservaHotel(FILE *usu_arq, Hotel hotel);

    // remove do arquivo do usuário o registro de determinado voo e
    // devolve os créditos gastos
    void ReembolsarCompraPassagem(FILE *usu_arq, Voo voo);

    // remove do arquivo do ususário o registro de determinada reserva e
    // devosve os créditos gastos
    void ReembolsarReservaHotel(FILE *usu_arq, Hotel hotel);

    // escreve os dados no arquivo permanente do usuário e fecha o arquivo
    void logoff(FILE *usu_arq);

  private:
    string nome_;
    string senha_;
    float creditos_;
    vector<Hotel> reservas_;
    vector<Voo> passagens_;
};
