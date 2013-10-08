#pragma once

#define WIN32_LEAN_AND_MEAN
#define _WIN32_DCOM 

#pragma warning(disable : 4995)
// AMGetErrorText
#pragma comment(lib, "quartz.lib") 
// DXGetErrorString9, DXGetErrorDescription9
#pragma comment(lib, "dxerr9.lib") 
#pragma comment(lib, "ole32.lib")

#include <tchar.h>

#include <windows.h>
#include <objbase.h>
#include <dxerr9.h>
#include <dshow.h> 