/**
Author: Victor Nguyen, Collin Sipple, David Ryan, Salman Djingueinabaye, Tony Ong
My NU ID: 02357235
CLASS: 155E
Section 250
Date Started: 10/24/2018
Date Finished: 10/26/2018
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//This function opens a file given a file path and returns all the contents as a
//single string


char *getFileContents(const char *filePath);

/* This funciton should solve for a given a file path or name as a string opens the file and returns
 the contents of the file as an array of strings. Each element in the array should
 correspond to a line in the file. Any end line character should be chomped out and
 not included.
 */
char **getFileLines(const char *filePath, int *numLines);
