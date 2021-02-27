# Kernel info
KERNEL_NAME		= VAULT KERNEL
VERSION			= 0.0.0
ARCH			= x86_64

# C language compiler block
CC				= gcc
CFLAGS			= -I. -m32 -c

# Assembly compiler block
ASM				= nasm
ASMCFLAGS		= -f elf32

# GNU linker block
LD				= ld
LDFLAGS			= -m elf_i386

# GNU rm block
RM 				= rm
RMFLAGS			= -rf

# GNU mkdir block
MKDIR 			= mkdir
MKDIRFLAGS		= -p

# Boot subfolder block
BOOT_PATH 		= boot
BOOT_LD_PATH	= $(BOOT_PATH)/$(ARCH)/linker
BOOT_LD_FILES	= $(wildcard $(BOOT_LD_PATH)/*.ld)
BOOT_LINK		= $(LDFLAGS) $(patsubst %, -T %, $(BOOT_LD_FILES))

# Devices subfolder block
DEVICES_PATH	= devices

# Building block
PROJ_PATH		= .
BUILD_PATH		= $(PROJ_PATH)/build

# Export tools
export ARCH
export CC
export CFLAGS
export ASM
export ASMCFLAGS
export LD
export RM
export RMFLAGS
export MKDIR
export MKDIRFLAGS
export KERNEL_NAME
export VERSION

# Declare phony targets
.PHONY : all version clean make_dir  vault_kernel boot devices

# The main target
all : make_dir vault_kernel

# Create a directory to build files in
make_dir : 
	$(MKDIR) $(MKDIRFLAGS) $(BUILD_PATH)

# Delete all the compiled files
clean : 
	$(RM) $(RMFLAGS) $(BUILD_PATH)

# Print the version of the current kernel
version : 
	@echo $(KERNEL_NAME) $(VERSION)

# Build boot modules
boot : 
	cd $(BOOT_PATH) && $(MAKE)

# Build devices drivers modules
devices : 
	cd $(DEVICES_PATH) && $(MAKE)

# Build the kernel
vault_kernel : boot devices
	$(LD) -o $(BUILD_PATH)/$@ $(wildcard $(BUILD_PATH)/*.o) $(BOOT_LINK)