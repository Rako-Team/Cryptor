@echo off

set vc=..\..\programs\VC2005

%vc%\VC\Bin\x86_amd64\cl /I %vc%\VC\Include /I %vc%\v7.0\Include loader1.c data.c /TC /Od /Gd /MT /GS- /link /FIXED /DYNAMICBASE:NO /NXCOMPAT:NO /LIBPATH:%vc%\VC\lib\amd64 /LIBPATH:%vc%\v7.0\Lib\x64 opengl32.lib glu32.lib user32.lib ole32.lib oledlg.lib oleaut32.lib gdi32.lib comctl32.lib advapi32.lib urlmon.lib shlwapi.lib kernel32.lib Winmm.lib Version.lib shell32.lib Winspool.lib Secur32.lib Netapi32.lib dbghelp.lib Aclui.lib Activeds.lib credui.lib winscard.lib Wtsapi32.lib Vfw32.lib UxTheme.lib Usp10.lib Ws2_32.lib Wsnmp32.lib CRYPTUI.lib Dnsapi.lib Setupapi.lib Comdlg32.lib Msimg32.lib powrprof.lib Rpcrt4.lib Scarddlg.lib