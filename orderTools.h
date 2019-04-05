#pragma once
#include "core.h"
#include "order.h"
#include "room.h"
#include "creep.h"
#include "structure.h"

static const shortFlags_t ORDER_FILTER_STRUCTURE_TYPE = 0b00000001;
static const shortFlags_t ORDER_FILTER_STRUCTURE_ROOM = 0b00000010;

static const shortFlags_t ORDER_FILTER_CREEP_ROLE = 0b00000001;
static const shortFlags_t ORDER_FILTER_CREEP_ROOM = 0b00000010;

extern queueCounter_t countStructures( const Structure*     first,
                                       const STRUCTURE_TYPE type,
                                       const Room*          room,
                                       const shortFlags_t   filter );

extern queueCounter_t countCreeps( const Creep*         creep,
                                   const CREEP_ROLE     role,
                                   const Room*          room,
                                   const shortFlags_t   filter);
