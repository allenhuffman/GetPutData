// https://github.com/allenhuffman/GetPutData/

/*---------------------------------------------------------------------------*/
// Include Files
/*---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <string.h> // for memset()

#include "GetPutValues.h"

/*---------------------------------------------------------------------------*/
// Prototypes
/*---------------------------------------------------------------------------*/
void HexDump (char *text, uint8_t *ptr, unsigned int size);

/*---------------------------------------------------------------------------*/
// Functions
/*---------------------------------------------------------------------------*/}
int main()
{
    uint8_t buffer[80]; // extra room.
    uint8_t *ptr;
    char msg[20] = "Don't Panic!";
    
    // Test 1 - put data in buffer.
    memset (buffer, 0x0, sizeof(buffer));
    HexDump ("Buffer  ", buffer, sizeof(buffer));

    ptr = &buffer[0];
    putU8 (&ptr, 0x11); // byte 0
    putU16 (&ptr, 0x2222); // bytes 1-2
    putU32 (&ptr, 0x33333333); // bytes 3-6
    putFloat (&ptr, 42.42); // bytes 7-10
    putDouble (&ptr, 42.42); // bytes 11-18
    putData (&ptr, msg, 20); // bytes 19-38
    
    HexDump ("Buffer  ", buffer, sizeof(buffer));
   
    // Test 2 - read data back from buffer.
    uint8_t u8 = 0;
    uint16_t u16 = 0;
    uint32_t u32 = 0;
    float flt = 0.0;
    double dbl = 0.0;
    char stringBuf[20];
    
    ptr = &buffer[0];
    u8 = getU8 (&ptr); // byte 0
    u16 = getU16 (&ptr); // bytes 1-2
    u32 = getU32 (&ptr); // bytes 3-6
    flt = getFloat (&ptr); // bytes 7-10
    dbl = getDouble (&ptr); // bytes 11-18
    getData (&ptr, stringBuf, 20); // bytes 19-38
    
    printf ("u8=0x%02x  u16=0x%04x  u32=0x%08x  flt=%f  dbl=%f  text='%s'\n",
            u8, u16, u32, flt, dbl, stringBuf);
    
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

// End of main2.c
