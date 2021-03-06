#include "room.h"

static queueMax_t     MAX_ROOMS = 30;
static Room           rooms[MAX_ROOMS];
static Room*          currentRoom;

const queueCounter_t getRoomIndex(Room* room)
{
   return (((size_t)currentRoom)/sizeof(Room))-(((size_t)rooms)/sizeof(Room));
}
void initRooms()
{
   for( currentRoom = rooms; currentRoom < &rooms[MAX_ROOMS]; currentRoom++ )
   {
      currentRoom->active = FALSE;
   }
   currentRoom = rooms;
}
void resetCurrentRoom()
{
   currentRoom = rooms;
}
Room* getCurrentRoom() { return currentRoom; }
bool_t isRoomQueueEnd(Room* room)   { return    room >= &rooms[MAX_ROOMS]; }
bool_t isCurrentRoomQueueEnd()      { return    isRoomQueueEnd(currentRoom); }
bool_t isRoomActive(Room* room)     { return  ! isRoomQueueEnd(room) && room->active; }
bool_t isCurrentRoomActive()        { return    isRoomActive(currentRoom); }

bool_t selectNextRoom()
{
   if ( isCurrentRoomQueueEnd() )
      return FALSE;

   currentRoom++;
   return TRUE;
}


bool_t addRoom( const shortFlags_t flags )
{
   if ( isCurrentRoomQueueEnd() )
      return FALSE;

   currentRoom->firstCreep = getCurrentCreep();
   currentRoom->firstStructure = getCurrentStructure();
   currentRoom->flags = flags;
   currentRoom->active = TRUE;
   return TRUE;
}
/*
 *
 * ROOM DATA
 *
 */
bool_t setCurrentRoomMember( ROOM_MEMBER member, creepData_t data )
{
   if ( isCurrentRoomQueueEnd() )
      return FALSE;
   switch (member)
   {
      case ROOM_MEMBER_FLAGS:         currentRoom->flags |= (shortFlags_t)data; break;
      case ROOM_MEMBER_ENERGY:        currentRoom->energy = (energy_t)data; break;
      case ROOM_MEMBER_MAX_ENERGY:    currentRoom->maxEnergy = (energy_t)data; break;
      default: return FALSE;
   }
   return TRUE;
}

creepData_t getCurrentRoomMember( ROOM_MEMBER member )
{
   if ( isCurrentRoomQueueEnd() )
      return FALSE;
   switch (member)
   {
      case ROOM_MEMBER_ID:            return getRoomIndex(currentRoom);
      case ROOM_MEMBER_FLAGS:         return currentRoom->flags;
      case ROOM_MEMBER_ENERGY:        return currentRoom->energy;
      case ROOM_MEMBER_MAX_ENERGY:    return currentRoom->maxEnergy;
      default: return DATA_ERROR;
   }
}
