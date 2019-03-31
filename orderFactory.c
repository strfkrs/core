#include "orderFactory.h"
#include "orderTools.h"
#include "order.h"
#include "room.h"
#include "creep.h"
#include "structure.h"

void factoryResetSources()
{
   resetCurrentRoom();
   resetCurrentCreep();
   resetCurrentStructure();
}

bool_t addSpawnOrder()
{
   factoryResetSources();

   while( isCurrentRoomActive() )
   {
      const Room*       currentRoom = getCurrentRoom();
      queueCounter_t    amountWorker = countCreeps(
            currentRoom->firstCreep,
            CREEP_ROLE_WORKER,
            currentRoom );
      energy_t       energy = currentRoom->energy;
      energy_t       maxEnergy = currentRoom->maxEnergy;

      for(  Structure* structure = currentRoom->firstStructure;
            isStructureActive(structure);
            structure++ )
      {
         if(    structure->type == STRUCTURE_TYPE_SPAWN
             && structure->energy == 300
             && structure->maxEnergy >= 300 )
         {
            addOrder( ORDER_TYPE_SPAWN_WORKER, currentRoom, NULL, 0 );
         }
      }

      if( ! selectNextRoom() )
         return 0;
   }
   return 1;
}


bool_t factoryCreateOrders()
{
   do
   {
      if( addSpawnOrder() ) break;

      break;
   } while( selectNextOrder() );

   return isCurrentOrderActive();
}
