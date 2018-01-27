#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 6562

long long unsigned decr(long long unsigned num) {
  long long unsigned test = num;
  int index=0;
  long long unsigned decimal=0;
  while(num != 0) {
    decimal += (num%10)*(pow(3,index));
    num /=10;
    index++;
  }
  decimal--;
  index = 0;
  long long unsigned ternary = 0;
  while(decimal!=0) {
    ternary += (decimal%3)*(pow(10,index));
    decimal /= 3;
    index++;
  }

  // printf("Decrement %llu>%llu\n",test,ternary );
  return ternary;
}

void evaluator(long long unsigned num) {
  int test = num;
  int sum = 0,digit,rev_index =9,index=0,i;
  char symbols[9];
  int prev_operator =2;
  int prev_number=1;
  int current_digit=2;
  sum +=1;

  for(index=0;index<8;index++) {
    digit = num%10;
    if(digit == 2) {
      sum +=current_digit;
      symbols[index] = '+';
      prev_number = current_digit;
    }
    else if(digit == 1) {
      sum -=current_digit;
      symbols[index] = '-';
      prev_number = current_digit;
    }
    else if(digit == 0) {
      if(prev_operator == 2) {
        sum = sum - prev_number + (prev_number*10+current_digit);
      }
      else if(prev_operator==1){
        sum = sum + prev_number - (prev_number*10+current_digit);
      }
      else{
        printf("Fail %d %d\n",test,prev_operator );
      }
      prev_number = prev_number*10+current_digit;
      symbols[index] = '\0';
    }
    if(digit!=0){
      prev_operator = digit;
    }
    current_digit++;
    num/=10;

  }

  if(sum == 100) {
    for(i=0;i<8;i++){
      printf("%d%c",i+1,symbols[i]);
    }
    printf("9" );
    printf("=%d\n", sum);
  }
  // printf("%d\n", test);
}

int main(int argc, char const *argv[]) {

  int start = 22222222;
  while(start!=0){
    evaluator(start);
    start = decr(start);
  }

  return 0;
}
