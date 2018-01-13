#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char const *argv[]) {
  // char* word;
  // char* string;

  char word[10];
  char string[100];

  int count = 0;

  scanf("%s\n", word);
  // printf("%s\n", word );
  scanf("%100[^\n]s\n", string);
  // printf("%s\n",string );
  // fflush(stdin);

  char* token = strtok(string," ");
  if(strcmp(token,word) == 0) {
      count++;
  }
  while(token != NULL) {
    if(strcmp(token,word) == 0) {
        count++;
    }
    token = strtok(NULL," ");
  }

  printf("%d\n",count);
  return 0;
}
