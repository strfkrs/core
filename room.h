#pragma once
#include "core.h"
#include "creep.h"
#include "structure.h"
//
// CONSTANTS
//
static const shortFlags_t ROOM_FLAG_OWN =     0b00000001;
static const shortFlags_t ROOM_FLAG_HOSTILE = 0b00000010;
static const shortFlags_t ROOM_FLAG_NEUTRAL = 0b00000100;

typedef enum ROOM_MEMBER
{
   ROOM_MEMBER_ID,
   ROOM_MEMBER_FLAGS,
   ROOM_MEMBER_ENERGY,
   ROOM_MEMBER_MAX_ENERGY

} ROOM_MEMBER;
//
// STRUCTS
//
typedef struct Creep Creep;

typedef struct Room
{
   bool_t               active;
   shortFlags_t         flags;
   struct Creep*        firstCreep;
   struct Structure*    firstStructure;
   energy_t             energy;
   energy_t             maxEnergy;

} Room;
//
// public funcs
//
extern void                   initRooms();
extern Room*                  getCurrentRoom();
extern void                   resetCurrentRoom();
extern bool_t                 selectNextRoom();
extern bool_t                 isRoomActive(Room* room);
extern bool_t                 isRoomQueueEnd(Room* room);
extern bool_t                 isCurrentRoomActive();
extern bool_t                 isCurrentRoomQueueEnd();
extern const queueCounter_t   getRoomIndex(Room* room);
