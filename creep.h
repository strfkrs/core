#pragma once
#include "core.h"
#include "room.h"
//
// CONSTANTS
//
static const shortFlags_t CREEP_FLAG_OWN =     0b00000001;
static const shortFlags_t CREEP_FLAG_HOSTILE = 0b00000010;

typedef enum CREEP_ROLE
{
   CREEP_ROLE_WORKER

} CREEP_ROLE;

typedef enum CREEP_ACTION
{
   CREEP_ACTION_NONE,
   CREEP_ACTION_IDLE,
   CREEP_ACTION_WORKER

} CREEP_ACTION;

typedef enum CREEP_LOOT_TYPE
{
   CREEP_LOOT_TYPE_NONE,
   CREEP_LOOT_TYPE_ENERGY,
   CREEP_LOOT_TYPE_OTHER

} CREEP_LOOT_TYPE;


typedef enum CREEP_MEMBER
{
   CREEP_MEMBER_ID,
   CREEP_MEMBER_FLAGS,
   CREEP_MEMBER_ROLE,
   CREEP_MEMBER_ACTION,
   CREEP_MEMBER_LOOT_TYPE,
   CREEP_MEMBER_LOOT_AMOUNT

} CREEP_MEMBER;
//
// STRUCTS
//
typedef struct Room Room;

typedef struct Creep
{
   bool_t          active;
   shortFlags_t    flags;
   Room*           room;
   CREEP_ROLE      role;
   CREEP_ACTION    action;
   CREEP_LOOT_TYPE lootType;
   lootAmount_t    lootAmount;

} Creep;

//
// public funcs
//
extern void     initCreeps();
extern void     resetCurrentCreep();
extern Creep*   getCurrentCreep();
extern bool_t   selectNextCreep();
extern bool_t   isCreepActive(Creep*);
extern bool_t   isCreepQueueEnd(Creep*);
extern bool_t   isCurrentCreepQueueEnd();
extern bool_t   isCurrentCreepActive();
extern const queueCounter_t getCreepIndex(Creep* creep);
