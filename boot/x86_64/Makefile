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

# Path to the boot section (real mode boot)
BOOT_PATH 	= boot

# Path to video section (real mode screen output)
VIDEO_PATH	= video

# Declare phony targets
.PHONY : all boot video

# The main target
all : boot video

boot :
	cd $(BOOT_PATH) && $(MAKE)

video :
	cd $(VIDEO_PATH) && $(MAKE)