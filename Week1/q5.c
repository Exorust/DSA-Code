#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mult(int arr[10]) {
  int i;
  int add_holder[10];
  for(i=0;i<10;i++) {
    add_holder[i] = 0;
  }
  for(i=9;i>=0;i--) {
    arr[i] *= 2;

    if(arr[i]>9) {
      if(i != 0) {
        add_holder[i-1] += (arr[i]/10);
      }
      arr[i] %=10;
    }

  }
  for(i=0;i<10;i++) {
    arr[i] +=add_holder[i];
  }
}


int main(){
  int n,i,j;
  int arr[10];
  for(i=0;i<10;i++) {
    arr[i] = 0;
  }
  arr[9] = 1;
  scanf("%d",&n );
  printf("%d\n", n);
  for(i=0;i<n;i++) {
    mult(arr);
    printf("%d : ", i);
    for(j=0;j<10;j++) {
      printf("%d", arr[j]);
    }
    printf("\n" );
    fflush(stdin);
  }
  printf("Final: " );
  for(i=0;i<10;i++) {
    printf("%d", arr[i]);
  }
  printf("\n" );
  fflush(stdin);
  return 0;
}
