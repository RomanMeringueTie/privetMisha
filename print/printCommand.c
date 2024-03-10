#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCommand (void)
{
  int *sign = malloc (sizeof (int));
  int *comand = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[command], sign, comand, operand);
  mt_gotoXY (145, 100);
  if (sc_commandValidate (ram[command]) == -1)
    printf ("!");
  else
    printf ("%d %d\n", *comand, *operand);
  free (sign);
  free (comand);
  free (operand);
}