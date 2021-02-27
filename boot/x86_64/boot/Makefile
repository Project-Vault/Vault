# C Language Compiler block
CFLAGS 		+= -I $(PROJ_PATH) -DKERNEL_NAME=\""$(KERNEL_NAME)"\" -DKERNEL_VERSION=\""$(VERSION)"\"

# Global paths
PROJ_PATH	= ../../..
SRC_PATH 	= .
OUT_PATH	= $(PROJ_PATH)/build

# C files to compile
C_FILES		= $(wildcard *.c)
ASM_FILES	= $(wildcard *.s)

# Assembly files to compile
C_OBJ		= $(patsubst %.c, ./$(OUT_PATH)/%.o, $(C_FILES))
ASM_OBJ		= $(patsubst %.s, ./$(OUT_PATH)/%.o, $(ASM_FILES))

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all

# The main target
all : $(C_OBJ) $(ASM_OBJ)

# Suffix rules
$(OUT_PATH)/%.o: $(SRC_PATH)/%.s
	$(ASM) -o $@ $< $(ASMCFLAGS)

$(OUT_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)