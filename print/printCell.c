#include <mySimpleComputer.h>
#include <myTerm.h>

void
printCell (int address, enum colors fg, enum colors bg)
{
  int *sign = malloc (sizeof (int));
  int *command = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[address], sign, command, operand);
  mt_setfgcolor (fg);
  mt_setbgcolor (bg);
  mt_gotoXY ((address % 10) * 3, 10 * (address / 12));
  printf ("|%d %d|\n", *command, *operand);
}
