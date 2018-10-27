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
#include "protein_utils.h"

void removeChar(char *s, char c);

char *DNAstuffs(const char *filePath);

char *clonegetFileContents(const char *filePath);

int main(int argc, char **argv) {


char *Ans = DNAstuffs(argv[1]);
removeChar(Ans, ' ');
removeChar(Ans, '\n');
removeChar(Ans, '\t');


FILE *outputFile = fopen(argv[2], "w");
char vic[3];
char tor = NULL;
int n = 0;
int i;
for (i = 0;i < strlen(Ans); i++) {
vic[n] = Ans[i]; n++;
if(n == 3){
  n = 0;
      tor = rnaToProtein(vic);
    if(tor == 'x'){
      break;
    }
    fprintf(outputFile, "%c\n", tor);
  if(tor == 'x'){
  break;
      }
    }
  }
fclose(outputFile);
return 0;
}

char *DNAstuffs(const char *filePath){

int i;
char *Stuff = clonegetFileContents(filePath);
for( i = 0; i < strlen(Stuff); i++)
{
  if (Stuff[i] == 'T') {
    Stuff[i] = 'U';
  }
}
return Stuff;
}

char *clonegetFileContents(const char *filePath) {

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
//using from string_utils.c from hack 8
void removeChar(char *s, char c)
  { if(s == NULL) {
    return;
  }
  for(int i = 0; i < strlen(s); i++) {
    int j = 0;
  	if(s[i] == c) {
  	  for(int j = i; j < strlen(s); j++) {
  		s[j] = s[j + 1];
}
j = i;
    while(s[j] == c) {
      for(int j = i; j < strlen(s); j++) {
  		s[j] = s[j + 1];
  	  }
      }

} else if(s[i] == '\0') {
  	  for(int j = i; j < strlen(s); j++) {
  		s[j] = '\0';
  	  }
  	}

    }

    return;
}
