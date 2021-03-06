#ifndef _ASM_ASMIO_H
#define _ASM_ASMIO_H

#include <stddef.h>
#include <stdint.h>

static inline void outb(uint16_t port, uint8_t value)
{
	asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

static inline uint8_t inb(uint16_t port)
{
	uint8_t ret;
	asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));

	return ret;
}

#endif
