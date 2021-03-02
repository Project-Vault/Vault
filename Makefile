# Copyright [2020] [Project Vault Team]
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# you may obtain a copy of the License at
# 
#   http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

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
DRIVERS_PATH	= drivers

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
.PHONY : all test version clean make_dir vault_kernel boot devices

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
drivers : 
	cd $(DRIVERS_PATH) && $(MAKE)

# Build the kernel
vault_kernel : make_dir boot devices
	$(LD) -o $(BUILD_PATH)/$@ $(wildcard $(BUILD_PATH)/*.o) $(BOOT_LINK)

test : vault_kernel
	qemu-system-x86_64 -kernel $(BUILD_PATH)/$<