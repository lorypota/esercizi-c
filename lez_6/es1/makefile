# File di progetto per la compilazione del codice
# dell'esercizio 1. Quelle scritte solo le regole
# che devono essere applicate per ottenere il 
# il risultato (target) indicato a partire dai file
# specificati.
#
# target: file di input necessari
# <TAB> comando per generare il target dai file di input
#
# makefile è usato dal programma make che processa le regole
# e le applica se i file target o i file intermedi non esistono
# o sono stati modificati dall'ultima escuzione.
#
# Vedere il materiale di approfondimento

main.exe: test_nsqrt.o nsqrt.o
	g++ test_nsqrt.o nsqrt.o -o main.exe

test_nsqrt.o: test_nsqrt.cpp
	g++ -c test_nsqrt.cpp -o test_nsqrt.o

nsqrt.o: nsqrt.cpp
	g++ -c nsqrt.cpp -o nsqrt.o

