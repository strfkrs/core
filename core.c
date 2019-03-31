#include "core.h"
#include "room.h"
#include "creep.h"
#include "structure.h"
#include "order.h"
#include "orderFactory.h"

static bool_t initialized = FALSE;
void init() { initialized = TRUE; }
bool_t isInitialized() { return initialized; }


void initData() {
   initRooms();
   initCreeps();
   initStructures();
   initOrders();
}
void run()
{
   factoryCreateOrders();
}

void reset()
{
   resetCurrentRoom();
   resetCurrentCreep();
   resetCurrentStructure();
   resetCurrentOrder();
}

long debug( int num )
{
   switch (num)
   {
      case 0: return (long) getCurrentRoom();
      case 1: return (long) getCurrentCreep();
      case 2: return (long) getCurrentStructure();
      case 3: return (long) getCurrentOrder();
      default: return (long) NULL;
   }
}
