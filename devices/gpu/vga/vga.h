#ifndef VGA_H
#define VGA_H

#include "misc/types/types.h"

// VGA mode screen parameters
#define VGA_ROW_COUNT 					25
#define VGA_COLUMN_COUNT 				85

// Colors
#define VGA_COLOR_BLACK   				0x0
#define VGA_COLOR_BLUE    				0x1
#define VGA_COLOR_GREEN   				0x2
#define VGA_COLOR_CYAN   				0x3
#define VGA_COLOR_RED     				0x4
#define VGA_COLOR_MAGENTA 				0x5
#define VGA_COLOR_BROWN   				0x6
#define VGA_COLOR_WHITE   				0x7

// Print manipulation
#define VGA_SET_BG(bg)				(bg << 12)
#define VGA_SET_FG(fg)				(fg << 8)
#define VGA_SET_COLOR(sym,bg,fg) 	(VGA_SET_BG(bg) | VGA_SET_FG(fg) | sym)
#define VGA_GET_SYM(block)			(block | 0xFF00)
#define VGA_GET_COLOR(block)		(block >> 8)
#define VGA_GET_BG(block)			(VGA_GET_COLOR(block) >> 4)
#define VGA_GET_FG(block)			(VGA_GET_COLOR(block) | 0xF0)

typedef struct {
	uint16_t* vga_mem;
	uint16_t vga_mem_index;
} vga_mem_struct;

void vga_clear_screen(void);
void vga_print_character(const uint8_t character, const uint8_t bg, const uint8_t fg);
void vga_print_string(const uint8_t *string, const uint8_t bg, const uint8_t fg);
void vga_scroll(const uint8_t scroll_line_count);

#endif // VGA_H