
// Copyright (C) 1997-1998 Reality Systems as
// All rights reserved.

// Windows specific stuff

#include <windows.h>
#include <posix/stdlib.h>
#define INTERNAL_DEFINES
#include <posix/stdio.h>
#include <time.h>
#include "Process_startup.h"
#include <Interface/Debug.h>
#include <Interface/rme_Memory.h>
#include <Interface/Kernel.h>

bool Initialized;

struct ThreadArgs{
	int		argc;
	char	**argv;
};

#include <Interface/Process.h>

typedef void (*print_func)(char *);

#include <Interface/globals.h>

#ifdef _DEBUG
__declspec(dllexport) void *Constructor(Process *proc, Host *hst, Driver *drv, print_func pf, int adrv, HANDLE con, DynamicArray *Input, DynamicArray *Stats, struct MemEnt *_last, void *(*al)(int,int,char*,int), void (*fre)(void*,char*,int), void *(*real)(void*,int,char*,int), double speed, struct Hook *str_hooks, int *str_masksize, long *str_mask){
#else
__declspec(dllexport) void *Constructor(Process *proc, Host *hst, Driver *drv, print_func pf, int adrv, HANDLE con, DynamicArray *Input, DynamicArray *Stats, struct MemEnt *_last, void *(*al)(int,int), void (*fre)(void*), void *(*real)(void*,int), double speed, struct Hook *str_hooks, int *str_masksize, long *str_mask){
#endif

	extern struct Hook *string_hooks;
	extern int *string_masksize;
	extern long *string_mask;
	string_hooks = str_hooks;
	string_masksize = str_masksize;
	string_mask = str_mask;

//return 0;

//	extern char root_path[1024];
//	if(proc->Root) sprintf(root_path,proc->Root);
//	else sprintf(root_path,"");

	__globals::SetSpeed(speed);
	#ifdef _DEBUG
	init_Memory(al,fre,real,0);
	#else
	init_Memory(al,fre,real);
	#endif

//return 0;

	extern Driver *Drivers;
	extern Host *host;
	host = hst;
	Drivers = drv;

	extern print_func stdio_print;
	stdio_print = pf;
	Kernel::Time();

	extern HANDLE Win_Console;
	Win_Console = con;
	extern Process *ThisProcess;
	ThisProcess = proc;

	extern int ActiveDriver;
	ActiveDriver = adrv;

	extern DynamicArray *Entries;
	Entries = Input;

extern bool Initialized;
	Initialized = false;

	ThreadArgs args={0,0}; //argc,argv};
	DWORD dwThreadID = 0;
void ProcessThread(ThreadArgs *a);
	HANDLE hThread = CreateThread(
		NULL,
		0,
		(LPTHREAD_START_ROUTINE)ProcessThread,
		&args,
		0,
		&dwThreadID);

#if 0

	CreateThread(
		NULL,
		0,
		(LPTHREAD_START_ROUTINE)MessageThread,
		proc,
		0,
		&dwThreadID);

#endif
while(!Initialized){
	Sleep(500);
}

	return 0;
}
/*
BOOL WINAPI DllEntryPoint(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

#include "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static AFX_EXTENSION_MODULE PROJNAMEDLL = { NULL, NULL };

extern "C" int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved){
	if(dwReason == DLL_PROCESS_ATTACH){
		TRACE0("PROJNAME.DLL Initializing!\n");

		// Extension DLL one-time initialization
		AfxInitExtensionModule(PROJNAMEDLL, hInstance);

		// Insert this DLL into the resource chain
		new CDynLinkLibrary(Dll3DLL);
	}else if (dwReason == DLL_PROCESS_DETACH)
	{
	TRACE0("PROJNAME.DLL Terminating!\n");
	}
	return 1;   // ok
}
*/
