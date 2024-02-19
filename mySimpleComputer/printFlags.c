#include <mySimpleComputer.h>

void printFlags(void)
{
    if (registr & 0x3FF & 0x200)
        printf("П\n");
    if (registr & 0x1FF & 0x100)
        printf("0\n");
    if (registr & 0xFF & 0x80)
        printf("М\n");
    if (registr & 0x7F & 0x40)
        printf("Т\n");
    if (registr & 0x3F & 0x20)
        printf("Е\n");
}