#include "order.h"

static queueMax_t    MAX_ORDERS = 20;
static Order         orders[MAX_ORDERS];
static Order*        currentOrder;

const queueCounter_t getOrderIndex(Order* order)
{
   return (((queueCounter_t)order)/sizeof(Order))-(((queueCounter_t)orders)/sizeof(Order));
}
void initOrders()
{
   for( currentOrder = orders; currentOrder < &orders[MAX_ORDERS]; currentOrder++ )
   {
      currentOrder->active = FALSE;
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

bool_t setOrder(  const ORDER_TYPE        type,
                  const queueCounter_t    source,
                  const queueCounter_t    target )
{
   if ( isOrderQueueEnd() )
      return FALSE;

   currentOrder->type =          type;
   currentOrder->source =        source;
   currentOrder->target =        target;
   currentOrder->active =        TRUE;
   currentOrder->isRecieved =    FALSE;

   return TRUE;
}

bool_t setCurrentOrderData( const queueCounter_t index, const orderData_t data)
{
   if ( isOrderQueueEnd() || index >= MAX_ORDER_DATA )
      return FALSE;

   currentOrder->data[index] = data;

   return TRUE;
}

bool_t selectNextOrder()
{
   if ( isOrderQueueEnd() )
      return FALSE;

   currentOrder++;

   return TRUE;
}

bool_t isCurrentOrderActive()    { return ( ! isOrderQueueEnd() && currentOrder->active ); }
bool_t setCurrentOrderRecieved() { return ( ! isOrderQueueEnd() && (currentOrder->isRecieved = TRUE) ); }
bool_t isCurrentOrderRecieved()  { return ( ! isCurrentOrderActive() || currentOrder->isRecieved ); }

orderData_t getCurrentOrderData( queueCounter_t index )
{
  if( index >= MAX_ORDER_DATA )
     return 0;
  return currentOrder->data[index];
}

orderField_t getCurrentOrderMember( shortFlags_t member )
{
   switch(member)
   {
      case ORDER_FLAG_ID:        return (orderField_t)getOrderIndex(currentOrder);
      case ORDER_FLAG_TYPE:      return (orderField_t)currentOrder->type;
      case ORDER_FLAG_SOURCE:    return (orderField_t)currentOrder->source;
      case ORDER_FLAG_TARGET:    return (orderField_t)currentOrder->target;
      case ORDER_FLAG_RECIEVED:  return (orderField_t)currentOrder->isRecieved;
      default: return DATA_ERROR;
   }
}
