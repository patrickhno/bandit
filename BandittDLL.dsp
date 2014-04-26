# Microsoft Developer Studio Project File - Name="Banditt" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Banditt - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BandittDLL.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BandittDLL.mak" CFG="Banditt - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Banditt - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Banditt - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Banditt - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "c:\develop\projects\Reality\Objects\i386-vc\Banditt\Release"
# PROP Intermediate_Dir "c:\develop\projects\Reality\Objects\i386-vc\Banditt\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G6 /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 libdtimt.lib libsrlmt.lib libdxxmt.lib glide2x.lib zlib.lib pnglib.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"libcmt" /nodefaultlib:"libcd" /out:"c:\RealityMakers\Banditt\Banditt.dll"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "Banditt - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "c:\develop\projects\Reality\Objects\i386-vc\Banditt\Debug"
# PROP Intermediate_Dir "c:\develop\projects\Reality\Objects\i386-vc\Banditt\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G6 /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "DLL" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libdtimt.lib libsrlmt.lib libdxxmt.lib glide2x.lib zlib.lib pnglib.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /pdb:"c:\RealityMakers\Banditt\Banditt.pdb" /debug /machine:I386 /out:"c:\RealityMakers\Banditt\Banditt.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Banditt - Win32 Release"
# Name "Banditt - Win32 Debug"
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

SOURCE=.\Button.cpp
# End Source File
# Begin Source File

SOURCE=.\Button.h
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

SOURCE=.\Win32_Conflict.cpp
# End Source File
# Begin Source File

SOURCE=.\Win32_Specific.cpp
# End Source File
# End Target
# End Project
