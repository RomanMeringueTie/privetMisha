#include <mySimpleComputer.h>

int
sc_commandValidate (int command)
{
  if (command < 0x80000000 && (command & 0x7f) <= 76
      && (command >> 8) <= 0xffffff)
    return 0;
  return -1;
}
