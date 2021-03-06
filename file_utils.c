/**
Author: Victor Nguyen, Collin Sipple, David Ryan, Salman Djingueinabaye, Tony Ong
My NU ID: 02357235
CLASS: 155E
Section 250
Date Started: 10/24/2018
Date Finished: 10/26/2018
 *
 *given a file path/name as a string opens the file and returns
 *its entire contents as a single string.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file_utils.h"


char *getFileContents(const char *filePath) {

  FILE *file = fopen(filePath, "r");
  if(file == NULL) {
    return NULL;
  }

  char* fileString = (char*) malloc(sizeof(char) * 100000);
  char buffer[100000];
  //Allocate memory for a string

   while(fgets(buffer, 100000, file) != NULL){
     strcat(fileString,buffer);}
  fclose(file);
  return fileString;


}


/* This funciton should solve for a given a file path or name as a string opens the file and returns
 the contents of the file as an array of strings. Each element in the array should
 correspond to a line in the file. Any end line character should be chomped out and
 not included.
 */
char **getFileLines(const char *filePath, int *numLines){
  if(filePath == NULL || numLines == NULL) {
    return NULL;
  }


  FILE *file = fopen(filePath, "r");
  char buff[1000];
  *numLines = 0;
  char thangs = fgetc(file);
  while (thangs != -1) {
    thangs = fgetc(file);
    if (thangs == '\n') {
      (*numLines)++;
    }
  }
  //reopens the file, the first time
  fclose(file);
  file = fopen(filePath, "r");
  //2D array
  char** lines = (char**)malloc(sizeof(char*) * (*numLines));
  for (int i = 0; i < *numLines; i++) {
    lines[i] = (char*)malloc(sizeof(char) * 1000);
  }
  int i = 0;
  //puts every line into one pointer of the 2D array
  while (fgets(buff, 1000, file) != NULL) {
    int n = strlen(buff);
    buff[n - 1] = '\0';
    strcpy(lines[i], buff);
    i++;
  }
  fclose(file);
  return lines;
}
