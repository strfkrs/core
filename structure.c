#include "structure.h"

static queueMax_t          MAX_STRUCTURES = 100;
static Structure           structures[MAX_STRUCTURES];
static Structure*          currentStructure;

const queueCounter_t getStructureIndex(Structure* structure)
{
   return (((size_t)structure)/sizeof(Structure))-(((size_t)structures)/sizeof(Structure));
}

void initStructures()
{
   for( currentStructure = structures; currentStructure < &structures[MAX_STRUCTURES]; currentStructure++ )
   {
      currentStructure->flags = 0;
      currentStructure->type = 0;
      currentStructure->energy = 0;
      currentStructure->maxEnergy = 0;
   }
   currentStructure = structures;
}
void        resetCurrentStructure()                 { currentStructure = structures; }
Structure*  getCurrentStructure()                   { return currentStructure; }

bool_t isStructureQueueEnd(Structure* structure)    { return    structure >= &structures[MAX_STRUCTURES]; }
bool_t isStructureActive(Structure* structure)      { return  ! isStructureQueueEnd(structure) && structure->flags; }
bool_t isCurrentStructureQueueEnd()                 { return    isStructureQueueEnd(currentStructure); }
bool_t isCurrentStructureActive()                   { return    isStructureActive(currentStructure); }

bool_t selectNextStructure()
{
   if ( isCurrentStructureQueueEnd() )
      return FALSE;

   currentStructure++;
   return TRUE;
}

bool_t addStructure( STRUCTURE_TYPE type,
                     shortFlags_t flags )
{
   if ( isCurrentStructureQueueEnd() )
      return FALSE;

   currentStructure->flags = flags;
   currentStructure->type = type;
   return TRUE;
}
/*
 *
 * STRUCTURE DATA
 *
 */
bool_t setStructureData( STRUCTURE_DATA_TYPE type, structureData_t data )
{
   if ( isCurrentStructureQueueEnd() )
      return FALSE;
   switch( type )
   {
      case STRUCTURE_DATA_FLAGS:            currentStructure->flags |= (shortFlags_t) data; break;
      case STRUCTURE_DATA_STRUCTURE_TYPE:   currentStructure->type = (STRUCTURE_TYPE) data; break;
      case STRUCTURE_DATA_ENERGY:           currentStructure->energy = (energy_t) data; break;
      case STRUCTURE_DATA_MAX_ENERGY:       currentStructure->maxEnergy = (energy_t) data; break;
      default: return FALSE;
   }
    return TRUE;
}

structureData_t getStructureData( STRUCTURE_DATA_TYPE type )
{
   if ( isCurrentStructureQueueEnd() )
      return FALSE;
   switch (type)
   {
      case STRUCTURE_DATA_ID:               return getStructureIndex(currentStructure);
      case STRUCTURE_DATA_FLAGS:            return currentStructure->flags;
      case STRUCTURE_DATA_STRUCTURE_TYPE:   return currentStructure->type;
      case STRUCTURE_DATA_ENERGY:           return currentStructure->energy;
      case STRUCTURE_DATA_MAX_ENERGY:       return currentStructure->maxEnergy;
      default: return DATA_ERROR;
   }
}