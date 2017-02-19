/* powers.c */

/*
 * Adam Reid
 * 2014
 */

#include "powersI.h"

int main(int argc, char * * argv)
{
    checkArgs(argc);
    printPowers(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10), strtol(argv[3], NULL, 10));
    return(0);
}
