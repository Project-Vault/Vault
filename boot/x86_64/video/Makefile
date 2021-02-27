# C Language Compiler block
CFLAGS 		+= -I $(PROJ_PATH)

# Global paths
PROJ_PATH	= ../../..
SRC_PATH 	= .
OUT_PATH	= $(PROJ_PATH)/build

# Files to compile
FILES		= $(wildcard *.c)
OBJ			= $(patsubst %.c, ./$(OUT_PATH)/%.o, $(FILES))

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all

# The main target
all : $(OBJ)

$(OUT_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)