/* powersF.c */

/*
 * Adam Reid
 * 2014
 */

#include "powersI.h"

/*
 * checkArgs
 * Will ensure that there are four command line arguments, and exit otherwise
 * Parameters: The number of arguments
 * Return: void
 */
void checkArgs(int numArgs)
{
    if(numArgs != 4)
    {
        printf("Usage: Please enter the program runnable, followed by a base number, the number of powers to calculate, and whether to print to a file or not.\n");
        exit(0);
    }
}

/*
 * createNumber
 * Will create a number record, containing theNum as the number
 * Parameters: The number to be assigned in the new number
 * Return: the new number record
 */
Number * createNumber(int theNum)
{
    Number * newNumber;
    newNumber = malloc(sizeof(Number));
    if(newNumber == NULL)
    {
        printf("Error: There is no more memory left. Please try again later.\n");
        exit(0);
    }

    newNumber->num = theNum;
    newNumber->prev = NULL;

    return(newNumber);
}

/*
 * printPowers
 * Will calculate, and print out all of the powers of the base given from the exponent 0 to the exponent given by iterations
 * Parameters: The base, the highest power to be calculated, and 1 or 0 (print to a file or not)
 * Return: void
 */
void printPowers(int base, int iterations, int print)
{
    Number * start;
    Number * temp;
    Number * newNum;
    FILE * theFile;
    int toAdd;
    int i;

    start = NULL;
    temp = NULL;
    newNum = NULL;
    theFile = NULL;
    toAdd = 0;
    i = 0;

    if(print == 1)
    {
        theFile = fopen("output.txt", "w");
        if(theFile == NULL)
        {
            printf("Error: the file has not been openned properly.\nPlease try again later.\n");
            exit(0);
        }
    }

    start = createNumber(1);
    if(print == 0)
    {
        printPower(start);
        printf("\n");
    }
    else
    {
        printToFile(theFile, start);
        fputs("\n", theFile);
    }

    for(i = 1; i <= iterations; i++)
    {
        /*printf("%d\n", i);*/
        toAdd = 0;
        temp = start;
        while(temp != NULL)
        {
            /*printf("hello\n");*/
            temp->num *= base;
            /*printf("toAdd: %d\n", toAdd);*/
            temp->num += toAdd;
            toAdd = 0;
            if(temp->num >= 10)
            {
                /*printf("BAM\n");*/
                if(temp->prev == NULL)
                {
                    newNum = createNumber(0);
                    temp->prev = newNum;
                    /*printf("temp->num: %d\n", temp->num);*/
                    /*printf("temp->prev->num: %d\n", temp->prev->num);*/
                }
                /*printf("temp->num: %d\n", temp->num);*/
                toAdd = temp->num / 10;
                temp->num %= 10;
                /*printf("temp->num: %d\n", temp->num);*/
            }
            temp = temp->prev;
        }
        if(print == 0)
        {
            printPower(start);
            printf("\n");
        }
        else
        {
            printToFile(theFile, start);
            fputs("\n", theFile);
        }
    }
    if(print == 1)
    {
        /*printToFile(theFile, start);
        fputs("\n", theFile);*/
        fclose(theFile);
        printf("Output has been written to 'output.txt'\n");
    }
    emptyList(start);

}

/*
 * printPower
 * Will print out the numbers contained in the list start
 * Parameters: The right most digit of the number (the start of the list)
 * Return: void
 */
void printPower(Number * start)
{
    if(start->prev == NULL)
    {
        printf("%d", start->num);
    }
    else
    {
        printPower(start->prev);
        printf("%d", start->num);
    }
}

/*
 * printToFile
 * Will print out the numbers contained in the list start to theFile
 * Parameters: The file, and the right most digit of the number (the start of the list)
 * Return: void
 */
void printToFile(FILE * theFile, Number * start)
{
    char toPrint[2] = {""};
    if(start->prev == NULL)
    {
        sprintf(toPrint, "%d", start->num);
        /*printf("%s\n", toPrint);*/
        fputs(toPrint, theFile);
    }
    else
    {
        printToFile(theFile, start->prev);
        sprintf(toPrint, "%d", start->num);
        /*printf("%s\n", toPrint);*/
        fputs(toPrint, theFile);
    }
}

/*
 * emptyList
 * Will free all contents of the list starting at start
 * Parameters: The start of the list
 * Return: void
 */
void emptyList(Number * start)
{
    Number * temp;

    temp = NULL;

    while(start != NULL)
    {
        temp = start;
        start = start->prev;
        free(temp);
    }
}
