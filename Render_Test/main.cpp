/*
	Part of the RPCS3 ELF Test Suite

	Draws a triangle to the screen using GCM.
	Each GCM command is 64KiB in size
	'Local Memory' is actually referring to the RSX (GPU) Memory. 

*/

#include <stdio.h>
#include <sysutil\sysutil_sysparam.h>
#include <cell\gcm.h>
#include <stdlib.h>

#include "gcmhelper.h"
#include "vertex.h"

#define GCM_BUFFER_SIZE		1024*1024 // Room for 16 GCM commands	
#define GCM_NUM_COMMANDS	16
#define GCM_COMMAND_SIZE	16*1024

uint32_t vid_width;
uint32_t vid_height;

void* rsx_mem_start = NULL;

// Initialises GCM
static int32_t initGCM(void)
{
	rsx_mem_start = memalign(GCM_BUFFER_SIZE, GCM_NUM_COMMANDS * GCM_BUFFER_SIZE); // Align our RSX video memory on a 1MiB bounday!

	if(cellGcmInit(GCM_COMMAND_SIZE, GCM_BUFFER_SIZE, rsx_mem_start) != CELL_OK)
	{
		printf("Failed to initialise GCM!\n");
		return -1;
	}

	// Get the GCM Config
	CellGcmConfig gcmConf;
	cellGcmGetConfiguration(&gcmConf);
	printf("====GCM VIDEO CONFIGURATION====\n");
	printf("RSX Memory Base Addr:				0x%p\n", gcmConf.localAddress);
	printf("RSX IO Base Addr:					0x%p\n", gcmConf.ioAddress);
	printf("RSX Memory Size:					0x%x\n", gcmConf.localSize);
	printf("RSX IO Memory Size:					0x%x\n", gcmConf.ioSize);

	if(gcmMemoryInit((uint32_t)&gcmConf.localAddress, (uint32_t)gcmConf.localSize) == -1)
	{
		printf("Unable to initialise RSX Memory");
		exit(1);
	}
	return 0;

}

static void initScreen()
{
	CellVideoOutResolution res;
	cellVideoOutGetResolution(CELL_VIDEO_OUT_RESOLUTION_720, &res);

	vid_width	= res.width;
	vid_height	= res.height;

	printf("====GCM VIDEO RESOLUTION====\n");
	printf("Video Width:	%d\n", vid_width);
	printf("Video Height:	%d\n", vid_height);

}

int main(void)
{
	if(initGCM() != 0)
	{
		printf("FAILED TO INIT!!");
		exit(1);
	}

	initScreen();

}