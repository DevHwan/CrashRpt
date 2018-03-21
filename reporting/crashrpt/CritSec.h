/************************************************************************************* 
This file is a part of CrashRpt library.
Copyright (c) 2003-2018 The CrashRpt project authors. All Rights Reserved.

Use of this source code is governed by a BSD-style license
that can be found in the License.txt file in the root of the source
tree. All contributing project authors may
be found in the Authors.txt file in the root of the source tree.
***************************************************************************************/

// File: CritSec.h
// Description: Critical section wrapper classes. Code of CCritSec and CAutoLock classes 
// is taken from DirectShow base classes and modified in some way.
// Authors: zexspectrum
// Date: 

#pragma once

#ifndef _CRITSEC_H
#define _CRITSEC_H

#include <cassert>
#include <mutex>

// wrapper for whatever critical section we have
class CCritSec final
{
    // make copy constructor and assignment operator inaccessible

    CCritSec(const CCritSec &refCritSec) = delete;
    CCritSec &operator=(const CCritSec &refCritSec) = delete;

    std::recursive_mutex m_mtx;

public:

    CCritSec() = default;
    ~CCritSec() = default;

    void Lock() 
    {
        m_mtx.lock();
    };

    void Unlock() 
    {
        m_mtx.unlock();
    };
};

// locks a critical section, and unlocks it automatically
// when the lock goes out of scope
class CAutoLock 
{
    // make copy constructor and assignment operator inaccessible

    CAutoLock(const CAutoLock &refAutoLock) = delete;
    CAutoLock& operator=(const CAutoLock &refAutoLock) = delete;

protected:
    CCritSec * m_pLock;

public:
    CAutoLock(__in CCritSec * plock)
        : m_pLock(nullptr)
    {
        assert(plock);
        m_pLock = plock;
        m_pLock->Lock();
    };

    ~CAutoLock() 
    {
        m_pLock->Unlock();
    };
};


#endif  //_CRITSEC_H
