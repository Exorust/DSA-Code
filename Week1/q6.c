#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]) {
  int c,n,p,i;
  int final =1;
  scanf("%d %d %d", &c, &n,&p);
  for(i=0;i<n;i++) {
    final *=  c;
    final %= p;
  }
  printf("%d\n", final);
  return 0;
}
