#include "../include/ListaDeHoteis.h"
#include "../include/ListaDeVoos.h"
#include <iostream>
using namespace std;

int main(void)
{
    try {
 
    cout << "Bem-vindo ao ViagemExpress! Aqui você pode comprar passagens aéreas e realizar reservas em hotéis de forma rápida e prática." << endl;
    cout << endl;
    cout << "Digite seu usuário e senha (caso o usuário não exista, ele será criado automaticamente)." << endl;

    Usuario jao;
    string nome;
    string senha;
    cout << "Usuário:\n";
    cin >> nome;
    cout << "Senha:\n";
    cin >> senha;
    cout << endl;
    jao.login(nome, senha);

    /*cout << "Digite um número para escolher sua opção:" << endl;
    cout << "1 - Comprar passagens aéreas" << endl;
    cout << "2 - Reservar um quarto de hotel" << endl;
    cout << "3 - Exibir todos os voos disponíveis para compra no App" << endl;
    cout << "4 - Exibir todos os hotéis disponíveis para reserva no App" << endl;
    cout << "5 - Adicionar saldo a minha conta" << endl;
    cout << "6 - Sair" << endl;*/
    
    //Aí pra cada opção tem um if com as ações a serem realizadas.


    cout << jao.creditos() << endl;
    jao.AdicionarCreditos(950.00);
    cout << jao.creditos() << endl;
    Voo v;
    v.numero = "2222";
    float p = 150.00;
    jao.RegistrarCompraPassagem(v, p);
    Hotel h;
    h.nome = "hotelhotel";
    string di = "21";
    string df = "24";
    jao.RegistrarReservaHotel(h, di, df, p);
    jao.logoff();
    return 0;

} catch (ExcecaoErroArquivoVoos e) {
    cout << "Erro ao abrir o arquivo Voos.txt." << endl;
}
}
