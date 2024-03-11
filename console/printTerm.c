#include <mySimpleComputer.h>
#include <myTerm.h>

void
printTerm (int address, int input, int n)
{
  int *sign = malloc (sizeof (int));
  int *comand = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  if (address != 0)
    {
      sc_commandDecode (ram[0], sign, comand, operand);
      mt_gotoXY (25, n * 20);
      printf ("prev: +%d %d", *comand, *operand);
      fflush (stdout);
    }
  if (address != 127)
    {
      mt_gotoXY (27, n * 20);
      sc_commandDecode (ram[address + 1], sign, comand, operand);
      printf ("next: +%d %d", *comand, *operand);
      fflush (stdout);
    }
  if (input)
    {
      mt_gotoXY (26, n * 20);
      sc_commandDecode (ram[address], sign, comand, operand);
      printf ("addr: %d < +%d %d", address, *comand, *operand);
      fflush (stdout);
    }
  else
    {
      mt_gotoXY (26, n * 20);
      fflush (stdout);
      printf ("addr: %d > ", address);
      scanf ("%d", &(ram[address]));
    }
  fflush (stdout);
  free (sign);
  free (comand);
  free (operand);
}