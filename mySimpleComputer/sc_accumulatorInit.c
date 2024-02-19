#include <mySimpleComputer.h>


int sc_accumulatorInit(void)
{
    registr = registr & 0x0001ffff;
    return 0;
}