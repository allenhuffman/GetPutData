/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h> // for memset()

#include "getPutValuesByOffset.h"

// Prototypes
void HexDump (char *text, uint8_t *ptr, unsigned int size);

// Functions
int main()
{
    uint8_t     u8;
    uint16_t    u16;
    uint32_t    u32;
    float       flt;
    double      dbl;

    // Test 1 - get values from data bytes.
    uint8_t data[] =
    {
        0x42,                                           // 0: uint8_t
        0x34, 0x12,                                    // 1-2: uin16_t
        0x44, 0x33, 0x22, 0x11,                         // 3-6: uint32_t
        0x14, 0xae, 0x29, 0x42,                         // 7-10: float 42.42    
        0xf6, 0x28, 0x5c, 0x8f, 0xc2, 0x35, 0x45, 0x40  // 11-16: double 42.42
    };
    
    HexDump ("data  ", data, sizeof(data));

    u8 = getValueFrom (data, 0, 1).U8;
    u16 = getValueFrom (data, 1, 2).U16;
    u32 = getValueFrom (data, 3, 4).U32;
    flt = getValueFrom (data, 7, 4).FLT;
    dbl = getValueFrom (data, 11, 8).DBL;
    
    printf ("u8=0x%02x  u16=0x%04x  u32=0x%08x  flt=%f  dbl=%f\n",
            u8, u16, u32, flt, dbl);

    // Test 2 - put values in buffer.
    uint8_t     buffer[17];
    ValueUnion  value;
    
    memset (buffer, 0x0, sizeof(buffer));

    value.U8 = u8;
    putValueTo (buffer, 0, 1, value);
    value.U16 = u16;
    putValueTo (buffer, 1, 2, value);
    value.U32 = u32;
    putValueTo (buffer, 3, 4, value);
    value.FLT = flt;
    putValueTo (buffer, 7, 4, value);
    value.DBL = dbl;
    putValueTo (buffer, 11, 8, value);

    HexDump ("buffer", buffer, 19);
    
    // Test 3 - get values from data bytes using helper functions.
    u8 = getU8From (data, 0);
    u16 = getU16From (data, 1);
    u32 = getU32From (data, 3);
    flt = getFloatFrom (data, 7);
    dbl = getDoubleFrom (data, 11);
    
    printf ("u8=0x%02x  u16=0x%04x  u32=0x%08x  flt=%f  dbl=%f\n",
            u8, u16, u32, flt, dbl);

    // Test 4 - put values to buffer using helper functions.
    memset (buffer, 0x0, sizeof(buffer));

    putU8To (buffer, 0, u8);
    putU16To (buffer, 1, u16);
    putU32To (buffer, 3, u32);
    putFloatTo (buffer, 7, flt);
    putDoubleTo (buffer, 11, dbl);

    HexDump ("buffer", buffer, 19);    
    
    return 0;
}

// Utility Functions
void HexDump (char *text, uint8_t *ptr, unsigned int size)
{
    printf ("%s: ", text);
    for (int idx=0; idx<size; idx++)
    {
        printf ("%02x ", ((uint8_t*)ptr)[idx]);
    }
    printf ("\n");
}

