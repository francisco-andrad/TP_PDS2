# TP_PDS2
**Sistema de Reserva de Passagens/Hotel**

*Descrição do Projeto:*
Como usuário, desejo consultar a disponibilidade de passagens aéreas de diferentes 
origens para diferentes destinos e comprá-las caso seja de meu interesse. Além disso,
 desejo consultar a disponibilidade de hotéis no local de destino e reservar quartos 
 caso seja de meu interesse. Desejo que o programa seja intuitivo e fácil de ser utilizado. 
 (Cancelar passagens e reservas também é importante.) 

*Requisitos do Projeto:*

1.	Usuário e Senha: o programa deve conter um sistema que permite o login de diferentes 
usuários, sendo que as informações de compras e reservas devem ser armazenas para cada usuário.

2.	Consulta: o sistema deve ser capaz de apresentar na tela todos os voos e/ou hotéis que 
o usuário pesquisar utilizando os filtros (atributos). Além disso, o usuário deve também escolher 
quantos e quais filtros utilizar, podendo encerrar um processo de consulta mesmo com poucos filtros.

3.	Compra de Passagens: o usuário deve ser capaz de comprar passagens aéreas (apenas voos 
diretos com possibilidade de extensão da funcionalidade) utilizando o sistema, sendo possível 
escolher entre classe econômica ou executiva. Diferentes companhias oferecem passagens de diferentes 
origens para diversos destinos, portanto, há uma boa variedade para o usuário analisar e escolher. 
Ademais, o usuário deve escolher se quer comprar apenas passagem de ida ou ida e volta. Essa pesquisa 
para comprar uma passagem deve ser fácil e intuitiva. (Uma compra de passagem deve modificar a 
disponibilidade de passagens no banco de dados.)



4.	Reserva de Hotel: o usuário deve ser capaz de reservar um ou mais quartos de hotel, podendo 
escolher a data de check in e check out e realizando uma busca simples, utilizando os filtros de 
acordo com seu interesse. (Uma reserva de quarto deve modificar a disponibilidade de quartos em 
determinado hotel no banco de dados.)

5.	Cancelamento/Modificação de Passagens: o usuário deve ser capaz de cancelar uma compra de 
passagem ou trocar de voo caso seja de seu interesse. (O cancelamento e a troca também modificam 
a disponibilidade de passagens no banco de dados.)


6.	Cancelamento/Modificação de Reserva: o usuário deve ser capaz de cancelar ou modificar a data 
de uma reserva de quarto caso seja de seu interesse. (O cancelamento e a troca também modificam a 
disponibilidade de quartos no banco de dados.)

7.	Exibir Passagens e Reservas feitas: o sistema deve ser capaz de exibir quais foram as compras e 
reservas efetuadas pelo usuário.

*Requisitos Funcionais:*

1.	O programa deve possuir um sistema de usuário e senha.

2.	O sistema deve ser capaz de representar vários voos e hotéis com diferentes atributos.
3.	O sistema deve sempre atualizar o banco de dados a cada nova modificação.

4.	O sistema deve permitir a consulta de disponibilidade de voos e hotéis.

5.	O sistema deve permitir que o usuário compre passagens de ida e volta ou apenas ida.
6.	O sistema deve permitir que o usuário reserve um ou mais quartos de hotel.

7.	O sistema deve permitir a remarcação de uma passagem.
8.	O sistema deve permitir o cancelamento de passagens.

9.	O sistema deve permitir a modificação da data de uma reserva.
10.	O sistema deve permitir o cancelamento de reservas de quartos.

11.	O sistema de filtragem do programa deve permitir que o usuário utilize os filtros que quiser e 
possa realizar uma busca mesmo com poucos filtros.


*Requisitos Não Funcionais:*

1.	O sistema deve ser intuitivo e fácil de ser utilizado.

2.	O código deve ser bem organizado e seguir boas práticas de programação.

3.	O sistema deve ser robusto e capaz de lidar com erros ou situações excepcionais.

4.	O sistema deve ser de fácil extensibilidade. 


*Principais Dificuldades:*

