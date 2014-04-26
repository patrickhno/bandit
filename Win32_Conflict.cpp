
// Copyright (C) 1997-1998 Reality Systems as
// All rights reserved.

#define POSIX_INTERNAL
#include <posix/stdlib.h>
#include "Process_startup.h"
#include <Interface/Garbage.h>

struct ThreadArgs{
	int		argc;
	char	**argv;
};

void ProcessThread(ThreadArgs *a){

	#ifdef _DEBUG

	extern void Initialize_Debug(void);
	Initialize_Debug();
	delete new Startup(a->argc,a->argv);
	extern void Deinitialize_Debug(void);
	Deinitialize_Debug();
	system_CollectAllGarbage();
	memory_shutdown();

	#else

	delete new Startup(a->argc,a->argv);
	system_CollectAllGarbage();

	#endif

}

