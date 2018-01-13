#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char letter, char* letters, int len) {
  int i;
  for (i = 0; i < len; i++) {
    if(letters[i] == letter) {
      return i;
    }
  }
  return -1;
}

int main() {
  char string[100];
  scanf("%100[^\n]s\n",string );
  int len = strlen(string);
  int index=0,i;
  char* letters = (char*)malloc(len*sizeof(char));
  int* num = (int*)malloc(len*sizeof(int));
  for (i = 0; i < len; i++) {
    letters[i] = "\0";
    num[i] = 0;
  }
  for (i = 0; i < len; i++) {
    int tmp = check(string[i],letters,len);
    if(tmp == -1){
      letters[index] = string[i];
      num[index] = 1;
      index++;
    }
    else {
      num[tmp] += 1;
    }
  }
  for (i = 0; i < index; i++) {
    printf("%c\t", letters[i]);
    printf("%d\n", num[i]);
  }
  return 0;
}
