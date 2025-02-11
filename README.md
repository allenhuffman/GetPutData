# GetPutData
C routines to get/put bytes from/to a buffer in a semi-portable way.

These were meant to be a more-portable way of parsing a message buffer and pulling out the bytes inside of it. The code currently does not deal with big/little endien issues, but that would be easy to add if needed. (Thus, semi-portable.)

* GetPutValuesByOffset - uses an offset value within a file.
* GetPutValues - uses a self-incrementing pointer so offsets are not needed.

I also have some message parsing routines so this does not have to be done manually, a value at a time. See my "StructureToFromBuffer" repository.

## GetPutValuesByOffset
These routines allow getting or putting a value at any offset within a buffer. They are useful if you don't always need to read all the values.

Assuming a buffer of data, such as this:
```
uint8_t data[] =
{
    0x11,
    0x22, 0x22,
    0x33, 0x33, 0x33, 0x33,
};
```
You could read the 8-bit value at offset 0, the 16-bit value at offset 1, and the 32-bite value at offset 3, like this:
```
uint8_t u8 = getU8From (buffer, 0);
uint16_t u16 = getU16From (buffer, 1);
uint32_t u32 = getU32From (buffer, 3);
```
This method allows any data to be retrieved in any order, such as only getting a value at a later offset.

Example: https://onlinegdb.com/YdCfV7MTm

## GetPutValues (by pointer)
These routines are simpler to use if pulling our sequential values from the start of the buffer. The functions take the address of a pointer to the buffer, and will modify it (increment it) after any get or put by the number of bytes that were gotten or putten.

Using the same example data above, the process is simpler (but more dangerous, since it is dealing with pointers):
```
uint8_t *ptr = &buffer[0]; // ptr points to start of data.
uint8_t u8 = getU8 (&ptr);
uint16_t u16 = getU16 (&ptr);
uint32_t u32 = getU32 (&ptr);
```
You **can not** pass in just the address of the data, since these functions will modify (increment) the pointer that is passed in by reference (the address of the pointer).

This method makes parsing data simpler since all you have to do is set a pointer to the start of the buffer and then make "get" calls pulling out data in the order it appears.

Example: https://onlinegdb.com/IDhMiu9kd
