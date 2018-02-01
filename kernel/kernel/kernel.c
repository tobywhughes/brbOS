#include <stdio.h>

#include <kernel/tty.h>
#include <arch/i386/vga.h>

void kernel_main(void) {
	terminal_initialize(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
	printf("Hello, kernel World!\nAnd hello newline");
}
