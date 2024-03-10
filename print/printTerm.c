#include <mySimpleComputer.h>
#include <myTerm.h>

void
printTerm (int address, int input)
{
  int *sign = malloc (sizeof (int));
  int *comand = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  if (address != 0)
    {
      sc_commandDecode (ram[0], sign, comand, operand);
      mt_gotoXY (155, 100);
      printf ("prev: %d %d\n", *comand, *operand);
    }
  if (address != 127)
    {
      mt_gotoXY (156, 100);
      sc_commandDecode (ram[address + 1], sign, comand, operand);
      printf ("next: %d %d\n", *comand, *operand);
    }
  if (input)
    {
      mt_gotoXY (157, 100);
      sc_commandDecode (ram[address], sign, comand, operand);
      printf ("%d %d\n", *comand, *operand);
    }
  else
    {
      mt_gotoXY (157, 100);
      printf ("> ");
      scanf ("%d", &(ram[address]));
    }
}