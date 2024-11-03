all: compila executa clean
compila: main.o algoritmo.o arquivo.o
	gcc main.c algoritmo.c arquivo.c -o grafo
main.o: main.c
	gcc -c main.c
algoritmo.o: algoritmo.c
	gcc -c algoritmo.c
arquivo.o: arquivo.c
	gcc -c arquivo.c
executa:
	./grafo
clean:
	rm main.o algoritmo.o arquivo.o