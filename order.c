#include "order.h"

static queueMax_t MAX_ORDERS = 20;
static Order      orders[MAX_ORDERS];
static Order*     currentOrder;

const queueCounter_t getOrderIndex(Order* order)
{
   return (((queueCounter_t)order)/sizeof(Order))-(((queueCounter_t)orders)/sizeof(Order));
}
void initOrders()
{
   for( currentOrder = orders; currentOrder < &orders[MAX_ORDERS]; currentOrder++ )
   {
      currentOrder->source = (Entity*)NULL;
      currentOrder->target = (Entity*)NULL;
   }
   currentOrder = orders;
}
void resetCurrentOrder()
{
   currentOrder = orders;
}
const Order* getCurrentOrder()
{
   return currentOrder;
}
bool_t isOrderQueueEnd()
{
   return currentOrder >= &orders[MAX_ORDERS];
}

bool_t addOrder(  const ORDER_TYPE  type,
                  const Entity*     source,
                  const Entity*     target,
                  const orderData_t data )
{
   if ( isOrderQueueEnd() )
      return FALSE;

   currentOrder->type =          type;
   currentOrder->source =        (Entity*) source;
   currentOrder->target =        (Entity*) target;
   currentOrder->data =          data;
   currentOrder->dataFlags =     0;

   currentOrder->isRecieved =    FALSE;

   if ( source != NULL )
      currentOrder->dataFlags |= ORDER_FLAG_SOURCE;

   if ( target != NULL )
      currentOrder->dataFlags |= ORDER_FLAG_TARGET;

   if ( data )
      currentOrder->dataFlags |= ORDER_FLAG_DATA;

   return TRUE;
}
bool_t selectNextOrder()
{
   if ( isOrderQueueEnd() )
      return FALSE;

   currentOrder++;

   return TRUE;
}
bool_t isCurrentOrderActive()    { return ( ! isOrderQueueEnd() && ( currentOrder->source != NULL || currentOrder->target != NULL ) ); }
bool_t setCurrentOrderRecieved() { return ( ! isOrderQueueEnd() && (currentOrder->isRecieved = TRUE) ); }
bool_t isCurrentOrderRecieved()  { return ( isOrderQueueEnd() || currentOrder->isRecieved ); }

orderField_t getOrderDataFlags() { return currentOrder->dataFlags; }
orderField_t getOrderData( shortFlags_t field )
{
   switch(field)
   {
      case ORDER_FLAG_ID:        return (orderField_t)getOrderIndex(currentOrder);
      case ORDER_FLAG_FLAGS:     return (orderField_t)currentOrder->dataFlags;
      case ORDER_FLAG_TYPE:      return (orderField_t)currentOrder->type;
      case ORDER_FLAG_SOURCE:    return (orderField_t)currentOrder->source;
      case ORDER_FLAG_TARGET:    return (orderField_t)currentOrder->target;
      case ORDER_FLAG_DATA:      return (orderField_t)currentOrder->data;
      case ORDER_FLAG_RECIEVED:  return (orderField_t)currentOrder->isRecieved;
      default: return DATA_ERROR;
   }
}
