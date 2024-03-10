#pragma once
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum colors
{
    fg_black = 30,
    fg_red,
    fg_green,
    fg_yellow,
    fg_blue,
    fg_magneta,
    fg_cyan,
    fg_white,
    bg_black = 40,
    bg_red,
    bg_green,
    bg_yellow,
    bg_blue,
    bg_magneta,
    bg_cyan,
    bg_white
};

int mt_clrscr (void);
int mt_gotoXY (int, int);
int mt_getscreensize (int * rows, int * cols);
int mt_setfgcolor (enum colors);
int mt_setbgcolor (enum colors);
int mt_setdefaultcolor (void);
int mt_setcursorvisible (int value);
int mt_delline (void);