#include <mySimpleComputer.h>
#include <myTerm.h>

void
printAccumulator (void)
{
  mt_gotoXY (2, 150);
  printf ("%d\n", accumulator);
}