#pragma once
#include "core.h"
#include "room.h"
//
// CONSTANTS
//
static const shortFlags_t STRUCTURE_FLAG_OWN =     0b00000001;
static const shortFlags_t STRUCTURE_FLAG_HOSTILE = 0b00000010;

typedef enum STRUCTURE_TYPE
{
   STRUCTURE_TYPE_ALL,
   STRUCTURE_TYPE_SPAWN,
   STRUCTURE_TYPE_SOURCE

} STRUCTURE_TYPE;


typedef enum STRUCTURE_DATA_TYPE
{
   STRUCTURE_DATA_ID,
   STRUCTURE_DATA_FLAGS,
   STRUCTURE_DATA_STRUCTURE_TYPE,
   STRUCTURE_DATA_ENERGY,
   STRUCTURE_DATA_MAX_ENERGY

} STRUCTURE_DATA_TYPE;
//
// STRUCTS
//
typedef struct Room Room;

typedef struct Structure
{
   shortFlags_t    flags;
   STRUCTURE_TYPE  type;
   Room*           room;
   energy_t        energy;
   energy_t        maxEnergy;
} Structure;
//
// public funcs
//
extern void                   initStructures();
extern Structure*             getCurrentStructure();
extern void                   resetCurrentStructure();
extern bool_t                 selectNextStructure();
extern bool_t                 isStructureActive(Structure* structure);
extern bool_t                 isStructureQueueEnd(Structure* structure);
extern bool_t                 isCurrentStructureActive();
extern bool_t                 isCurrentStructureQueueEnd();
extern const queueCounter_t   getStructureIndex(Structure* structure);
