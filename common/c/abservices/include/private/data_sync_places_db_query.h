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

/*****************************************************************/
/*                                                               */
/* (C) Copyright 2006 by Networks In Motion, Inc.                */
/*                                                               */
/* The information contained herein is confidential, proprietary */
/* to Networks In Motion, Inc., and considered a trade secret as */
/* defined in section 499C of the penal code of the State of     */
/* California. Use of this information by anyone other than      */
/* authorized employees of Networks In Motion is granted only    */
/* under a written non-disclosure agreement, expressly           */
/* prescribing the scope and manner of such use.                 */
/*                                                               */
/*****************************************************************/

/*-
 * data_sync_places_db_query.h: created 2006/09/25 by Mark Goddard.
 */

#ifndef DATA_SYNC_PLACES_DB_QUERY_H
#define DATA_SYNC_PLACES_DB_QUERY_H

#include "datautil.h"
#include "data_sync_add_item.h"
#include "data_sync_delete_item.h"
#include "data_sync_modify_item.h"
#include "nbplace.h"
#include "absynchronizationtypes.h"
#include "nbextappcontent.h"

typedef struct data_sync_places_db_query_ {

	/* Child Elements */
	struct CSL_Vector*			vec_add_item;
	struct CSL_Vector*			vec_delete_item;
	struct CSL_Vector*			vec_modify_item;

	/* Attributes */
	data_string			name;
	uint32				last_sync_generation;
	uint32				db_id;

} data_sync_places_db_query;

NB_Error	data_sync_places_db_query_init(data_util_state* pds, data_sync_places_db_query* spdq);
void		data_sync_places_db_query_free(data_util_state* pds, data_sync_places_db_query* spdq);

tpselt		data_sync_places_db_query_to_tps(data_util_state* pds, data_sync_places_db_query* spdq);

NB_Error	data_sync_places_db_query_add_add_item(data_util_state* pds, data_sync_places_db_query* spdq, int64 local_id, nb_unixTime modtime, NB_Place* pPlace, AB_PlaceMessage* pPlaceMessage);
NB_Error	data_sync_places_db_query_add_add_item_with_ext_app_content(data_util_state* pds, data_sync_places_db_query* spdq, int64 local_id, nb_unixTime modtime, NB_Place* pPlace, AB_PlaceMessage* pPlaceMessage, NB_ExtAppContent* pExtAppContent);
NB_Error	data_sync_places_db_query_add_modify_item(data_util_state* pds, data_sync_places_db_query* spdq, uint64 server_id, nb_unixTime modtime, NB_Place* pPlace, AB_PlaceMessage* pPlaceMessage, AB_PlaceMessageFlags placeMessageFlags);
NB_Error	data_sync_places_db_query_add_modify_item_with_ext_app_content(data_util_state* pds, data_sync_places_db_query* spdq, uint64 server_id, nb_unixTime modtime, NB_Place* pPlace, AB_PlaceMessage* pPlaceMessage, AB_PlaceMessageFlags placeMessageFlags, NB_ExtAppContent* pExtAppContent);

NB_Error	data_sync_places_db_query_add_delete_item(data_util_state* pds, data_sync_places_db_query* spdq, uint64 id);

#endif // DATA_SYNC_PLACES_DB_QUERY_H