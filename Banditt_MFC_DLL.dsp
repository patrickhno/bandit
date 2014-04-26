# Microsoft Developer Studio Project File - Name="Banditt_MFC_DLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Banditt_MFC_DLL - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Banditt_MFC_DLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Banditt_MFC_DLL.mak" CFG="Banditt_MFC_DLL - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Banditt_MFC_DLL - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Banditt_MFC_DLL - Win32 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Banditt_MFC_DLL - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "d:\develop\Metropol\projects\reality\\" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /D "DLL" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 zlib.lib pnglib.lib glide2x.lib wsock32.lib libdtimt.lib libsrlmt.lib libdxxmt.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libcmt" /nodefaultlib:"libc" /nodefaultlib:"libcd" /out:"c:\realitymakers\banditt\Banditt.dll"

!ELSEIF  "$(CFG)" == "Banditt_MFC_DLL - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "d:\develop\Metropol\projects\reality\\" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_AFXEXT" /D "DLL" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /fo"Debug/Banditt.res" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/Banditt.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 zlib.lib pnglib.lib glide2x.lib wsock32.lib libdtimt.lib libsrlmt.lib libdxxmt.lib Watchdog.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"libcmtd" /nodefaultlib:"libcd" /nodefaultlib:"libc" /out:"c:\realitymakers\banditt\Banditt.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Banditt_MFC_DLL - Win32 Release"
# Name "Banditt_MFC_DLL - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Arm.cpp
# End Source File
# Begin Source File

SOURCE=.\Arm.h
# End Source File
# Begin Source File

SOURCE=.\Banditt.cpp
# End Source File
# Begin Source File

SOURCE=.\Banditt_MFC_DLL.cpp
# End Source File
# Begin Source File

SOURCE=.\Banditt_MFC_DLL.def
# End Source File
# Begin Source File

SOURCE=.\Banditt_MFC_DLL.rc

!IF  "$(CFG)" == "Banditt_MFC_DLL - Win32 Release"

!ELSEIF  "$(CFG)" == "Banditt_MFC_DLL - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Button.cpp
# End Source File
# Begin Source File

SOURCE=.\Button.h
# End Source File
# Begin Source File

SOURCE=.\Coin.cpp
# End Source File
# Begin Source File

SOURCE=.\Coin.h
# End Source File
# Begin Source File

SOURCE=.\Hiscore.cpp
# End Source File
# Begin Source File

SOURCE=.\Hiscore.h
# End Source File
# Begin Source File

SOURCE=.\Image.cpp
# End Source File
# Begin Source File

SOURCE=.\Image.h
# End Source File
# Begin Source File

SOURCE=.\Images.cpp
# End Source File
# Begin Source File

SOURCE=.\Images.h
# End Source File
# Begin Source File

SOURCE=.\MovieScroller.cpp
# End Source File
# Begin Source File

SOURCE=.\MovieScroller.h
# End Source File
# Begin Source File

SOURCE=.\Phone.cpp
# End Source File
# Begin Source File

SOURCE=.\Phone.h
# End Source File
# Begin Source File

SOURCE=.\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\Player.h
# End Source File
# Begin Source File

SOURCE=.\PlayField.cpp
# End Source File
# Begin Source File

SOURCE=.\PlayField.h
# End Source File
# Begin Source File

SOURCE=.\Process_Startup.cpp
# End Source File
# Begin Source File

SOURCE=.\Process_Startup.h
# End Source File
# Begin Source File

SOURCE=.\Roll.cpp
# End Source File
# Begin Source File

SOURCE=.\Roll.h
# End Source File
# Begin Source File

SOURCE=.\ScrollText.cpp
# End Source File
# Begin Source File

SOURCE=.\ScrollText.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TextView.cpp
# End Source File
# Begin Source File

SOURCE=.\TextView.h
# End Source File
# Begin Source File

SOURCE=.\Win32_Conflict.cpp
# End Source File
# Begin Source File

SOURCE=.\Win32_Specific.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Banditt_MFC_DLL.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
