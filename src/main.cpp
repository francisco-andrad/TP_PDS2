#include "../include/ListaDeHoteis.h"
#include "../include/ListaDeVoos.h"
#include <iostream>
using namespace std;

int main(void)
{
    try {

    ListaDeVoos ldv;
    ldv.Inicializar();
    ListaDeHoteis ldh;
    ldh.Inicializar();
 
    cout << "Bem-vindo ao ViagemExpress! Aqui você pode comprar passagens aéreas e realizar reservas em hotéis de forma rápida e prática." << endl;
    cout << endl;
    cout << "Digite seu usuário e senha (caso o usuário não exista, ele será criado automaticamente)." << endl;

    Usuario jao;
    string nome;
    string senha;
    cout << "Usuário: " << endl;
    cin >> nome;
    cout << "Senha: " << endl;
    cin >> senha;
    cout << endl;
    jao.login(nome, senha);

    Menu:

    cout << "MENU" << endl;
    cout << "Digite um número para escolher sua opção:" << endl;
    cout << "1 - Comprar passagens aéreas" << endl;
    cout << "2 - Reservar um quarto de hotel" << endl;
    cout << "3 - Exibir todos os voos disponíveis para compra no App" << endl;
    cout << "4 - Exibir todos os hotéis disponíveis para reserva no App" << endl;
    cout << "5 - Adicionar saldo a minha conta" << endl;
    cout << "6 - Cancelar compra de passagem" << endl;
    cout << "7 - Cancelar reserva de quarto" << endl;
    cout << "8 - Exibir informações do usuário" << endl;
    cout << "9 - Sair" << endl;

    int opcao;
    cin >> opcao;

    if (opcao == 1) {
        FiltrosVoo fv;

        cout << endl;
        cout << "Digite a cidade de origem (letras maiúsculas e minúsculas): " << endl;
        cin >> fv.origem;
        cout << "Digite a cidade de destino (letras maiúsculas e minúsculas): " << endl;
        cin >> fv.destino;
        cout << "Digite a data (apenas ida) (formato DD/MM/2024):" << endl;
        cin >> fv.data_partida;

        ldv.Buscar(fv); //Busca com base apenas na origem, destino e data para exibir todos os voos disponíveis na tela.

        cout << "Estas são as opções: " << endl;
        cout << endl;

        // Dar um cout aqui que imprima todos os voos encontrados na tela e suas especificações //

        cout << endl;


        if ( /* só foi retornado um voo */) {
            cout << "Deseja comprar uma passagem para esse voo? (Digite S para SIM ou N para NÃO)" << endl;
            string soun;
            cin >> soun;

            if (soun == "S" || soun == "s") {
                cout << "Deseja comprar a passagem econômica ou executiva? (Digite 1 para econômica ou 2 para executiva)" << endl;
                int eoue;
                cin >> eoue;

                if (eoue == 1) {
                    ldv.Comprar(ldv.Buscar(fv), jao, true);
                } else if (eoue == 2) {
                    ldv.Comprar(ldv.Buscar(fv), jao, false);
                } else if (eoue < 1 || eoue > 2) {
                    ExcecaoOpcaoInvalida e;
                    throw e;
                }

                cout << endl;
                cout << "Obrigado por comprar no ViagemExpress!" << endl;
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;

            } else if (soun == "N" || soun == "n") {
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;

            } else if (!(soun == "S" || soun == "s" || soun == "N" || soun == "n")) {
                ExcecaoOpcaoInvalida e;
                throw e;
            }
            
        } else {
            cout << "Selecione um voo (digite as especificações do voo que deseja)." << endl;
            cout << "Companhia aérea (letras maiúsculas e minúsculas): " << endl;
            cin >> fv.companhia;
            cout << "Horário da partida (formato 00:00): " << endl;
            cin >> fv.hora_partida;
            cout << endl;
            ldv.Buscar(fv);

            // Dar cout no voo que aparecer //

            cout << endl;

            cout << "Deseja comprar uma passagem para esse voo? (Digite S para SIM ou N para NÃO)" << endl;
            string soun;
            cin >> soun;

            if (soun == "S" || soun == "s") {
                cout << "Deseja comprar a passagem econômica ou executiva? (Digite 1 para econômica ou 2 para executiva)" << endl;
                int eoue;
                cin >> eoue;

                if (eoue == 1) {
                    ldv.Comprar(ldv.Buscar(fv), jao, true);
                } else if (eoue == 2) {
                    ldv.Comprar(ldv.Buscar(fv), jao, false);
                } else if (eoue < 1 || eoue > 2) {
                    ExcecaoOpcaoInvalida e;
                    throw e;
                }

                cout << endl;
                cout << "Obrigado por comprar no ViagemExpress!" << endl;
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;


            } else if (soun == "N" || soun == "n") {
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;
            } else if (!(soun == "S" || soun == "s" || soun == "N" || soun == "n")) {
                ExcecaoOpcaoInvalida e;
                throw e;
            }
        }


            

    } else if (opcao == 2) {
        FiltrosHotel fh;

        cout << endl;
        cout << "Digite a cidade em que você deseja se hospedar (letras maiúsculas e minúsculas): " << endl;
        cin >> fh.local;
        cout << "Estas são as opções: " << endl;

        // Dar um cout aqui com todas as opções de hotel da cidade escolhida.

        cout << endl;

        cout << "Digite o nome do hotel que deseja (letras maiúculas e minúsculas): " << endl;
        cin >> fh.nome;
        cout << "(Reserva para o ano de 2024.)" << endl;
        cout << "Digite o dia e o mês da chegada ao hotel (separados por espaços): " << endl;
        Data datachegada;
        cin >> datachegada.dia;
        cin >> datachegada.mes;
        cout << "Digite o dia e o mês da saída do hotel (separados por espaços): " << endl;
        Data datasaida;
        cin >> datasaida.dia;
        cin >> datasaida.mes;
        cout << "Será um quarto para 2, 3 ou 4 pessoas? (Digite 2, 3 ou 4)" << endl;
        int pessoas;
        cin >> pessoas;

        cout << "Deseja realizar a reserva? (Digite S para SIM ou N para NÃO)" << endl;
        string soun;
        cin >> soun;
        if (soun == "S" || soun == "s") {
            ldh.Reservar (datachegada, datasaida, ldh.Buscar(fh), jao, pessoas);
            cout << endl;
            cout << "Obrigado por reservar no ViagemExpress!" << endl;
            cout << "Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;

        } else if (soun == "N" || soun == "n") {
            cout << "Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;

        } else if (!(soun == "S" || soun == "s" || soun == "N" || soun == "n")) {
            ExcecaoOpcaoInvalida e;
            throw e;
        }



    } else if (opcao == 3) {

    } else if (opcao == 4) {

    } else if (opcao == 5) {
        cout << endl;
        cout << "Atualmente você possui R$" << jao.creditos() << " de saldo. Quanto deseja adicionar? Digite o valor (sem centavos): " << endl;
        float valor;
        cin >> valor;
        jao.AdicionarCreditos(valor);
        cout << "Valor adicionado com sucesso! Você será redirecionado ao Menu." << endl;
        cout << endl;
        goto Menu;

    } else if (opcao == 6) {

    } else if (opcao == 7) {

    } else if (opcao == 8) {

    } else if (opcao == 9) {
        cout << endl;
        cout << "Obrigado por usar o ViagemExpress!" << endl;
        jao.logoff();
        return 0;
    } else if (opcao < 1 || opcao > 9) {
        ExcecaoOpcaoInvalida e;
        throw e;
    }
    

    ldv.Fechar();
    ldh.Fechar();


    /*cout << jao.creditos() << endl;
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
    return 0;*/

} catch (ExcecaoOpcaoInvalida e) {
    cout << "Opção inválida." << endl;
} catch (ExcecaoErroArquivoVoos f) {
    cout << "Erro ao abrir o arquivo Voos.txt." << endl;
} catch (ExcecaoErroArquivoHoteis g) {
    cout << "Erro ao abrir o arquivo Hoteis.txt." << endl;
} catch (ExcecaoValorInvalido h) {
    cout << "Valor inválido" << endl;
}
}
