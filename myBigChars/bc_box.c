#include <myBigChars.h>
#include <myTerm.h>

int bc_box(int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg, char *header, enum colors header_fg, enum colors header_bg)
{
    mt_clrscr();
    mt_gotoXY(y1, x1);
    printf("\E(0");
    printf("l");
    for (int i = 0; i < x2; i++)
        printf("q");
    printf("k");
    for (int i = 0; i < y2; i++)
    {
        mt_gotoXY(y1 + i, x1);
        printf("x");
        mt_gotoXY(y1 + i + 1, x1 + x2 + 1);
        printf("x");
    }
    mt_gotoXY(y1 + y2, x1 - 1);
    printf("m");
    for (int i = 0; i < x2; i++)
    {
        printf("q");
    }
    printf("j\E(B");
    mt_delline();
    printf("\n");
    return 0;
}