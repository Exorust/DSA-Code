#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {

  int num,i,j;
  scanf("%d", &num );
  int a,b,c,d;
  int k=0,l=0,m=num-1,n=num-1;
  int** arr = (int**)malloc(num*sizeof(int*));
  for(i=0;i<num;i++) {
    arr[i] = (int*)malloc(num*sizeof(int));
  }
  i=1;
  while(i<=num*num) {
    for(a=l;a<=n;a++) {
      arr[k][a] = i++;
    }
    k++;
    for(b=k;b<=m;b++) {
      arr[b][n] = i++;
    }
    n--;
    for(c=n;c>=l;c--) {
      arr[m][c] = i++;
    }
    m--;
    for(d=m;d<k;d++) {
      arr[d][l] = i++;
    }
    l--;
  }

  for(i=0;i<num;i++) {
    for(j=0;j<num;j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  free(arr);
  return 0;
}
