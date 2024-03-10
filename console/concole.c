#include <mySimpleComputer.h>
#include <myTerm.h>

int main()
{
    FILE *out = fopen("/dev/tty", "r");
    int fd = open ("/dev/tty", O_RDWR);
    if (stdout != out)
        return -1;
    return 0;
}