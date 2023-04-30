# GetPutData
C routines to get/put bytes from/to a buffer in a semi-portable way.

These were meant to be a more-portable way of parsing a message buffer and pulling out the bytes inside of it. The code currently does not deal with big/little endien issues, but that would be easy to add if needed. (Thus, semi-portable.)

* GetPutValuesByOffset - uses an offset value within a file.
* GetPutValues - uses a self-incrementing pointer so offsets are not needed.

I also have some message parsing routines so this does not have to be done manually, a value at a time. See my "StructureToFromBuffer" repository.
