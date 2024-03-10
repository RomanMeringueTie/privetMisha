#include <myTerm.h>

char *
str_replace_3 (char *orig, char *rep, char *with)
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
mt_setfgcolor (enum colors x)
{
  char *str = malloc (100);
  strcpy (str, "\E[38:5;xm");
  char *xstr = malloc (4);
  sprintf (xstr, "%d", x);
  str = str_replace_3 (str, "x", xstr);
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, str, strlen (str));
  size_t len = strlen (str);
  free (str);
  free (xstr);
  close (fd);
  return (result == len) ? 0 : -1;
}