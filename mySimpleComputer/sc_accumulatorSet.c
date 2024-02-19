#include <mySimpleComputer.h>


int sc_accumulatorSet(int value)
{
    if (value >= 0x7FFF)
        return -1;
    registr = value;
    return 0;
}
