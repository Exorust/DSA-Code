#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
  int num_digits,distinct,i;
  scanf("%d %d",&num_digits,&distinct );
  int smallest=0,largest=0;
  int nines = num_digits-distinct+1;
  int remaining_largest = distinct-1;
  for(i=0;i<nines;i++) {
    largest = largest*10 + 9;
  }
  int countdown =8;
  for(i=0;i<remaining_largest;i++) {
    largest = largest*10 + countdown;
    countdown--;
  }

  smallest++;
  int zeros = num_digits -distinct +1;
  for(i=0;i<zeros;i++){
    smallest *=10;
  }
  int remaining_smallest = distinct -2;
  int counter =2;
  for(i=0;i<remaining_smallest;i++) {
    smallest = smallest*10 + counter;
    counter++;
  }
  printf("%d %d\n", largest, smallest);

  return 0;
}
