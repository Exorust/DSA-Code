#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char encode(char input) {
  int temp = (int)input;
  temp +=3;
  temp-=97;
  temp = temp%26;
  temp +=97;
  char output = (char)temp;
  return output;
}

char* flip(char* input, int len) {
  char* output = (char*)malloc(len*sizeof(char));
  int i;
  for(i=0;i<len;i++) {
    output[len-i-1] = encode(input[i]);
  }
  return output;
}

int main() {
  char* string = (char*)malloc(100*sizeof(char));
  char* output = (char*)malloc(100*sizeof(char));
  char* word = (char*)malloc(50*sizeof(char));
  // output[0] = "\0";
  scanf("%100[^\n]s\n",string);
  char* token = strtok(string," ");
  word = flip(token, strlen(token));
  strcat(output,word);

  while(token != NULL) {
    token = strtok(NULL, " ");
    if(token != NULL) {
      word = flip(token, strlen(token));
      strcat(output," ");
      strcat(output,word);
    }
  }
  printf("%s\n", output );
  return 0;
}
