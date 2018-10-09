# Compiler settings
CC = gcc
CFLAGS = -Wall -g -fPIC -Wextra -std=c99

# Normal command
MAKE_DIR = @mkdir -p

# Some folders to create
LIB = lib
BUILD = build

# Power definitions
LIB_POWER_PATH = ./libpower
LIB_POWER_SO = libpower.so
LIB_POWER_SRC = libpower.c

# Installation path for library
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

$(LIB_POWER_SO) : $(LIB_POWER_PATH)/libpower.c $(LIB_POWER_PATH)/libpower.h
	$(MAKE_DIR) $(BUILD) $(LIB)
	$(CC) -c $(CFLAGS) $(LIB_POWER_PATH)/libpower.c -o $(BUILD)/libpower.o;
	$(CC) $(CFLAGS) -shared -o $(LIB)/libpower.so $(BUILD)/libpower.o
