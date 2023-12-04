#include "../include/ListaDeHoteis.h"
#include "../include/ListaDeVoos.h"

#include <iostream>

using namespace std;

int main(void)
{
    try
    {

        ListaDeVoos ldv;
        ldv.Inicializar();
        ListaDeHoteis ldh;
        ldh.Inicializar();

        cout << "Bem-vindo ao ViagemExpress! Aqui você pode comprar passagens aéreas e realizar reservas em hotéis de "
                "forma rápida e prática."
             << endl;
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

        if (opcao == 1)
        {
            // FiltrosVoo fv;

            cout << endl;
            cout << "Digite a cidade de origem (letras maiúsculas e minúsculas): " << endl;
            string origem;
            cin >> origem;
            cout << "Digite a cidade de destino (letras maiúsculas e minúsculas): " << endl;
            string destino;
            cin >> destino;
            cout << "(Passagens apenas para o ano de 2024)" << endl;
            cout << "Digite o dia e o mês do voo (separados por espaços):" << endl;
            Data datavoo;
            cin >> datavoo.dia;
            cin >> datavoo.mes;

            cout << "Estas são as opções: " << endl;
            cout << endl;

            // COLOCAR AQUI A FUNÇÃO EXIBIR VOOS (ORIGEM, DESTINO, DATA)
            // DONE:
            ldv.ExibirVoos(origem, destino, datavoo);
            cout << endl;

            cout << "Digite o código do voo que deseja (letras maiúsculas e minúsculas): " << endl;
            string codigo;
            cin >> codigo;

            // TODO: colocar aqui a função confirmar (código)
            // exibe as informações do voo desejado
            // DONE:
            ldv.Confirmar(codigo);
            cout << "Deseja comprar a passagem econômica ou executiva? (Digite 1 para econômica ou 0 para executiva)"
                 << endl;
            bool eoue;
            cin >> eoue;

            cout << "Confirmar compra? (Digite S para SIM ou N para NÃO)" << endl;
            string soun;
            cin >> soun;

            if (soun == "S" || soun == "s")
            {
                ldv.Comprar(ldv.Buscar(codigo), jao, eoue);
                cout << endl;
                cout << "Obrigado por comprar no ViagemExpress!" << endl;
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;
            }
            else if (soun == "N" || soun == "n")
            {
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;
            }
            else if (!(soun == "S" || soun == "s" || soun == "N" || soun == "n"))
            {
                ExcecaoOpcaoInvalida e;
                throw e;
            }
        }
        else if (opcao == 2)
        {
            // FiltrosHotel fh;

            cout << endl;
            cout << "Digite a cidade em que você deseja se hospedar (letras maiúsculas e minúsculas): " << endl;
            string cidade;
            cin >> cidade;
            cout << "Estas são as opções: " << endl;
            cout << endl;

            // COLOCAR AQUI A FUNÇÃO EXIBIR HOTEIS (CIDADE)
            // DONE:
            ldh.ExibirHoteis(cidade);
            cout << endl;

            cout << "Digite o nome do hotel que deseja (letras maiúculas e minúsculas): " << endl;
            string nome;
            cin >> nome;
            // TODO: colocar aqui a função Confirmar(nome)
            // exibe só as informações do hotel desejado
            // DONE:
            ldh.Confirmar(nome);
            cout << "(Reservas apenas para o ano de 2024)" << endl;
            cout << "Digite o dia e o mês de chegada ao hotel (separados por espaços): " << endl;
            Data datachegada;
            cin >> datachegada.dia;
            cin >> datachegada.mes;
            cout << "Digite o dia e o mês de saída do hotel (separados por espaços): " << endl;
            Data datasaida;
            cin >> datasaida.dia;
            cin >> datasaida.mes;
            cout << "Será um quarto para 2, 3 ou 4 pessoas? (Digite 2, 3 ou 4)" << endl;
            int pessoas;
            cin >> pessoas;
            if ((pessoas > 4) || (pessoas < 2))
            {
                // TODO: número de pessoas inválido
            }
            cout << "Confirmar reserva? (Digite S para SIM ou N para NÃO)" << endl;
            string soun;
            cin >> soun;
            if (soun == "S" || soun == "s")
            {
                ldh.Reservar(ldh.Buscar(nome), datachegada, datasaida, jao, pessoas);
                cout << endl;
                cout << "Obrigado por reservar no ViagemExpress!" << endl;
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;
            }
            else if (soun == "N" || soun == "n")
            {
                cout << "Você será redirecionado ao Menu." << endl;
                cout << endl;
                goto Menu;
            }
            else if (!(soun == "S" || soun == "s" || soun == "N" || soun == "n"))
            {
                ExcecaoOpcaoInvalida e;
                throw e;
            }
        }
        else if (opcao == 3)
        {
            cout << endl;
            // IMPLEMENTAR UMA FUNÇÃO QUE EXIBA TODOS OS VOOS
            // DONE:
            ldv.ExibirTodos();
            cout << endl;
            cout << "Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;
        }
        else if (opcao == 4)
        {
            cout << endl;
            // IMPLEMENTAR UMA FUNÇÃO QUE EXIBA TODOS OS HOTÉIS
            // DONE:
            ldh.ExibirTodos();
            cout << endl;
            cout << "Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;
        }
        else if (opcao == 5)
        {
            cout << endl;
            cout << "Atualmente você possui R$" << jao.creditos() // por que sem centavos?
                 << " de saldo. Quanto deseja adicionar? Digite o valor (sem centavos): " << endl;
            float valor;
            cin >> valor;
            jao.AdicionarCreditos(valor);
            cout << "Valor adicionado com sucesso! Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;
        }
        else if (opcao == 6)
        {
            cout << "Digite o código do voo que deseja cancelar a compra (letras maiúsculas e minúsculas): " << endl;
            string codigo;
            cin >> codigo;
            cout << "Qual é a classe da passagem que deseja cancelar? Digite 1 para econômica ou 0 para executiva:"
                 << endl;
            bool econ_ou_exec;
            cin >> econ_ou_exec;
            ldv.CancelarCompra(ldv.Buscar(codigo), jao, econ_ou_exec);
            // PASSAR SÓ O CÓDIGO COMO PARÂMETRO PRA FACILITAR
            // Não tem como, precisa da classe também. O usuário pode comprar uma passagem econômica
            // e uma executiva no mesmo voo, nada impede. E ele pode querer cancelar só uma das duas
            // também precisa do usuário

            cout << "Cancelamento realizado com sucesso. Você foi reembolsado." << endl;
            cout << "Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;
        }
        else if (opcao == 7)
        {
            cout << "Digite o nome do hotel que deseja cancelar a reserva (letras maiúculas e minúsculas):" << endl;
            string nome;
            cin >> nome;
            cout << "Digite o dia e o mês do iníco da reserva, separados por espaço:" << endl;
            Data inicio;
            cin >> inicio.dia;
            cin >> inicio.mes;
            cout << "Digite o dia e o mês do final da reserva, separados por espaço:" << endl;
            Data fim;
            cin >> fim.dia;
            cin >> fim.mes;
            cout << "Digite o número de pessoas (2, 3 ou 4) para o qual o quarto estava reservado" << endl;
            int pessoas;
            if ((pessoas < 2) || (pessoas > 4))
            {
                // TODO: opção inválida
            }
            cin >> pessoas;
            ldh.CancelarReserva(ldh.Buscar(nome), inicio, fim, jao, pessoas);
            cout << "Cancelamento realizado com sucesso. Você foi reembolsado." << endl;
            cout << "Você será redirecionado ao Menu." << endl;
            goto Menu;
        }
        else if (opcao == 8)
        {
            // IMPLEMENTAR UMA FUNÇÃO QUE EXIBA O NOME, O SALDO, OS VOOS E AS RESERVAS DO USUÁRIO.
            // DONE:
            jao.ExibirDados();
            cout << "Você será redirecionado ao Menu." << endl;
            cout << endl;
            goto Menu;
        }
        else if (opcao == 9)
        {
            cout << endl;
            cout << "Obrigado por usar o ViagemExpress!" << endl;
            jao.logoff();
            return 0;
        }
        else if (opcao < 1 || opcao > 9)
        {
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
    }
    catch (ExcecaoOpcaoInvalida e)
    {
        cout << "Opção inválida." << endl;
    }
    catch (ExcecaoErroArquivoVoos f)
    {
        cout << "Erro ao abrir o arquivo Voos.txt." << endl;
    }
    catch (ExcecaoErroArquivoHoteis g)
    {
        cout << "Erro ao abrir o arquivo Hoteis.txt." << endl;
    }
    catch (ExcecaoValorInvalido h)
    {
        cout << "Valor inválido" << endl;
    }
}
