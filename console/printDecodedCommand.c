#include <mySimpleComputer.h>
#include <myTerm.h>

void
printDecodedCommand (int value)
{
  mt_gotoXY (21, 1);
  printf ("dec: %d oct: %o hex: %x bin: %b", value, value, value, value);
  fflush (stdout);
}