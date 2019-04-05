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
   bool_t            isRecieved;
   orderData_t       data[MAX_ORDER_DATA];

} Order;

static const shortFlags_t ORDER_FLAG_ID =       0b00000;
static const shortFlags_t ORDER_FLAG_TYPE =     0b00001;
static const shortFlags_t ORDER_FLAG_SOURCE =   0b00010;
static const shortFlags_t ORDER_FLAG_TARGET =   0b00100;
static const shortFlags_t ORDER_FLAG_RECIEVED = 0b01000;


extern void initOrders();
extern void resetCurrentOrder();
extern const Order* getCurrentOrder();
extern bool_t selectNextOrder();
extern bool_t isCurrentOrderActive();
extern bool_t setOrder( const ORDER_TYPE     type,
                        const queueCounter_t source,
                        const queueCounter_t target );
extern bool_t setCurrentOrderData( const queueCounter_t index,
                                   const orderData_t data);
extern const queueCounter_t getOrderIndex(Order* order);
