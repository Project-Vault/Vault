# C Language Compiler block
CFLAGS 		+= -I $(PROJ_PATH) -DKERNEL_NAME=\""$(KERNEL_NAME)"\" -DKERNEL_VERSION=\""$(VERSION)"\"

# GNU Linker block
LDFLAGS		= -m elf_i386 -T $(LINKER_FILE) 

# Global paths
PROJ_PATH	= ..
SRC_PATH 	= $(ARCH)
OUT_PATH	= $(PROJ_PATH)/build

# Files to compile
FILES		= boot.o loader.o
OBJ			= $(patsubst %, ./$(OUT_PATH)/%, $(FILES))

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all

# The main target
all : $(OBJ)

# Suffix rules
$(OUT_PATH)/%.o: $(SRC_PATH)/%.s
	$(ASM) -o $@ $< $(ASMCFLAGS)

$(OUT_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)