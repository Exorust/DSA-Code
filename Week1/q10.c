#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mult(int arr[100], int num) {
  int add_holder[100];
  int i,j;
  for(i=0;i<100;i++) {
    add_holder[i] = 0;
  }
  for(i=99;i>=0;i--) {
    arr[i] *= num;
    if(arr[i]>9) {
      if(i != 0) {
        add_holder[i-1] += (arr[i]/10);
      }
      arr[i] %=10;
    }

  }
  for(i=0;i<100;i++) {
    arr[i] +=add_holder[i];
  }
  for(j=0;j<100;j++) {
    for(i=99;i>=0;i--) {
      if(arr[i]>9) {
        if(i != 0) {
          arr[i-1] += (arr[i]/10);
        }
        arr[i] %=10;
      }

    }
  }
}


int main(int argc, char const *argv[]) {
  int n,i;
  int arr[100];
  for(i=0;i<100;i++) {
    arr[i] = 0;
  }
  arr[99] = 1;
  scanf("%d",&n );
  for(i=1;i<=n;i++) {
    mult(arr,i);
  }
  printf("Final: " );
  for(i=0;i<100;i++) {
    printf("%d ", arr[i]);
  }
  printf("\n" );
  fflush(stdout);
  return 0;
}
