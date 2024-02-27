#include <mySimpleComputer.h>

void
printCell (int address)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[address], sign, command, operand);
  printf ("sign = %d\ncommand = %d\noperand = %d", *sign, *command, *operand);
}
