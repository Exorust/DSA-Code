#include <stdio.h>
#include <stdlib.h>

void heapify(int*arr,int n) {
  int i,j,tmp;
  int limit = (n/2)+1;
  for(i=1;i<=limit;i++) {
    if(2*i < n && arr[2*i] > arr[i]) {
      tmp = arr[i];
      arr[i] = arr[2*i];
      arr[2*i] = tmp;
    }
    if((2*i+1) < n && arr[2*i+1] > arr[i]) {
      tmp = arr[i];
      arr[i] = arr[2*i+1];
      arr[2*i+1] = tmp;
    }
  }
  for(i=1;i<=n;i++) {
    printf("%d ", arr[i] );
  }
  printf("\n" );
}

int main(int argc, char const *argv[]) {

  int n,i,j,tmp,count;
  scanf("%d",&n );

  int* arr = malloc((n+2)*sizeof(int));
  arr[0] = 0;

  for(i=1;i<=n;i++) {
    scanf("%d", &arr[i] );
  }

  heapify(arr,n);
  for(count=n;count>1;count--) {
    // arr[1] = arr[1] ^ arr[count];
    // arr[count] = arr[1] ^ arr[count];
    // arr[1] = arr[1] ^ arr[count];
    tmp = arr[1];
    arr[1] = arr[count];
    arr[count] = tmp;
    heapify(arr,count);
  }



  for(i=1;i<=n;i++) {
    printf("%d ", arr[i] );
  }
  return 0;
}
