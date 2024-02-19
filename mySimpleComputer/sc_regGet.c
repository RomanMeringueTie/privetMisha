#include <mySimpleComputer.h>

#define FLAG_GET(k) ((flag >> (k - 1)) & 0x1)

int sc_regGet(int registr, int *value)
{
    // if (registr < 0 || registr > 32 || value == NULL)
    //     return -1;
    // *value = (registr >> (registr - 1)) & 0x1;
    return 0;
}