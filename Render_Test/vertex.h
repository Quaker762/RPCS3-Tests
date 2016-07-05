/*
	Part of the RPCS3 ELF Test Suite

	Defines some Vertex stuff 

*/
#ifndef VERTEX_H
#define VERTEX_H

#include <stdint.h>

typedef struct VERTEX
{
	// Co-ordinates
	float x;
	float y;
	float z;

	// Texture Co-ordinates
	float u;
	float v;

	// Colour
	uint32_t rgba;
} Vertex;

#endif