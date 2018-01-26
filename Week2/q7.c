#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main() {
  int i=0,j,n;
  scanf("%d\n",&n );
  char message[100];
  char c;
  c=getchar();
  while(c != '\n') {
    if(c != ' ') {
      message[i] = c;
      i++;
    }
    c = getchar();
  }
  message[i] = '\n';
  printf("%s\n",message );
  // scanf("%100[^\n]s", message);

  int len = strlen(message);
  int arrlen = (len/n) +1;

  char** arr = (char**)malloc(n*sizeof(char*));
  for(i =0;i<n;i++) {
    arr[i] = (char*)malloc(arrlen*sizeof(char));
  }

  for(i=0;i<n;i++) {
    for(j=0;j<arrlen;j++) {
      arr[i][j] = '\0';
    }
  }

  for(i=0;i<len; i++) {
    arr[i%n][i/n] = message[i];
  }

  for(i=0;i<n;i++) {
    for(j=0;j<arrlen;j++) {
      // if(arr[i][j] == '\0') {
      //   break;
      // }
      // else {
      //   printf("%c", arr[i][j] );
      // }
      printf("%c", arr[i][j] );
    }
  }

  return 0;
}
