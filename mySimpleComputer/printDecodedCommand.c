#include <mySimpleComputer.h>

void printDecodedCommand(int value)
{
    printf("10: %d\n8: %o\n16: %x\n2: ", value, value, value);
    for (int i = 1 << 31; i > 0; i = i / 2)
        (value & i) ? printf("1") : printf("0");
    printf("\n");
}