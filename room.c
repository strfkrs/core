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
      currentRoom->flags = 0;
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
bool_t isRoomActive(Room* room)     { return  ! isRoomQueueEnd(room) && room->flags; }
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
   return TRUE;
}
/*
 *
 * ROOM DATA
 *
 */
bool_t setRoomData( ROOM_DATA_TYPE type, creepData_t data )
{
   if ( isCurrentRoomQueueEnd() )
      return FALSE;
   switch (type)
   {
      case ROOM_DATA_FLAGS:         currentRoom->flags |= (shortFlags_t)data; break;
      case ROOM_DATA_ENERGY:        currentRoom->energy = (energy_t)data; break;
      case ROOM_DATA_MAX_ENERGY:    currentRoom->maxEnergy = (energy_t)data; break;
      default: return FALSE;
   }
   return TRUE;
}

creepData_t getRoomData( ROOM_DATA_TYPE type )
{
   if ( isCurrentRoomQueueEnd() )
      return FALSE;
   switch (type)
   {
      case ROOM_DATA_ID:            return getRoomIndex(currentRoom);
      case ROOM_DATA_FLAGS:         return currentRoom->flags;
      case ROOM_DATA_ENERGY:        return currentRoom->energy;
      case ROOM_DATA_MAX_ENERGY:    return currentRoom->maxEnergy;
      default: return DATA_ERROR;
   }
}
