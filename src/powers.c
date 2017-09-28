/* powers.c */

/*
 * Adam Reid
 * 2017
 */

#include "powersI.h"

int main(int argc, char** argv)
{
    checkArgs(argc, argv);
    if (argc == 4)
    {
        printPowers(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10), argv[3]);
    }
    if (argc == 3)
    {
        printPowers(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10), NULL);
    }

    return (0);
}
