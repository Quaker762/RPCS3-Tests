/*
	Part of the RPCS3 ELF Test Suite

	Implementation of gcmhelper.h

*/
#include "gcmhelper.h"

uint32_t rsx_memory_start;
uint32_t rsx_memory_size;

// Initialise Local Memory
int32_t	gcmMemoryInit(uint32_t base, uint32_t size)
{
	if(base==0)		return -1;
	if(size <= 0)	return -1;

	rsx_memory_start	= base;
	rsx_memory_size		= size; 
}

// Allocate some RSX Local Memory
void* gcmRSXAlloc(uint32_t size)
{
	uint32_t rsx_heap = rsx_memory_start;
	printf("Allocating size %d in RSX memory\n", size);
	rsx_heap += (size + 1023) & (~1023);
	printf("Allocated at address %x(aligned)\n", rsx_heap); 
	return (void*)rsx_heap;
}



