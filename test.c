/**
Author: Victor Nguyen, Collin Sipple
My NU ID: 02357235
CLASS: 155E
Section 250
Date Started: 10/24/2018
Date Finished: 10/26/2018
 *
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"file_utils.h"

int main(int argc, char **argv) {
  char *string = getFileContents("utils.txt");
  for(int i = 0; i < strlen(string); i++) {
    printf("%c", string[i]);
  }
  printf("\n");
  int lines = 0;
  char **stringMatrix = getFileLines("utils.txt", &lines);
  for(int i = 0; i < lines; i++) {
    printf("%s\n", stringMatrix[i]);
  }
  return 0;
}
