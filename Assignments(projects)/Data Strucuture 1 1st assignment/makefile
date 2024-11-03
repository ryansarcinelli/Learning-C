all: compila executa clean
compila: main.o Filme.o ListacDescritor.o ListaDupEncadeada.o
	gcc main.c Filme.c ListacDescritor.c ListaDupEncadeada.c -o ed1
main.o: main.c
	gcc -c main.c
Filme.o: Filme.c
	gcc -c Filme.c
ListacDescritor.o: ListacDescritor.c
	gcc -c ListacDescritor.c
ListaDupEncadeada.o: ListaDupEncadeada.c
	gcc -c ListaDupEncadeada.c
executa:
	./ed1
clean:
	rm main.o Filme.o ListacDescritor.o ListaDupEncadeada.o