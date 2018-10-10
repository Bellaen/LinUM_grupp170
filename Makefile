main:
	gcc -c -Wall -Werror -fPIC resistance.c
	gcc -shared -o libresistance.so resistance.o
	gcc -o main main.c libresistance.so -Wl,-rpath,.

clean:
	rm libresistance.so
	rm main
	rm resistance.o
