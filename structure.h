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


typedef enum STRUCTURE_MEMBER
{
   STRUCTURE_MEMBER_ID,
   STRUCTURE_MEMBER_FLAGS,
   STRUCTURE_MEMBER_STRUCTURE_TYPE,
   STRUCTURE_MEMBER_ENERGY,
   STRUCTURE_MEMBER_MAX_ENERGY

} STRUCTURE_MEMBER;
//
// STRUCTS
//
typedef struct Room Room;

typedef struct Structure
{
   bool_t          active;
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
