#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

int my_getchar() {
  char c = getchar();
  if(c == '\n') {
    return -1;
  }
  else if( c == ' ') {
    return -100;
  }
  else {
    int i = (int)c;
    return (i-48);
  }
}

int main(int argc, char const *argv[]) {
  char txt[40];

  txt[2]='a';
  txt[12]='b';
  txt[22]='c';
  txt[3]='d';
  txt[13]='e';
  txt[23]='f';
  txt[4]='g';
  txt[14]='h';
  txt[24]='i';
  txt[5]='j';
  txt[15]='k';
  txt[25]='l';
  txt[6]='m';
  txt[16]='n';
  txt[26]='o';
  txt[7]='p';
  txt[17]='q';
  txt[27]='r';
  txt[37]='s';
  txt[8]='t';
  txt[18]='u';
  txt[28]='v';
  txt[9]='w';
  txt[19]='x';
  txt[29]='y';
  txt[39]='z';

  int c = my_getchar();
  int prev = -1;
  int space_flag=0;
  int count =0,num=0;
  while(c != -1 ) {

    if(c == prev ) {
      count++;
    }
    else if(prev !=-100  ){
      num = (count*10+prev)-10;
      printf("%c", txt[num] );
      count =1;
    }

    if(c != -100) {

    }
    else {
      count =1;
    }
    prev = c;
    c = my_getchar();
  }
  num = (count*10+prev)-10;
  printf("%c", txt[num] );
  count =1;
  printf("\n" );
  return 0;
}
