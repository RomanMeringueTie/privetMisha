#include <mySimpleComputer.h>

void printAccumulator(void)
{
    printf("%d\n", registr & 0x1fffc000);
}