# Microsoft Developer Studio Project File - Name="Banditt" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Banditt - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Banditt.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Banditt.mak" CFG="Banditt - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Banditt - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Banditt - Win32 Debug" (based on "Win32 (x86) Application")
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
# PROP Output_Dir "C:\develop\projects\Reality\Objects\ix86-vc\Banditt\Release"
# PROP Intermediate_Dir "C:\develop\projects\Reality\Objects\ix86-vc\Banditt\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G6 /W3 /GX /Zi /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 libdtimt.lib libsrlmt.lib libdxxmt.lib zlib.lib pnglib.lib glide2x.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /profile /map:"C:\RealityMakers\Banditt\Banditt.map" /debug /machine:I386 /nodefaultlib:"libcmt" /nodefaultlib:"libcd" /out:"C:\RealityMakers\Banditt\Banditt.exe"

!ELSEIF  "$(CFG)" == "Banditt - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "C:\develop\projects\Reality\Objects\ix86-vc\Banditt\Debug"
# PROP Intermediate_Dir "C:\develop\projects\Reality\Objects\ix86-vc\Banditt\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o NUL /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libdtimt.lib libsrlmt.lib libdxxmt.lib pnglib.lib zlib.lib glide2x.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

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

SOURCE=.\TextView.cpp
# End Source File
# Begin Source File

SOURCE=.\TextView.h
# End Source File
# End Target
# End Project
