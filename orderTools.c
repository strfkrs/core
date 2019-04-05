#include "orderTools.h"

queueCounter_t countStructures(
      const Structure*     first,
      const STRUCTURE_TYPE type,
      const Room*          room,
      const shortFlags_t   filter )
{
   Structure*       _structure = (Structure*)first;
   queueCounter_t   amount = 0;

   while(   isStructureActive(_structure)
         && ( (filter & ORDER_FILTER_STRUCTURE_TYPE) && _structure->type == type )
         && ( (filter & ORDER_FILTER_STRUCTURE_ROOM) && _structure->room == room ) )
   {
      amount++;

      if ( ! isStructureQueueEnd(++_structure) ) break;
   }

   return amount;
}

queueCounter_t countCreeps(
      const Creep*         creep,
      const CREEP_ROLE     role,
      const Room*          room,
      const shortFlags_t   filter )
{
   Creep*           _creep = (Creep*)creep;
   queueCounter_t   amount = 0;

   while(    isCreepActive(_creep)
          && ( (filter & ORDER_FILTER_CREEP_ROLE) && _creep->role == role )
          && ( (filter & ORDER_FILTER_CREEP_ROOM) && _creep->room == room ) )
   {
      amount++;

      if ( ! isCreepQueueEnd(++_creep) ) break;
   }

   return amount;
}
