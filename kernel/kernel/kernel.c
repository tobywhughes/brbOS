#include <stdio.h>
#include <stdlib.h>

#include <kernel/tty.h>
#include <arch/i386/vga.h>

void kernel_main(void) {
	terminal_initialize(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
	printf("STARTING TESTING SEQUENCE\n\n");
	printf("NUMBER TEST:\n\n");
	printf("Decimal\n\n");
	int negative = -1234;
	int zero = 0;
	printf("%d\n", negative);
	printf("%d\n", zero);
	for(int i = 10; i < 1000000; i = i * 10)
	{
		printf("%d\n", i); 
	}
}
