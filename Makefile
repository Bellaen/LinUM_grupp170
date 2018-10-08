main:
	gcc -c -Wall -Werror -fPIC resistance.c
	gcc -shared -o libresistance.so resistance.o
	gcc -L ${PWD} -Wall main.c -o main -lresistance

clean:
	rm libresistance.so
	rm main
	rm resistance.o
