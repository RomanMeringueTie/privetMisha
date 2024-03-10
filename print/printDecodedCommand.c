#include <mySimpleComputer.h>
#include <myTerm.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (20, 150);
  printf ("10: %d 8: %o 16: %x 2: %b\n", value, value, value, value);
}