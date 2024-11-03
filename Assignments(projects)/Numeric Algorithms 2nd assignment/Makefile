all: compila executa clean
compila: main.o curva.o
	gcc main.c curva.c -o programa -lm
main.o: main.c
	gcc -c main.c
curva.o: curva.c
	gcc -c curva.c
executa:
	./programa
clean:
	rm main.o curva.o
