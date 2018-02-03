#include<stdio.h>
#include<math.h>

int digitcount(long long unsigned num) {
  int count =0;
  
  while(num != 0) {
    num /=10;
    count++;
  }

  return count;

}

int chop(int num,int a, int b) {

}


int main() {

  int seed, reps,square;
  int even = 0;
  scanf("%d %d", &seed,&reps);
  int size = digitcount(seed);
  if(size%2 == 0) {
    even =1;
  }
  for(i=0;i<reps;i++) {
    square = seed*seed;
    if((digitcount(square)%2) == 0 ) {
      if((digitcount(seed)%2) == 0 ) {

      }
      else {

      }
    }
    else {
      if((digitcount(seed)%2) == 0 ) {

      }
      else {

      }
    }
  }


  return 0;
}
