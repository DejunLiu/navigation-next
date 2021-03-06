/*
Copyright (c) 2018, TeleCommunication Systems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the TeleCommunication Systems, Inc., nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED. IN NO EVENT SHALL TELECOMMUNICATION SYSTEMS, INC.BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!--------------------------------------------------------------------------

    @file     palimpl.h
    @date     02/10/2012
    @defgroup PALIMPL_H PAL Pal Functions

    @brief    Provides a platform-dependent Pal implementation.

*/
/*
    (C) Copyright 2011 by Telecommunication Systems, Inc.

    The information contained herein is confidential, proprietary
    to Telecommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of Telecommunication Systems is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/

#ifndef PALIMPL_H
#define PALIMPL_H

#include "pal.h"
#include "taskmanager.h"
#include "taskqueue.h"
#include "thread.h"
#include "finishfunctionmanager.h"
#include "timerimpl.h"
#include "palevent.h"

using namespace nimpal;
using namespace taskqueue;

struct _timer;

struct PAL_Instance {
    PAL_Config             config;
    TimerManager* timerManager;
    FinishFunctionManager* functionManager;
    TaskManager*           taskManager;      /*!< PAL task manager */
    PAL_Error              lastError;        /* Used in some cases to return error code from functions which cannot do this in standart way */
    PAL_Event*             destroyEvent;
    nb_boolean             isBackground;
};

#endif
