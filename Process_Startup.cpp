
// Copyright (C) 1997-1998 RealityMakers Entertainment as
// All rights reserved.

//#include <Interface/Debug.h>
#include <posix/stdio.h>
#include <posix/stdlib.h>

#include <Interface/Process.h>
#include "Process_startup.h"

static Process *GetCurrentProcess(void){
	extern Process *ThisProcess;
	return ThisProcess;
}

//void Boot(int,char**){}	// Dummy

Startup::Startup(int argc, char **argv) : Message(){
//	extern char root_path[1024];
	extern void main(int,char**);
//	printf("%s\n",root_path);
	main(argc, argv);
}

Startup::~Startup(){
	AddPacket(0);
	SendTo(GetCurrentProcess()->GetName());
}

