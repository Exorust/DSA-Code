#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int values[27];
  values[1]=2;
  values[2]=22;
  values[3]=222;
  values[4]=3;
  values[5]=33;
  values[6]=333;
  values[7]=4;
  values[8]=44;
  values[9]=444;
  values[10]=5;
  values[11]=55;
  values[12]=555;
  values[13]=6;
  values[14]=66;
  values[15]=666;
  values[16]=7;
  values[17]=77;
  values[18]=777;
  values[19]=7777;
  values[20]=8;
  values[21]=88;
  values[22]=888;
  values[23]=9;
  values[24]=99;
  values[25]=999;
  values[26]=9999;
  char c=getchar();
  char prev = ' ';
  while(c != '\n') {
    int temp = (int)c;
    temp -= 96;
    if(prev == c) {
      printf(" %d",values[temp] );
    }
    else {
      printf("%d",values[temp] );
    }
    prev = c;
    c = getchar();
  }
  return 0;
}
