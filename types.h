#pragma once

#define DATA_ERROR 9999
#define FALSE 0
#define TRUE 1

static long nullpos = 0;
#define NULL (void*)&nullpos

typedef unsigned char       bool_t;
typedef unsigned int        size_t;

typedef long                orderField_t;
typedef unsigned short      orderData_t;

typedef unsigned char       queueCounter_t;
typedef const unsigned char queueMax_t;

typedef unsigned char       shortID_t;
typedef unsigned short      ID_t;
typedef unsigned char       shortFlags_t;


typedef unsigned short      energy_t;

// creeps
typedef unsigned short      creepData_t;
typedef unsigned short      lootAmount_t;

// structures
typedef unsigned short      structureData_t;
