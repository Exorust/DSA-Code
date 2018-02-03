#include<stdio.h>
#include<math.h>

int main() {

  int count = 0,i;
  long long unsigned num;
  scanf("%llu", &num);
  printf("%llu\n", num);
  while((num%2)==0) {
    count++;
    num /=2;
  }

  // long long unsigned limit = (long long unsigned)sqrtl((long double)num);
  // printf("%llu\n", limit );
  //
  int limit = 100000000;
  for(i=3;i<limit && num != 1;i+=2) {
    if(num%i == 0) {
      printf("%d\n", i );
      do {
        num/=i;
        count++;
      } while(num%i ==0);
    }
  }

  printf("%d\n", count);
  return 0;
}
