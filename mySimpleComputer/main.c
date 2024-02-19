#include <mySimpleComputer.h>

int registr;

int *ram;

int main()
{
    int sc_memoryInit();
    int sc_regInit();
    int sc_accumulatorInit();
    int sc_icounterInit();
    for (int i = 0; i < 128; i += 4)
    {
        if (sc_memorySet(i, i) != 0)
            return -1;
    }
    int *value = malloc(sizeof(int));
    for (int i = 0; i < 128; i++)
    {
        sc_memoryGet(i, value);
        printDecodedCommand(*value);

    }
    printf("\n");

}