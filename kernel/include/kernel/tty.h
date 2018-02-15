#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <arch/i386/vga.h>

void terminal_initialize(enum vga_color text_color, enum vga_color background_color);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void log_write(const char* data, size_t size);

#endif
