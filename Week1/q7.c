#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]) {
  unsigned long long num,x;
  scanf("%llu", &num);
  fflush(stdout);
  x = num;
  int count=0;
  do {
    if(x%2 == 1) {
      count++;
    }
    x /=2;
  } while(x !=1);
  count++;
  printf("%d\n",count );
  return 0;
}
