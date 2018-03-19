/************************************************************************************* 
This file is a part of CrashRpt library.
Copyright (c) 2003-2018 The CrashRpt project authors. All Rights Reserved.

Use of this source code is governed by a BSD-style license
that can be found in the License.txt file in the root of the source
tree. All contributing project authors may
be found in the Authors.txt file in the root of the source tree.
***************************************************************************************/

// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

// Target Windows SDK Version
#include <SDKDDKVer.h>

#include <errno.h>
#include <atldef.h>
#include <atlbase.h>
#include <atlwin.h>
#include <atlapp.h>

extern CAppModule _Module;
#include <atlwin.h>
// CString-related includes
#define _WTL_USE_CSTRING
#include <atlmisc.h>
#include <new.h>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
#include <string>
#include <dbghelp.h>
#include <shlobj.h>
#include <Psapi.h>
#include <time.h>
#include <shellapi.h>
#include <signal.h>
#include <exception>
#include <sys/stat.h>
#include <psapi.h>
#include <rtcapi.h>

// Below are some macro definitions expanding into secured functions for newer versions of Visual C++
// and into insecure functions for old versions of Visual C++
#if _MSC_VER<1400
#define _TCSCPY_S(strDestination, numberOfElements, strSource) _tcscpy(strDestination, strSource)
#define WCSNCPY_S(strDest, sizeInBytes, strSource, count) wcsncpy(strDest, strSource, count)
#define STRCPY_S(strDestination, numberOfElements, strSource) strcpy(strDestination, strSource)
#else
#define _TCSCPY_S(strDestination, numberOfElements, strSource) _tcscpy_s(strDestination, numberOfElements, strSource)
#define WCSNCPY_S(strDest, sizeInBytes, strSource, count) wcsncpy_s(strDest, sizeInBytes, strSource, count)
#define STRCPY_S(strDestination, numberOfElements, strSource) strcpy_s(strDestination, numberOfElements, strSource)
#endif



