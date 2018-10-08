main:
	gcc -c -Wall -Werror -fPIC resistance.c
	gcc -shared -o libresistance.so resistance.o
	gcc -L ${HOME}/LinUM/uppgift6/ -Wall main.c -o main -lresistance

clean:
	rm libresistance.so
	rm main
	rm resistance.o
