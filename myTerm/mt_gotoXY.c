#include <myTerm.h>

char *
str_replace_1 (char *orig, char *rep, char *with)
{
  char *result;  // the return string
  char *ins;     // the next insert point
  char *tmp;     // varies
  int len_rep;   // length of rep (the string to remove)
  int len_with;  // length of with (the string to replace rep with)
  int len_front; // distance between rep and end of last rep
  int count;     // number of replacements
  if (!orig || !rep)
    return NULL;
  len_rep = strlen (rep);
  if (len_rep == 0)
    return NULL; // empty rep causes infinite loop during count
  if (!with)
    with = "";
  len_with = strlen (with);
  ins = orig;
  for (count = 0; tmp = strstr (ins, rep); ++count)
    {
      ins = tmp + len_rep;
    }
  tmp = result = malloc (strlen (orig) + (len_with - len_rep) * count + 1);
  if (!result)
    return NULL;
  while (count--)
    {
      ins = strstr (orig, rep);
      len_front = ins - orig;
      tmp = strncpy (tmp, orig, len_front) + len_front;
      tmp = strcpy (tmp, with) + len_with;
      orig += len_front + len_rep; // move to next "end of rep"
    }
  strcpy (tmp, orig);
  return result;
}

int
find_char (char *str, char sym)
{
  for (int i = 0; i < strlen (str); i++)
    {
      if (str[i] == sym)
        return i;
    }
  return -1;
}

int
mt_gotoXY (int x, int y)
{
  char *str = malloc (20);
  char *xstr = malloc (5);
  char *ystr = malloc (5);
  strcpy (str, "\E[x;yH");
  sprintf (xstr, "%d", x);
  sprintf (ystr, "%d", y);
  str = str_replace_1 (str, "x", xstr);
  str = str_replace_1 (str, "y", ystr);
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, str, strlen (str));
  size_t len = strlen (str);
  close (fd);
  free (str);
  free (xstr);
  free (ystr);
  fflush (stdout);
  return (result == len) ? 0 : -1;
}
