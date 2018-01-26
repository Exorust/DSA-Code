#include<stdio.h>
#include<stdlib.h>
#define MAX 99999

int binary_query(int* arr, int beg, int end,int value) {
  int mid = (beg+end)/2;
  if(beg<=end) {
    if(beg == end || beg == mid || end == mid) {
      return arr[mid];
    }
    else if(arr[mid] == value) {
      return arr[mid];
    }
    else if(arr[mid] > value && arr[mid-1] < value) {
      return arr[mid-1];
    }
    else if(arr[mid] < value && arr[mid-1] > value) {
      return arr[mid];
    }
    else if (arr[mid] > value) {
      return binary_query(arr,beg,mid,value);
    }
    else {
      return binary_query(arr,mid,end,value);
    }
  }
  else{
    return -1;
  }

}


int total_query(int** arr, int* size) {
  int dist = MAX;
  int i,j,k,temp;
  int value[3];
  for(i=0;i<size[0];i++) {
    value[0] = arr[0][i];
    value[1] = binary_query(arr[1],0,size[1]-1,value[0]);
    value[2] = binary_query(arr[2],0,size[2]-1,value[0]);
    temp = abs(value[0]-value[1]) + abs(value[1]-value[2]) + abs(value[2]-value[0]);
    if(temp<dist) {
      dist = temp;
    }
  }
  return dist;
}



int main(int argc, char const *argv[]) {

  int i,j,k;
  int size[3],size_mod1[3],size_mod2[3];
  scanf("%d %d %d", &size[0],&size[1],&size[2] );
  int** arr = (int**)malloc(3*sizeof(int*));
  for(i=0;i<3;i++) {
      arr[i] = (int*)malloc(size[i]*sizeof(int));
  }
  int** arr_mod1 = (int**)malloc(3*sizeof(int*));
  int** arr_mod2 = (int**)malloc(3*sizeof(int*));

  for(i=0;i<3;i++) {
    for(j=0;j<size[i];j++) {
      scanf("%d", &arr[i][j] );
    }
  }
  int min[6];
  min[0] = total_query(arr,size);

  arr_mod1[0] = arr[1];
  arr_mod1[1] = arr[2];
  arr_mod1[2] = arr[0];

  size_mod1[0] = size[1];
  size_mod1[1] = size[2];
  size_mod1[2] = size[0];

  min[1] = total_query(arr_mod1,size_mod1);

  arr_mod1[0] = arr[2];
  arr_mod1[1] = arr[0];
  arr_mod1[2] = arr[1];

  size_mod1[0] = size[2];
  size_mod1[1] = size[0];
  size_mod1[2] = size[1];

  min[2] = total_query(arr_mod1,size_mod1);

  arr_mod1[0] = arr[0];
  arr_mod1[1] = arr[2];
  arr_mod1[2] = arr[1];

  size_mod1[0] = size[0];
  size_mod1[1] = size[2];
  size_mod1[2] = size[1];

  min[3] = total_query(arr_mod1,size_mod1);

  arr_mod1[0] = arr[1];
  arr_mod1[1] = arr[0];
  arr_mod1[2] = arr[2];

  size_mod1[0] = size[1];
  size_mod1[1] = size[0];
  size_mod1[2] = size[2];

  min[4] = total_query(arr_mod1,size_mod1);

  arr_mod1[0] = arr[2];
  arr_mod1[1] = arr[1];
  arr_mod1[2] = arr[0];

  size_mod1[0] = size[2];
  size_mod1[1] = size[1];
  size_mod1[2] = size[0];

  min[5] = total_query(arr_mod1,size_mod1);

  for(i=0;i<6;i++) {
    printf("%d  ", min[i]);
  }
  printf("\n");

  for(i=0;i<6;i++) {
    if(min[i]<min[0]) {
      min[0] = min[i];
    }
  }

  printf("%d\n", min[0]);

  return 0;
}
