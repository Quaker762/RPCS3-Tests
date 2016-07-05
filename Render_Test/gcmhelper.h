/*
	Part of the RPCS3 ELF Test Suite

	Interface for some GCM Helper functions.
	Mainly to do with Memory and Resource management!

*/
#ifndef GCMHELPER_H
#define GCMHELPER_H
#include <stdio.h>

int32_t	gcmMemoryInit(uint32_t base, uint32_t size);

void*	gcmRSXAlloc(uint32_t size);

#endif