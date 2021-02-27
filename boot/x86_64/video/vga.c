#include "vga.h"

static volatile vga_mem_struct vga = { 
	.vga_mem = (uint16_t*) 0xb8000, 
	.vga_mem_index = 0
};

void vga_clear_screen(void) {
	// Clear the memory
	for (uint16_t index = 0; index < (VGA_COLUMN_COUNT * VGA_ROW_COUNT); ++index) {
		vga.vga_mem[index] = 0x0000;
	}

	// Update index
	vga.vga_mem_index = 0;
}

void vga_print_character(const uint8_t character, const uint8_t bg, const uint8_t fg) {
	switch (character) {
		// 
		case '\n':
			vga.vga_mem_index += (vga.vga_mem_index % VGA_COLUMN_COUNT);
			vga.vga_mem_index += VGA_COLUMN_COUNT;
			break;

		//
		case '\t':
			vga.vga_mem_index = (vga.vga_mem_index & (~7)) + 8;
			break;
		
		//
		case '\r':
			break;
	}
    
	// Scroll when the buffer is the 
    if(vga.vga_mem_index >= VGA_COLUMN_COUNT * VGA_ROW_COUNT) {
        vga_scroll(1);
    }

	// Store the symbol
	vga.vga_mem[vga.vga_mem_index++] = VGA_SET_COLOR(character,bg,fg);
}


void vga_print_string(const uint8_t *string, const uint8_t bg, const uint8_t fg) {
	while(*string != '\0') {
        vga_print_character(*string, bg, fg);
        ++string;
    }
}

void vga_scroll(const uint8_t scroll_line_count) {
	// FIXME : use scroll_line_count
	for (uint8_t line = 0; line < VGA_ROW_COUNT - 1; ++line) {
		for (uint8_t index = 0; index < VGA_COLUMN_COUNT; ++index) {
			// Get the offset
			uint16_t offset = (line * VGA_COLUMN_COUNT) + index;

			// Move the data
			vga.vga_mem[offset] = vga.vga_mem[offset + VGA_COLUMN_COUNT];
		}
	}

	// Update the index
	vga.vga_mem_index -= VGA_COLUMN_COUNT;
}