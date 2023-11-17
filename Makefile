all: main

./obj/ListaDeHoteis.o: ./src/ListaDeHoteis.cpp ./include/ListaDeHoteis.h 
		c++ -c ./src/ListaDeHoteis.cpp -o ./obj/ListaDeHoteis.o

./obj/ListaDeVoos.o: ./src/ListaDeVoos.cpp ./include/ListaDeVoos.h 
		c++ -c ./src/ListaDeVoos.cpp -o ./obj/ListaDeVoos.o 

./obj/Usuario.o: ./src/Usuario.cpp ./include/Usuario.h 
		c++ -c ./src/Usuario.cpp -o ./obj/Usuario.o 

main: ./obj/Usuario.o ./obj/ListaDeVoos.o ./obj/ListaDeHoteis.o	
		c++ ./obj/Usuario.o ./obj/ListaDeVoos.o ./obj/ListaDeHoteis.o -o ./main

