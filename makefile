all:
	gcc -c -Wall -Werror -fPIC resistance.c
	gcc -shared -o libresistance.so resistance.o
	export LD_LIBRARY_PATH=/home/isabella/LinUM/uppgift6:$LD_LIBRARY_PATH
	gcc -L/home/isabella/LinUM/uppgift6/ -Wall main.c -o main -lresistance