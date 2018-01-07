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

    @file nbgmnbmheaderchunk.h
*/
/*
    (C) Copyright 2010 by Networks In Motion, Inc.

    The information contained herein is confidential, proprietary
    to Networks In Motion, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of Networks In Motion is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/
#ifndef _NBGM_NBM_FILE_CHUNK_H_
#define _NBGM_NBM_FILE_CHUNK_H_
#include "nbgmnbmchunk.h"
#include "nbrevector2.h"

/*! \addtogroup NBRE_Mapdata
*  @{
*/
/*! \addtogroup NBGM_NBMFile
*  @{
*/

class NBGM_NBMHeaderChunk: public NBGM_NBMChunk
{
    friend class NBGM_NBMChunkFactory;
public:
    uint16 Version() const {return mVersion;}
    const NBRE_Vector2f& RefCenter() const {return mRefCenter;}

private:
    explicit NBGM_NBMHeaderChunk(const NBGM_NBMChunkInfo& chunkInfo);
    ~NBGM_NBMHeaderChunk();

private:
    /// Inherited from NBGM_NBMChunk
    virtual void ReadImpl(NBGM_NBMField& field) ;
    virtual void WriteImpl(NBGM_NBMField& field) const ;

private:
    uint16          mVersion;
    NBRE_Vector2f   mRefCenter;
};

/** @} */
/** @} */
#endif