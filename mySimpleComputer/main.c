#include <mySimpleComputer.h>

int flag;
int command;
int accumulator;
int *ram;

int
main ()
{
  sc_memoryInit ();
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  for (int i = 0; i < 70; i += 10)
    {
      if (sc_memorySet (i, i) != 0)
        return -1;
    }
  int *value = malloc (sizeof (int));
  for (int i = 0; i < 70; i += 10)
    {
      sc_memoryGet (i, value);
      printDecodedCommand (*value);
    }
  printf ("\n");
  printf ("%d\n", sc_memorySet (127, -1));
  for (int i = 0; i < 5; i++)
    sc_regSet (i, i);
  printFlags ();
  printf ("%d\n", sc_regSet (3, -1));
  sc_accumulatorSet (15);
  printf ("%d\n", sc_accumulatorSet (-1));
  sc_icounterSet (15);
  printf ("%d\n", sc_icounterSet (-1));
  int *sign = malloc (sizeof (int));
  int *comand = malloc (sizeof (int));
  int *operand = malloc (sizeof (int));
  sc_commandDecode (ram[50], sign, comand, operand);
  printf ("%d %d %d\n", *sign, *comand, *operand);
  sc_commandDecode (accumulator, sign, comand, operand);
  printf ("%d %d %d\n", *sign, *comand, *operand);
  sc_commandEncode (0, 14, 30, value);
  printDecodedCommand (*value);
  free (value);
  return 0;
}