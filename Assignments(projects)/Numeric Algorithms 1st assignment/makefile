all: compila executa clean
compila: main.o sistemas_lineares.o fatoracao.o gauss.o gaussjacob.o gaussseidel.o
	gcc main.c sistemas_lineares.c fatoracao.c gauss.c gaussjacob.c gaussseidel.c -o algoritimo1
main.o: main.c
	gcc -c main.c
sistemas_lineares.o: sistemas_lineares.c
	gcc -c sistemas_lineares.c
fatoracao.o: fatoracao.c
	gcc -c fatoracao.c
gauss.o: gauss.c
	gcc -c gauss.c
gaussjacob.o: gaussjacob.c
	gcc -c gaussjacob.c
gaussseidel.o: gaussseidel.c
	gcc -c gaussseidel.c
executa:
	./algoritimo1
clean:
	rm main.o sistemas_lineares.o fatoracao.o gauss.o gaussjacob.o gaussseidel.o