#include <stdio.h>
#include <stdlib.h>

void merge(int* arr1,int* arr2, int len1,int len2)  {
  int i,j;
  int* tmp_arr = malloc((len1+len2)*sizeof(int));
  int index1=0,index2=0;
  for(i=0;i<len1+len2;i++) {
    if( index1 < len1 && index2 < len2) {
      if(arr1[index1]<arr2[index2]) {
        tmp_arr[i] = arr1[index1];
        index1++;
      }
      else {
        tmp_arr[i] = arr2[index2];
        index2++;
      }
    }
    else {
      if(index1 < len1) {
        tmp_arr[i] = arr1[index1];
        index1++;
      }
      else {
        tmp_arr[i] = arr2[index2];
        index2++;
      }
    }
  }
  for(i=0;i<len1;i++) {
    arr1[i] = tmp_arr[i];
  }
  for(j=0;j<len2;j++,i++) {
    arr2[j] = tmp_arr[i];
  }
}

void mergesort(int* arr, int len) {
  int chop_size = len/2;
  if(chop_size>1) {
    mergesort(arr,chop_size);
    mergesort(arr+chop_size,len-chop_size);
  }
  else if(len-chop_size>1) {
    mergesort(arr+chop_size,len-chop_size);
  }
  merge(arr,arr+chop_size,chop_size,len-chop_size);
}

int main(int argc, char const *argv[]) {

  int n,i,j,tmp,count;
  scanf("%d",&n );

  int* arr = malloc((n+2)*sizeof(int));

  for(i=0;i<n;i++) {
    scanf("%d", &arr[i] );
  }

  mergesort(arr,n);

  for(i=0;i<n;i++) {
    printf("%d ", arr[i] );
  }
  return 0;
}
