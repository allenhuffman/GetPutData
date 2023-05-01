// https://github.com/allenhuffman/GetPutData/

/*---------------------------------------------------------------------------*/
// Include Files
/*---------------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h> // for memset(), memcpy()

#include "GetPutValues.h"

/*---------------------------------------------------------------------------*/
// Functions
/*---------------------------------------------------------------------------*/
void getData (uint8_t **ptr, void *dataPtr, unsigned int dataSize)
{
    memcpy(dataPtr, *ptr, dataSize);
    *ptr += dataSize;
}

uint8_t getU8 (uint8_t **ptr)
{
    uint8_t value;
    memcpy (&value, *ptr, sizeof(value));
    *ptr += sizeof(value);
    return value;
}

uint16_t getU16 (uint8_t **ptr)
{
    uint16_t value;
    memcpy (&value, *ptr, sizeof(value));
    *ptr += sizeof(value);
    return value;
}

uint32_t getU32 (uint8_t **ptr)
{
    uint32_t value;
    memcpy (&value, *ptr, sizeof(value));
    *ptr += sizeof(value);
    return value;
}

float getFloat (uint8_t **ptr)
{
    float value;
    memcpy (&value, *ptr, sizeof(value));
    *ptr += sizeof(value);
    return value;
}

double getDouble (uint8_t **ptr)
{
    double value;
    memcpy (&value, *ptr, sizeof(value));
    *ptr += sizeof(value);
    return value;
}

void putData (uint8_t **ptr, void *dataPtr, unsigned int dataSize)
{
    memcpy(*ptr, dataPtr, dataSize);
    *ptr += dataSize;
}

void putU8 (uint8_t **ptr, uint8_t value)
{
    memcpy (*ptr, &value, sizeof(value));
    *ptr += sizeof (value);
}

void putU16 (uint8_t **ptr, uint16_t value)
{
    memcpy (*ptr, &value, sizeof(value));
    *ptr += sizeof (value);
}

void putU32 (uint8_t **ptr, uint32_t value)
{
    memcpy (*ptr, &value, sizeof(value));
    *ptr += sizeof (value);
}

void putFloat (uint8_t **ptr, float value)
{
    memcpy (*ptr, &value, sizeof(value));
    *ptr += sizeof (value);
}

void putDouble (uint8_t **ptr, double value)
{
    memcpy (*ptr, &value, sizeof(value));
    *ptr += sizeof (value);
}

// End of GetPutValues.c
