#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {

  int n,i,j;
  scanf("%d",&n );

  int* arr = (int*)malloc(n*sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d", &arr[i] );
  }


  int start=0,tmp;
  int min_index;
  for(i=0;i<n;i++,start++){
    for(j=start,min_index=start;j<n;j++){
      if(arr[j]<arr[min_index]) {
        min_index=j;
      }
    }
    tmp = arr[min_index];
    arr[min_index] = arr[start];
    arr[start] = tmp;
  }

  for(i=0;i<n;i++) {
    printf("%d ", arr[i] );
  }

  return 0;
}
