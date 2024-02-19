#include <mySimpleComputer.h>


int sc_memorySet(int address, int value)
{
    if ((address >= 0 && address <= 127) || (value >= INT_MIN && value <= INT_MAX))
        return -1;
    else
    {
        ram[address] = value;
        return 0;
    }
}
