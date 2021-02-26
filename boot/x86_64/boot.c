#include "devices/gpu/vga/vga.h"

void kmain(void) {
	const char *name = KERNEL_NAME;
	const char *version = KERNEL_VERSION;

	// Print kernel info
	vga_clear_screen();
	vga_print_string(name, VGA_COLOR_BLACK, VGA_COLOR_GREEN);
	vga_print_character(' ', VGA_COLOR_BLACK, VGA_COLOR_GREEN);
	vga_print_string(version, VGA_COLOR_BLACK, VGA_COLOR_GREEN);

	return;
}