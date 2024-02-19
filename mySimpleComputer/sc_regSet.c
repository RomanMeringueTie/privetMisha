#include <mySimpleComputer.h>

#define FLAG_SET(k) (flag | (1 << (k - 1)))
#define FLAG_CLEAR(k) (flag & (~(1 << (k - 1))))

int sc_regSet(int registr, int value)
{
    // if (registr < 0 || registr > 32)
    //     return -1;
    // if (value)
    //     flag = FLAG_SET(registr);
    // else
    //     flag = FLAG_CLEAR(registr);
    return 0;
}