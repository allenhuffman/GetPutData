// https://github.com/allenhuffman/GetPutData/

#include <stdint.h>
#include <string.h> // for memset(), memcpy()

#include "GetPutValuesByOffset.h"

ValueUnion getValueFrom(uint8_t *bufferPtr, unsigned int offset, unsigned int size)
{
    ValueUnion result;
    memcpy(&result, bufferPtr + offset, size);
    return result;
}

void putValueTo(uint8_t *bufferPtr, unsigned int offset, unsigned int size, ValueUnion value)
{
    memcpy(bufferPtr + offset, &value, size);
}

// getValue helper functions
uint8_t getU8From (uint8_t *bufferPtr, unsigned int offset)
{
    return getValueFrom(bufferPtr, offset, sizeof(uint8_t)).U8;
}

uint16_t getU16From (uint8_t *bufferPtr, unsigned int offset)
{
    return getValueFrom(bufferPtr, offset, sizeof(uint16_t)).U16;
}

uint32_t getU32From (uint8_t *bufferPtr, unsigned int offset)
{
    return getValueFrom(bufferPtr, offset, sizeof(uint32_t)).U32;
}

float getFloatFrom (uint8_t *bufferPtr, unsigned int offset)
{
    return getValueFrom(bufferPtr, offset, sizeof(float)).FLT;
}

float getDoubleFrom (uint8_t *bufferPtr, unsigned int offset)
{
    return getValueFrom(bufferPtr, offset, sizeof(double)).DBL;
}

// putValue helper functions
void putU8To (uint8_t *bufferPtr, unsigned int offset, uint8_t value)
{
    memcpy (bufferPtr + offset, &value, sizeof(value));
}

void putU16To (uint8_t *bufferPtr, unsigned int offset, uint16_t value)
{
    memcpy (bufferPtr + offset, &value, sizeof(value));
}

void putU32To (uint8_t *bufferPtr, unsigned int offset, uint32_t value)
{
    memcpy (bufferPtr + offset, &value, sizeof(value));
}

void putFloatTo (uint8_t *bufferPtr, unsigned int offset, float value)
{
    memcpy (bufferPtr + offset, &value, sizeof(value));
}

void putDoubleTo (uint8_t *bufferPtr, unsigned int offset, double value)
{
    memcpy (bufferPtr + offset, &value, sizeof(value));
}
