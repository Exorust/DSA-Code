#include<stdio.h>
#include<stdlib.h>

int main() {
  int m,p,n;
  int i,j,k;
  scanf("%d %d",&m, &p );
  int** arr1 = (int**)malloc(p*(sizeof(int*)));
  for(i=0;i<p;i++) {
    arr1[i]= (int*)malloc(m*(sizeof(int)));
  }
  for(i=0;i<m;i++){
    for(j=0;j<p;j++){
      scanf("%d", &arr1[i][j] );
    }
  }
  scanf("%d %d",&p, &n );
  int** arr2 = (int**)malloc(n*(sizeof(int*)));
  for(i=0;i<n;i++) {
    arr2[i]= (int*)malloc(p*(sizeof(int)));
  }
  for(i=0;i<p;i++){
    for(j=0;j<n;j++){
      scanf("%d", &arr2[i][j] );
    }
  }
  printf("End\n");
  fflush(stdout);
  int colsum=0,rowsum=0,sum=0;
  for(k=0;k<p;k++,colsum=0,rowsum=0){
    for(i=0;i<m;i++){
      colsum += arr1[i][k];
    }
    for(j=9;j<n;j++){
      rowsum +=arr2[k][j];
    }
    sum += colsum*rowsum;
  }
  printf("%d\n", sum );
  return 0;
}
