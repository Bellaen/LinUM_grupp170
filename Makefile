# Compiler settings
CC = gcc
CFLAGS = -std=c99

# Create directory
MAKE_DIR = @mkdir -p

# Directories to create
BUILD = build
LIB = lib
BIN = bin

# Installation path for binary
USR_BIN = /usr/bin

# Installation path for libraries
USR_LIB = /usr/lib

# Library Power variables
LIB_POWER_PATH = ./libpower
LIB_POWER_SO = libpower.so
LIB_POWER_SRC = libpower.c

# Library Resistance variables
LIB_RESISTANCE_PATH = ./libresistance
LIB_RESISTANCE_SO = libresistance.so
LIB_RESISTANCE_SRC = libresistance.c

# Library Component variables
LIB_COMPONENT_PATH = ./libcomponent
LIB_COMPONENT_SO = libcomponent.so
LIB_COMPONENT_SRC = libcomponent.c

# Main variables
MAIN_PATH = ./main
MAIN_SRC = main.c
MAIN_BIN = main


.PHONY : all

all : $(LIB_RESISTANCE_SO) $(LIB_POWER_SO) $(LIB_COMPONENT_SO) $(MAIN_BIN)

.PHONY : lib

lib : $(LIB_RESISTANCE_SO) $(LIB_POWER_SO) $(LIB_COMPONENT_SO)


$(LIB_POWER_SO) : $(LIB_POWER_PATH)/$(LIB_POWER_SRC) $(LIB_POWER_PATH)/libpower.h
	$(MAKE_DIR) $(BUILD) $(LIB)
	$(CC) -c $(CFLAGS) -fPIC $(LIB_POWER_PATH)/$(LIB_POWER_SRC) -o $(BUILD)/libpower.o;
	$(CC) -shared -o $(LIB)/$(LIB_POWER_SO) $(BUILD)/libpower.o

$(LIB_COMPONENT_SO) : $(LIB_COMPONENT_PATH)/$(LIB_COMPONENT_SRC) $(LIB_COMPONENT_PATH)/libcomponent.h
	$(MAKE_DIR) $(BUILD) $(LIB)
	$(CC) -c $(CFLAGS) -fPIC $(LIB_COMPONENT_PATH)/$(LIB_COMPONENT_SRC) -o $(BUILD)/libcomponent.o;
	$(CC) -shared -o $(LIB)/$(LIB_COMPONENT_SO) $(BUILD)/libcomponent.o -lm

$(LIB_RESISTANCE_SO) : $(LIB_RESISTANCE_PATH)/$(LIB_RESISTANCE_SRC) $(LIB_RESISTANCE_PATH)/libresistance.h
	$(MAKE_DIR) $(BUILD) $(LIB)
	$(CC) -c $(CFLAGS) -fPIC $(LIB_RESISTANCE_PATH)/$(LIB_RESISTANCE_SRC) -o $(BUILD)/libresistance.o;
	$(CC) -shared -o $(LIB)/$(LIB_RESISTANCE_SO) $(BUILD)/libresistance.o

$(MAIN_BIN) : $(LIB_RESISTANCE_SO) $(LIB_POWER_SO) $(LIB_COMPONENT_SO) $(BUILD)/main.o

	$(MAKE_DIR) $(BIN)
	$(CC) -L$(LIB)/ -Wl,-rpath,../$(LIB) $(BUILD)/main.o -o $(BIN)/$(MAIN_BIN) -lm -lresistance -lcomponent -lpower

$(BUILD)/main.o : $(MAIN_PATH)/$(MAIN_SRC)

	$(MAKE_DIR) $(BUILD)
	$(CC) $(CFLAGS) -c $(MAIN_PATH)/$(MAIN_SRC) -o $(BUILD)/main.o


.PHONY : install

install : all

	cp -f $(BIN)/$(MAIN_BIN) $(USR_BIN)

	cp -f $(LIB)/$(LIB_RESISTANCE_SO) $(USR_LIB)

	cp -f $(LIB)/$(LIB_POWER_SO) $(USR_LIB)

	cp -f $(LIB)/$(LIB_COMPONENT_SO) $(USR_LIB)

	sudo make clean

.PHONY : uninstall

uninstall:

	rm -f $(USR_BIN)/$(MAIN_BIN)

	rm -f $(USR_LIB)/$(LIB_RESISTANCE_SO)

	rm -f $(USR_LIB)/$(LIB_POWER_SO)

	rm -f $(USR_LIB)/$(LIB_COMPONENT_SO)


.PHONY : clean

clean:

	rm -rf $(BUILD) $(BIN) $(LIB)




