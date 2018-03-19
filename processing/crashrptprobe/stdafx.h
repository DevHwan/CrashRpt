/************************************************************************************* 
This file is a part of CrashRpt library.
Copyright (c) 2003-2018 The CrashRpt project authors. All Rights Reserved.

Use of this source code is governed by a BSD-style license
that can be found in the License.txt file in the root of the source
tree. All contributing project authors may
be found in the Authors.txt file in the root of the source tree.
***************************************************************************************/

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// Target Windows SDK Version
#include <SDKDDKVer.h>

#include <errno.h>
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include <atldef.h>
#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

// CString-related includes
#define _WTL_USE_CSTRING
#include <atlmisc.h>

#include <shlobj.h>
#include <shellapi.h>

#if _MSC_VER<1400
#define WCSNCPY_S(strDest, sizeInBytes, strSource, count) wcsncpy(strDest, strSource, count)
#define WCSCPY_S(strDestination, numberOfElements, strSource) wcscpy(strDestination, strSource)
#define STRCPY_S(strDestination, numberOfElements, strSource) strcpy(strDestination, strSource)
#define _TCSCPY_S(strDestination, numberOfElements, strSource) _tcscpy(strDestination, strSource)
#define _LTOT_S(value, str, sizeOfStr, radix) _ltot(value, str, radix)
#define _ULTOT_S(value, str, sizeOfStr, radix) _ultot(value, str, radix)
#define _TCSCAT_S(strDestination, size, strSource) _tcscat(strDestination, strSource)
#else
#define WCSNCPY_S(strDest, sizeInBytes, strSource, count) wcsncpy_s(strDest, sizeInBytes, strSource, count)
#define WCSCPY_S(strDestination, numberOfElements, strSource) wcscpy_s(strDestination, numberOfElements, strSource)
#define STRCPY_S(strDestination, numberOfElements, strSource) strcpy_s(strDestination, numberOfElements, strSource)
#define _TCSCPY_S(strDestination, numberOfElements, strSource) _tcscpy_s(strDestination, numberOfElements, strSource)
#define _LTOT_S(value, str, sizeOfStr, radix) _ltot_s(value, str, sizeOfStr, radix)
#define _ULTOT_S(value, str, sizeOfStr, radix) _ultot_s(value, str, sizeOfStr, radix)
#define _TCSCAT_S(strDestination, size, strSource) _tcscat_s(strDestination, size, strSource)
#endif

int _STPRINTF_S(TCHAR* buffer, size_t sizeOfBuffer, const TCHAR* format, ... );



