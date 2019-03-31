#include "orderTools.h"

queueCounter_t countStructures(
      const Structure*      first,
      const STRUCTURE_TYPE  type,
      const Room*           room )
{
   Structure*       _structure = (Structure*)first;
   queueCounter_t   amount = 0;

   while(   isStructureActive(_structure)
         && ( type == STRUCTURE_TYPE_ALL  || _structure->type == type )
         && ( room == NULL                || _structure->room == room) )
   {
      amount++;

      if ( ! isStructureQueueEnd(++_structure) ) break;
   }

   return amount;
}

queueCounter_t countCreeps(
      const Creep*      creep,
      const CREEP_ROLE  role,
      const Room*       room )
{
   Creep*           _creep = (Creep*)creep;
   queueCounter_t   amount = 0;

   while(   isCreepActive(_creep) &&
          ( role == CREEP_ROLE_NONE || _creep->role == role ) )
   {
      amount++;

      if ( ! isCreepQueueEnd(++_creep) ) break;
   }

   return amount;
}
