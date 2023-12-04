#include "../include/ListaDeHoteis.h"
#include "../include/ListaDeVoos.h"

#include <iostream>
using namespace std;

int main(void)
{
    // ListaDeVoos ldv;
    Usuario jao;
    string nome;
    string senha;
    cout << "nome: \n";
    cin >> nome;
    cout << "senha: \n";
    cin >> senha;
    jao.login(nome, senha);
    ListaDeHoteis ldh;
    ldh.Inicializar();
    //  ldv.Inicializar();
    //  ldv.Confirmar("JJ3104");
    //   jao.AdicionarCreditos(500.00);
    //   ldv.Comprar(ldv.Buscar("JJ3104"), jao, true);
    //  ldv.CancelarCompra(ldv.Buscar("JJ3104"), jao, true);
    //  ldv.Fechar();
    Data in;
    Data fim;
    in.dia = 1;
    in.mes = 10;
    fim.dia = 12;
    fim.mes = 10;
    ldh.Confirmar("Hotel do Sol");
    ldh.Reservar(ldh.Buscar("Hotel do Sol"), in, fim, jao, 2);
    ldh.Fechar();
    jao.logoff();

    return 0;
}
