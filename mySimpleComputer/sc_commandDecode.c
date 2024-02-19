#include <mySimpleComputer.h>

int sc_commandDecode(int value, int *sign, int *command, int *operand)
{
    if (sc_commandValidate(value) == -1)
        return -1;
    *sign = 0;
    *command = value & 0x7f;
    *operand = value >> 8;
    return 0;
}