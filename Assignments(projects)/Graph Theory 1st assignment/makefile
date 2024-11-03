all: compila executa clean
compila: main.o arquivo.o grafo.o
	gcc main.c arquivo.c grafo.c -o grafo
main.o: main.c
	gcc -c main.c
arquivo.o: arquivo.c
	gcc -c arquivo.c
grafo.o: grafo.c
	gcc -c grafo.c
executa:
	./grafo
clean:
	rm main.o arquivo.o grafo.o