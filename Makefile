all: main
	
main:
	gcc -c -Wall -Werror -fPIC resistance.c
	gcc -shared -o libresistance.so resistance.o
	gcc -L. -Wall main.c -o main -lresistance

clean:
	rm libresistance.so
	rm main
	rm resistance.o

install:
	sudo cp main /usr/local/bin

uninstall:
	sudo rm /usr/local/bin/main
