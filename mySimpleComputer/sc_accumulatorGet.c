#include <mySimpleComputer.h>


int sc_accumulatorGet(int *value)
{
    if (value == NULL)
        return -1;
    *value = registr & 0xFFFE;
    printf("%x\n", *value);
    return 0;
}
