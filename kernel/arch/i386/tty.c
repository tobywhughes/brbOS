#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>
#include <arch/i386/vga.h>
#include <asm/asmio.h>

#define PORT 0x3f8

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

void terminal_initialize(enum vga_color text_color, enum vga_color background_color ) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(text_color, background_color);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
	unsigned char uc = c;
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void terminal_newline()
{
	terminal_column = 0;
	terminal_row++;
}

void terminal_write(const char* data, size_t size) {
	log_write(data, size);
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == '\n')
			terminal_newline();
		else
			terminal_putchar(data[i]);
	}		
}

void log_write(const char* data, size_t size){
	for (size_t i = 0; i < size; i++)
	{
		outb(PORT, data[i]);
	}
}

void terminal_writestring(const char* data) {
	size_t data_len = strlen(data);
	terminal_write(data, data_len);
	outb(PORT, 'A');
	log_write(data, data_len);
}
