#pragma once
#include "core.h"

typedef enum ORDER_TYPE
{
   ORDER_TYPE_NONE,
   ORDER_TYPE_SPAWN_WORKER,
   ORDER_TYPE_ASSIGN_ACTION

} ORDER_TYPE;

typedef struct Order
{
   ORDER_TYPE       type;
   Entity*          source;
   Entity*          target;
   orderData_t      data;
   shortFlags_t     dataFlags;
   bool_t           isRecieved;

} Order;

static const shortFlags_t ORDER_FLAG_ID =       0b000000;
static const shortFlags_t ORDER_FLAG_FLAGS  =   0b000001;
static const shortFlags_t ORDER_FLAG_TYPE =     0b000010;
static const shortFlags_t ORDER_FLAG_SOURCE =   0b000100;
static const shortFlags_t ORDER_FLAG_TARGET =   0b001000;
static const shortFlags_t ORDER_FLAG_DATA =     0b010000;
static const shortFlags_t ORDER_FLAG_RECIEVED = 0b100000;


extern void initOrders();
extern void resetCurrentOrder();
extern const Order* getCurrentOrder();
extern bool_t selectNextOrder();
extern bool_t isCurrentOrderActive();
extern bool_t addOrder( const ORDER_TYPE  type,
                        const Entity*     source,
                        const Entity*     target,
                        const orderData_t data );
extern const queueCounter_t getOrderIndex(Order* order);
