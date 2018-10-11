# Compiler settings
CC = gcc
CFLAGS = -Wall -g -fPIC -Wextra -std=c99

# Normal command
MAKE_DIR = @mkdir -p

# Some folders to create
LIB = lib
BUILD = build
BIN = bin

# Power definitions
LIB_POWER_PATH = ./libpower
LIB_POWER_SO = libpower.so
LIB_POWER_SRC = libpower.c

# Installation path for library
LIB_INSTDIR = /usr/lib

# Installation path for binary
BIN_INSTDIR = /usr/bin

.PHONY : all
all : $(LIB_POWER_SO) test

.PHONY : lib
lib : $(LIB_POWER_SO)

.PHONY : install
install : all
	cp -f $(LIB)/$(LIB_POWER_SO) $(LIB_INSTDIR)
	cp -f $(BIN)/testprog $(BIN_INSTDIR)

.PHONY : uninstall
uninstall : 
	rm -f $(LIB_INSTDIR)/$(LIB_POWER_SO)
	rm -f $(BIN_INSTDIR)/testprog

.PHONY : clean
clean :
	rm -rf $(BUILD) $(LIB) $(BIN)

$(LIB_POWER_SO) : $(LIB_POWER_PATH)/$(LIB_POWER_SRC) $(LIB_POWER_PATH)/libpower.h
	$(MAKE_DIR) $(BUILD) $(LIB)
	$(CC) -c $(CFLAGS) $(LIB_POWER_PATH)/$(LIB_POWER_SRC) -o $(BUILD)/libpower.o;
	$(CC) -shared -o $(LIB)/libpower.so $(BUILD)/libpower.o

.PHONY : test
test: $(LIB_POWER_SO) $(BUILD)/maintest.o
	$(MAKE_DIR) $(BIN)
	$(CC) -L$(LIB)/ -Wl,-rpath,. -lpower $(BUILD)/maintest.o -o $(BIN)/testprog

$(BUILD)/maintest.o : $(LIB_POWER_PATH)/maintest.c
	$(CC) -c $(LIB_POWER_PATH)/maintest.c -o $(BUILD)/maintest.o
