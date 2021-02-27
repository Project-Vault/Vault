#
BOOT_PATH 	= boot

#
VIDEO_PATH	= video

# Disable preinstalled suffixes
.SUFFIXES:

# Declare phony targets
.PHONY : all boot video

# The main target
all : boot video

boot :
	cd $(BOOT_PATH) && $(MAKE)

video :
	cd $(VIDEO_PATH) && $(MAKE)