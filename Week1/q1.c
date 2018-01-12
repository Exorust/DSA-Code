#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int check(char* str) {
  int i,j,flag=0;
  int len = strlen(str);
  int k = (int)sqrt((double)len);         //IMP!!
  if (sqrt((double)len) - k != 0) {
    return flag;
  }
  char** arr = (char**)malloc(k*(sizeof(char*)));
  for(i=0;i<k;i++) {
    arr[i] = (char*)malloc(k*(sizeof(char)));
  }
  for(i=0;i<k;i++) {
    for (j = 0; j <k; j++) {
      arr[i][j] = str[(k*i)+j];
    }
  }
  int index =0;
  for(j=0;j<k;j++) {
    for (i = 0; i <k; i++) {
      if(arr[i][j] != str[index++]) {
        return 0;
      }
    }
  }
  index = 0;
  for(i=k-1;i>=0;i--) {
    for (j = k-1; j>=k; j--) {
      if(arr[i][j] != str[index++]) {
        return 0;
      }
    }
  }
  for(j=k-1;j>=0;j--) {
    for (i= k-1; i>=k; i--) {
      if(arr[i][j] != str[index++]) {
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char const *argv[]) {
  int n,i,j,k,len,flag;
  char* yes = "YES";
  char* no = "NO";
  char* temp_string;
  scanf("%d\n",&n );
  char** input_array,output_array;
  input_array =(char**)malloc(n*(sizeof(char*)));
  output_array =(char**)malloc(n*(sizeof(char*)));
  for (i = 0; i < n; i++) {
    input_array[i] = (char*)malloc(4*(sizeof(char)));
  }
  for (i = 0; i < n; i++) {
    scanf("%s\n", temp_string);
    len = strlen(temp_string);
    len++;
    input_array[i] = (char*)malloc(len*(sizeof(char)));
    strcpy(input_array,temp_string);
  }
  for(i=0;i<k;i++) {
    flag = check(input_array[i]);
    if(flag) {
      strcpy(output_array,yes);
    }
    else {
      strcpy(output_array,no);
    }
  }
  for(i=0;i<n;i++) {
    printf("%s\n", output_array[i] );
  }
  return 0;
}
