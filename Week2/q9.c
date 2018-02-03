#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long unsigned convert_to_10(long long unsigned num) {
  int count = 0;
  int index=0;
  while(num != 0) {
    count = (num%10)*(long long unsigned)pow(3,index)+ count;
    index++;
    num /=10;
  }
  return count;
}

int digitcount(long long unsigned num) {
  int count =0;
  while(num != 0) {
    num /=10;
    count++;
  }
  return count;
}
long long unsigned digit_replace(long long unsigned num) {
  long long unsigned temp = 0;
  int index = 0;
  int fakeno;
  while(num != 0) {
    if(num%10 == 1) {
      fakeno = 0;
    }
    if(num%10 ==7) {
      fakeno = 1;
    }
    if(num%10 ==9) {
      fakeno = 2;
    }
    temp = temp + fakeno*(int)pow(10,index);
    index++;
    num /=10;

  }
  return temp;
}

int is_lucky(long long unsigned num) {
  while(num != 0) {
    if(num%10 == 1 || num%10 == 7 || num%10 ==9) {
      num /=10;
    }
    else {
      return -1;
    }
  }
  return 1;
}

long long unsigned gen(int num, int digits) {
  long long unsigned gen=0;
  int i;
  for(i=0;i<digits;i++) {
    gen = gen*10 +num;
  }
  return gen;
}

int main(int argc, char const *argv[]) {

  long long unsigned num;
  scanf("%llu",&num );
  int digit_total = digitcount(num);
  long long unsigned total=0;
  int digits;

  for(digits=1;digits<=digit_total;digits++) {
    long long unsigned temp1 = gen(1,digits);
    long long unsigned temp2 = gen(7,digits);
    long long unsigned temp3 = gen(9,digits);
    long long unsigned temp;
    int equals =0;

    if (is_lucky(num) == 1) {
      temp = num;
      equals = 1;
    }
    else {
      if (temp3 > num) {
        if(temp2>num) {
          if(temp1>num) {
            temp = temp1;
          }
          else {
            temp = temp2;
          }
        }
        else {
          temp = temp3;
        }
      }
    }

    while(equals ==0) {
      temp--;
      if(is_lucky(temp) == 1) {
        equals = 1;
      }
    }

    long long unsigned ternary_no = digit_replace(temp);
    long long unsigned decimals = convert_to_10(ternary_no);
    total += decimals;
  }

  printf("%llu\n",total+1 );


  return 0;
}
