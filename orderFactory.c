#include "orderFactory.h"
#include "orderTools.h"
#include "order.h"
#include "room.h"
#include "creep.h"
#include "structure.h"
#include "orders/spawn.h"

void factoryResetSources()
{
   resetCurrentRoom();
   resetCurrentCreep();
   resetCurrentStructure();
}

bool_t factoryCreateOrders()
{
   do
   {
      factoryResetSources();
      if( addSpawnOrder() ) break;

      break;
   } while( selectNextOrder() );

   return isCurrentOrderActive();
}
