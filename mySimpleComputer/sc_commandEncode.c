#include <mySimpleComputer.h>


int sc_commandEncode(int sign, int command, int operand, int *value)
{
    if (sign != 0 || (command < 10 && command > 76) || value == NULL)
        return -1;
    *value = 0;
    (*value) = command;
    *value = (*value) | operand << 8;
    return 0;
}