/**
Author: Victor Nguyen, Collin Sipple
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

char **getFileLines(const char *filePath, int *numLines);
