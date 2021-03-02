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

#ifndef VGA_H
#define VGA_H

// VGA mode screen parameters
#define VGA_ROW_COUNT 					25
#define VGA_COLUMN_COUNT 				85

// VGA register and memory addresses
#define VGA_MEM_ADDR					0xb8000
#define VGA_CRTC_ADDR					0x3d4
#define VGA_CRTC_DATA_ADDR				0x3d5
#define VGA_GRAPH_ADDR					0x3ce
#define VGA_GRAPH_DATA_ADDR				0x3cf

// VGA indexes
#define VGA_CRT_HOR_TOTAL				0x00
#define VGA_CRT_END_HOR_DISP			0x01
#define VGA_CRT_START_HOR_BLANK			0x02
#define VGA_CRT_END_HOR_BLANK			0x03
#define VGA_CRT_START_HOR_RETRACE		0x04
#define VGA_CRT_END_HOR_RETRACE			0x05
#define VGA_CRT_VER_TOTAL				0x06
#define VGA_CRT_OVF						0x07
#define VGA_CRT_ROW_SCAN				0x08
#define VGA_CRT_MAX_LINE_SCAN			0x09
#define VGA_CRT_CURSOR_START			0x0A
#define VGA_CRT_CURSOR_END				0x0B
#define VGA_CRT_START_ADDR_HIGH			0x0C
#define VGA_CRT_START_ADDR_LOW			0x0D
#define VGA_CRT_CURSOR_POS_HIGH			0x0E
#define VGA_CRT_CURSOR_POS_LOW			0x0F
#define VGA_CRT_VER_RETRACE_START		0x10
#define VGA_CRT_VER_RETRACE_END			0x11
#define VGA_CRT_VER_END					0x12
#define VGA_CRT_VER_END					0x12
#define VGA_CRT_VER_END					0x12
#define VGA_CRT_VER_END					0x12
#define VGA_CRT_VER_END					0x12
#define VGA_CRT_VER_END					0x12
#define VGA_CRT_HOR_TOTAL				0x18

// Colors
#define VGA_COLOR_BLACK   				0x0
#define VGA_COLOR_BLUE    				0x1
#define VGA_COLOR_GREEN   				0x2
#define VGA_COLOR_CYAN   				0x3
#define VGA_COLOR_RED     				0x4
#define VGA_COLOR_MAGENTA 				0x5
#define VGA_COLOR_BROWN   				0x6
#define VGA_COLOR_WHITE   				0x7

#endif /* VGA_H */