// https://github.com/allenhuffman/GetPutData/

/*---------------------------------------------------------------------------*/
// Include Files
/*---------------------------------------------------------------------------*/
#include <stdint.h>


/*---------------------------------------------------------------------------*/
// Typedefs
/*---------------------------------------------------------------------------*/
typedef union value_t {
    uint8_t     U8;
    int8_t      S8;
    uint16_t    U16;
    int16_t     S16;
    uint32_t    U32;
    int32_t     S32;
    float       FLT;
    double      DBL;
} ValueUnion;


/*---------------------------------------------------------------------------*/
// Prototypes
/*---------------------------------------------------------------------------*/
ValueUnion getValueFrom(uint8_t *bufferPtr, unsigned int offset, unsigned int size);
void putValueTo(uint8_t *bufferPtr, unsigned int offset, unsigned int size, ValueUnion value);

uint8_t getU8From (uint8_t *bufferPtr, unsigned int offset);
uint16_t getU16From (uint8_t *bufferPtr, unsigned int offset);
uint32_t getU32From (uint8_t *bufferPtr, unsigned int offset);
float getFloatFrom (uint8_t *bufferPtr, unsigned int offset);
float getDoubleFrom (uint8_t *bufferPtr, unsigned int offset);

void putU8To (uint8_t *bufferPtr, unsigned int offset, uint8_t value);
void putU16To (uint8_t *bufferPtr, unsigned int offset, uint16_t value);
void putU32To (uint8_t *bufferPtr, unsigned int offset, uint32_t value);
void putFloatTo (uint8_t *bufferPtr, unsigned int offset, float value);
void putDoubleTo (uint8_t *bufferPtr, unsigned int offset, double value);

// End of GetPutValuesByOffset.h
