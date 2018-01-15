#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char stringinput[100];
  char goodbye[7] = "goodbye";
  scanf("%s", stringinput);
  int len = strlen(stringinput);
  int i,index=0;
  for(i=0;i<len;i++) {
    if(stringinput[i] == goodbye[index]) {
      index++;
      if(index ==7) {
        break;
      }
    }
  }
  if(index == 7){
    printf("%s\n", "YES");
  }
  else {
    printf("%s\n", "NO");
  }
  return 0;
}
