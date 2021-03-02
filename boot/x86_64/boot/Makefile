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