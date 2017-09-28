/* powersI.h */

/*
 * Adam Reid
 * 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct NumList
{
    int num;
    struct NumList * prev;
};
typedef struct NumList Number;

/*
 * checkArgs
 * Will ensure that there are three command line arguments, and exit otherwise
 * Parameters: The number of arguments, and the argument parameters
 * Return: void
 */
void checkArgs(int argc, char** argv);

/*
 * createNumber
 * Will create a number record, containing theNum as the number
 * Parameters: The number to be assigned in the new number
 * Return: the new number record
 */
Number * createNumber(int theNum);

/*
 * printPowers
 * Will calculate, and print out all of the powers of the base given from the exponent 0 to the exponent given by iterations
 * Parameters: The base, the highest power to be calculated, and 1 or 0 (print to a file or not)
 * Return: void
 */
void printPowers(int base, int iterations, char* printFlag);

/*
 * printPower
 * Will print out the numbers contained in the list start
 * Parameters: The right most digit of the number (the start of the list)
 * Return: void
 */
void printPower(Number * start);

/*
 * printToFile
 * Will print out the numbers contained in the list start to theFile
 * Parameters: The file, and the right most digit of the number (the start of the list)
 * Return: void
 */
void printToFile(FILE * theFile, Number * start);

/*
 * emptyList
 * Will free all contents of the list starting at start
 * Parameters: The start of the list
 * Return: void
 */
void emptyList(Number * start);
