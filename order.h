#pragma once
#include "core.h"

static const queueMax_t MAX_ORDER_DATA = 3;

typedef enum ORDER_TYPE
{
   ORDER_TYPE_SPAWN,
   ORDER_TYPE_ASSIGN_ACTION

} ORDER_TYPE;

typedef struct Order
{
   bool_t            active;
   ORDER_TYPE        type;
   queueCounter_t    source;
   queueCounter_t    target;
   orderData_t       data[MAX_ORDER_DATA];
   shortFlags_t      dataFlags;
   bool_t            isRecieved;

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
extern bool_t addOrder( const ORDER_TYPE     type,
                        const queueCounter_t source,
                        const queueCounter_t target );
extern bool_t setOrderData( const queueCounter_t index,
                            const orderData_t data);
extern const queueCounter_t getOrderIndex(Order* order);