25/10/2023: no momento, nossa principal dificuldade é pensar em como fazer um sistema de reserva de 
hotéis que consiga utilizar um calendário. Nos parece extremamente complexo implementar um sistema 
que consiga armazenar qual a quantidade de quartos disponíveis em cada hotel em cada dia do calendário 
e modificar esses dados de acordo com a reserva. Para o sistema de compra de passagens, isso não é 
necessário.



**CARTÕES CRC**

*Tipos definidos pelos desenvolvedores: (para facilitar a compreensão do leitor)*

    Hotel: tipo que armazena os atributos individuais do hotel. (localização, avaliação, etc.)

    Voo: tipo que armazena os atributos individuais do voo. (origem, destino, etc.)

    FiltrosVoo: tipo para armazenar as preferencias do usuário com relação aos voos na hora de
                 buscar. (companhia aérea, duração, etc.)

    FiltrosHotel: tipo para armazenar as preferencias do usuário com relação aos hotés na hora de
                  buscar. (avaliação, capacidade dos quartos, etc.)



Classe: Usuário 

Responsabilidades:
    Construtor: cria um usuário vazio.
    
    Login: string, string -> FILE* : recebe o nome e a senha de um usuário, abre o arquivo do respectivo usuário,
                                     e retorna o ponteiro para esse arquivo.

    RegistrarCompraPassagem: Voo, FILE* -> void: registra a compra de uma passagem no arquivo do usuário.

    RegistrarReservaHotel: Hotel, FILE* -> void: regisra a reserva de um ou mais quartos no hotel.

    ReembolsarCompraPassagem: Voo, FILE* -> void: remove do arquivo do usuário o registro de determinado voo.

    ReembolsarReservaHotel: Hotel, FILE* -> void: remove do arquivo do usuário o registro de determinada reserva.

    Logoff: FILE* -> void: escreve todos os dados no arquivo permanente do usuário e fecha o arquivo.

Colaborações: FILE*; (?)

                    

Classe: ListaDeVoos (Lista de passagens disponíveis)

Responsabilidades:

    Construtor: constrói uma lista de passagens.

    Inicializar: FILE -> void: Lê as informações do banco de dados e as insere na lista de voos.

    Buscar: string, FiltrosVoo -> iterator: Encontra uma voo de acordo com as necessidades do usuário e retorna um 
                                         iterador para o voo encontrado
    
    Comprar: iterator, Usuário -> void: retira uma passagem (econômica ou executiva) do banco de dados do voo 
                                        selecionado e registra a compra no usuário.
    
    Reembolsar: iterator, Usuário -> void: Cancela a compra no usuário e retorna a passagem para os dados do voo.

    Avaliar:  iterator, Usuário, float -> void: Permite que o usuário avalie um voo.

    Fechar: FILE* -> void: Registra as informações no arquivo de dados permanente e fecha o arquivo.

Colaborações: std::list;

 

Classe: ListaDeHoteis (lista de hotéis disponíveis)

Responsabilidades:
        
    Construtor: Constroi uma lista de hotéis.

    Inicializar: FILE -> void: Lê as informações do banco de dados e as insere na lista de hotéis.

    Buscar: string, FiltrosHotel -> iterator: Encontra um hotél de acordo com as necessidades do usuário e 
                                         retorna um iterador para o hotél encontrado.

    ConsultarCalendário: string -> bool: Verifica se há vagas disponíveis na data pesquisada pelo usuário.

    Reservar: string, iterator, Usuário -> void: Se houver vagas disponíveis, realiza a reserva, ou seja: reduz
                                                 o número de vagas disponíveis do hotel na data especificada e registra
                                                 a reserva no usuário.

    Reembolsar iterator, Usuário -> void: Remove a reserva do usuário e aumenta o número de vagas disponíveis no hotel 
                                          na data da reserva.

    Avaliar: iterator, Usuário, float -> void: Permite que um usuário avalie um hotél.

    Fechar: FILE* -> void: Registra as informações no arquivo de dados permanente e fecha o arquivo.
            
Colaborações: std::list;

  

            
Classe: Interface (Responsável por facilitar a interação com o usuário. Ainda não temos certeza se essa 
                  classe é realmente necessária, pois sua responsabilidade pode ser cumprida na função main
                  ou em outra função.)

Responsabilidades:
    
    Construtor: cria uma interface.

    ???

 
