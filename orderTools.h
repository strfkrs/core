#pragma once
#include "core.h"
#include "order.h"
#include "room.h"
#include "creep.h"
#include "structure.h"

extern queueCounter_t countStructures(
      const Structure*      first,
      const STRUCTURE_TYPE  type,
      const Room*           room );

extern queueCounter_t countCreeps(
      const Creep*      creep,
      const CREEP_ROLE  role,
      const Room*       room );
