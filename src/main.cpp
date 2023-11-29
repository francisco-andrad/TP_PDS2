#include "../include/ListaDeHoteis.h"
#include "../include/ListaDeVoos.h"
#include <iostream>
using namespace std;

int main(void)
{
    try {

    Usuario jao;
    string nome;
    string senha;
    cout << "nome:\n";
    cin >> nome;
    cout << "senha:\n";
    cin >> senha;
    jao.login(nome, senha);
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
