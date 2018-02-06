#ifndef _ASM_ASMIO_H
#define _ASM_ASMIO_H

#include <stddef.h>

static inline void outb(uint16_t port, uint8_t value);
static inline uint8_t inb(uint16_t port);

#endif
