/**
 * Copyright [2020] [Project Vault Team]
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * you may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "vga.h"

static volatile struct vga_state_struct vga;

void vga_init(const uint8_t param) {
	// Set the VGA memory data
	vga.mem = (uint16_t*) VGA_MEM_ADDR;
	vga.mem_index = 0;
	vga.param = param;

	// Disable the cursor
	__vga_set_cursor(false);
}

void vga_set_param(const uint8_t param) {
	vga.param = param;
}

void vga_clear_screen(void) {
	// Clear the memory
	for (uint16_t index = 0; index < (VGA_COLUMN_COUNT * VGA_ROW_COUNT); ++index) {
		vga.mem[index] = 0x0000;
	}

	// Update index
	vga.mem_index = 0;
}

void vga_print_character(const uint8_t character) {
	switch (character) {
		// 
		case '\n':
			vga.mem_index += (vga.mem_index % VGA_COLUMN_COUNT);
			vga.mem_index += VGA_COLUMN_COUNT;
			break;

		//
		case '\t':
			vga.mem_index = (vga.mem_index & (~7)) + 8;
			break;
		
		//
		case '\r':
			break;
	}
    
	// Scroll when the buffer is the 
    if(vga.mem_index >= VGA_COLUMN_COUNT * VGA_ROW_COUNT) {
        __vga_scroll();
    }

	// Store the symbol
	vga.mem[vga.mem_index++] = VGA_SET_COLOR(character,vga.param);
}


void vga_print_string(const uint8_t *string) {
	while(*string != '\0') {
        vga_print_character(*string);
        ++string;
    }
}

static void __vga_scroll(void) {
	for (uint8_t line = 0; line < VGA_ROW_COUNT - 1; ++line) {
		for (uint8_t index = 0; index < VGA_COLUMN_COUNT; ++index) {
			// Get the offset
			uint16_t offset = (line * VGA_COLUMN_COUNT) + index;

			// Move the data
			vga.mem[offset] = vga.mem[offset + VGA_COLUMN_COUNT];
		}
	}

	// Update the index
	vga.mem_index -= VGA_COLUMN_COUNT;
}

static inline void __vga_set_cursor(bool is_enabled) {
    _outb(VGA_CRTC_ADDR, VGA_CRTC_CURSOR_START);

	// Flip the bit to the corresponding value to enable/disable the cursor
	uint8_t reg_data = _inb(VGA_CRTC_DATA_ADDR);
	if (is_enabled == true)
		reg_data &= ~(1 << 5);
	else 
		reg_data |= (1 << 5);

	_outb(VGA_CRTC_ADDR, reg_data);
}

static inline uint8_t _inb(uint16_t port) {
    uint8_t value;

	// Call Assembly function
    asm volatile ( 
					"inb %1, %0"
                   	: "=a"(value)
                   	: "Nd"(port) 
				);

    return value;
}

static inline void _outb(uint16_t port, uint8_t value) {
    asm volatile ( 
					"outb %0, %1" : :
					"a"(value),
					"Nd"(port) 
				);
}