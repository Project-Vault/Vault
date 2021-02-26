# C Language Compiler block
CFLAGS 		+= -I $(PROJ_PATH)

# GNU Linker block
LDFLAGS		= -m elf_i386 -T $(LINKER_FILE) 

# VGA mode block
VGA_PATH	= vga
VGA_FILES	= $(BUILD_PATH)/vga.o

# Global paths
PROJ_PATH	= ../..
SRC_PATH 	= $(VGA_PATH)
BUILD_PATH	= $(PROJ_PATH)/build

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all vga

# The main target
all : vga

vga : $(VGA_FILES)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)
