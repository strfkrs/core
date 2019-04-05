#include "spawn.h"
#include "../order.h"
#include "../orderTools.h"
#include "../creep.h"

bool_t addSpawnOrder()
{

   while( isCurrentRoomActive() )
   {
      const Room*       currentRoom = getCurrentRoom();
      queueCounter_t    amountWorker = countCreeps( currentRoom->firstCreep,
                                                    CREEP_ROLE_WORKER,
                                                    currentRoom,
                                                    ORDER_FILTER_CREEP_ROLE | ORDER_FILTER_CREEP_ROOM );
      energy_t       energy = currentRoom->energy;
      energy_t       maxEnergy = currentRoom->maxEnergy;

      for(  Structure* structure = currentRoom->firstStructure;
            isStructureActive(structure);
            structure++ )
      {
         if(    structure->type == STRUCTURE_TYPE_SPAWN
             && structure->energy == structure->maxEnergy )
         {
            addOrder( ORDER_TYPE_SPAWN, getStructureIndex( structure ), 0 );
            setOrderData(0, structure->energy );
         }
      }

      if( ! selectNextRoom() )
         return 0;
   }
   return 1;
}
