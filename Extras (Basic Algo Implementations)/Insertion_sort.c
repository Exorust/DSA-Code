#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int n,i,j,temp;
  scanf("%d",&n );

  int* arr = (int*)malloc(n*sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d", &arr[i] );
  }

  for(i=0;i<n;i++){
    for(j=i;j>=0;j--){
      if(arr[j]>arr[j-1]) {
        break;
      }
      else {
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
    }
  }

  for(i=0;i<n;i++) {
    printf("%d ", arr[i] );
  }
  return 0;
}
