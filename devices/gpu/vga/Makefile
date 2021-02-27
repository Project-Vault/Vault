# C Language Compiler block
CFLAGS 		+= -I $(PROJ_PATH)

# Global paths
PROJ_PATH	= ../..
SRC_PATH 	= .
BUILD_PATH	= $(PROJ_PATH)/build

# Files to compile
FILES		= 
OBJ			= $(patsubst %, ./$(OUT_PATH)/%, $(FILES))

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all

# The main target
all : $(FILES)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
