// https://github.com/allenhuffman/GetPutData/

#include <stdint.h>

// Prototypes
void getData(uint8_t **ptr, void *dataPtr, unsigned int dataSize);
uint8_t getU8(uint8_t **ptr);
uint16_t getU16(uint8_t **ptr);
uint32_t getU32(uint8_t **ptr);
float getFloat(uint8_t **ptr);
double getDouble(uint8_t **ptr);

void putData(uint8_t **ptr, void *dataPtr, unsigned int dataSize);
void putU8(uint8_t **ptr, uint8_t value);
void putU16(uint8_t **ptr, uint16_t value);
void putU32(uint8_t **ptr, uint32_t value);
void putFloat(uint8_t **ptr, float value);
void putDouble(uint8_t **ptr, double value);
