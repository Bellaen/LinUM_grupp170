CC = gcc

MAKE_DIR = @mkdir -p

CFLAGS = -Wall -g -fPIC -Wextra -std=c99

LIB = lib
BUILD = build

LIB_POWER_PATH = .

LIB_POWER_SO = libpower.so

LIB_POWER_SRC = libpower.c

LIB_INSTDIR = /usr/lib

.PHONY : lib
lib : $(LIB_POWER_SO)

.PHONY : install
install : $(LIB_POWER_SO) 
	cp -f $(LIB)/$(LIB_POWER_SO) $(LIB_INSTDIR)

.PHONY : uninstall
uninstall : 
	rm -f $(LIB_INSTDIR)/$(LIB_POWER_SO)

.PHONY : clean
clean :
	rm -rf $(BUILD) $(LIB)
	rm -f *.o

$(LIB_POWER_SO) : libpower.c libpower.h
	$(MAKE_DIR) $(BUILD) $(LIB)
	$(CC) -c $(CFLAGS) libpower.c -o $(BUILD)/libpower.o;
	$(CC) $(CFLAGS) -shared -o $(LIB)/libpower.so $(BUILD)/libpower.o
