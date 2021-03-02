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