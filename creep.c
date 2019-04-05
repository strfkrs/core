#include "creep.h"

static queueMax_t      MAX_CREEPS = 100;
static Creep           creeps[MAX_CREEPS];
static Creep*          currentCreep;

const queueCounter_t getCreepIndex(Creep* creep)
{
   return (((size_t)creep)/sizeof(Creep))-(((size_t)creeps)/sizeof(Creep));
}
void initCreeps()
{
   for( currentCreep = creeps; currentCreep < &creeps[MAX_CREEPS]; currentCreep++ )
   {
      currentCreep->active = FALSE;
   }
   currentCreep = creeps;
}
void resetCurrentCreep()
{
   currentCreep = creeps;
}
Creep* getCurrentCreep()
{
   return currentCreep;
}




bool_t isCreepQueueEnd(Creep* creep) { return creep >= &creeps[MAX_CREEPS]; }
bool_t isCreepActive(Creep* creep) { return ! isCreepQueueEnd(creep) && creep->active; }
bool_t isCurrentCreepQueueEnd() { return isCreepQueueEnd(currentCreep); }
bool_t isCurrentCreepActive() { return isCreepActive(currentCreep); }

bool_t selectNextCreep()
{
   if ( isCurrentCreepQueueEnd() )
      return FALSE;

   currentCreep++;
   return TRUE;
}


bool_t addCreep( shortFlags_t flags )
{
   if ( isCurrentCreepQueueEnd() )
      return FALSE;
   currentCreep->flags =  flags;
   currentCreep->active = TRUE;
   return TRUE;
}
/*
 *
 * CREEP DATA
 *
 */
bool_t setCreepData( CREEP_MEMBER member, creepData_t data )
{
   if ( isCurrentCreepQueueEnd() )
      return FALSE;
   switch (member)
   {
      case CREEP_MEMBER_FLAGS:        currentCreep->flags |= (shortFlags_t) data; break;
      case CREEP_MEMBER_ROLE:         currentCreep->role = (CREEP_ROLE) data; break;
      case CREEP_MEMBER_ACTION:       currentCreep->action = (CREEP_ACTION) data; break;
      case CREEP_MEMBER_LOOT_TYPE:    currentCreep->lootType = (CREEP_LOOT_TYPE) data; break;
      case CREEP_MEMBER_LOOT_AMOUNT:  currentCreep->lootAmount = (lootAmount_t) data; break;
      default: return FALSE;
   }
   return TRUE;
}

creepData_t getCurrentCreepMember( CREEP_MEMBER member )
{
   if ( isCurrentCreepQueueEnd() )
      return FALSE;
   switch (member)
   {
      case CREEP_MEMBER_ID:           return (creepData_t)getCreepIndex(currentCreep);
      case CREEP_MEMBER_FLAGS:        return (creepData_t)currentCreep->flags;
      case CREEP_MEMBER_ROLE:         return (creepData_t)currentCreep->role;
      case CREEP_MEMBER_ACTION:       return (creepData_t)currentCreep->action;
      case CREEP_MEMBER_LOOT_TYPE:    return (creepData_t)currentCreep->lootType;
      case CREEP_MEMBER_LOOT_AMOUNT:  return (creepData_t)currentCreep->lootAmount;
      default: return DATA_ERROR;
   }
}
