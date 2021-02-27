# Architecture-dependend files build
X86_PATH	= x86_64
ARM_PATH	= arm
ARM64_PATH	= arm64

# Build the project for x86_64
ifeq ($(ARCH), x86_64)
BOOT_PATH 	= $(X86_PATH)
endif

# Build the project for arm
ifeq ($(ARCH), arm)
BOOT_PATH 	= $(ARM_PATH)
endif

# Build the project for arm64
ifeq ($(ARCH), arm64)
BOOT_PATH 	= $(ARM64_PATH)
endif

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all boot

# The main target
all : boot

boot :
	cd $(BOOT_PATH) && $(MAKE)