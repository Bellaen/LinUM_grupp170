lib: libcomponent.c libcomponent.h
	gcc -o libcomponent.so -shared -fPIC libcomponent.c