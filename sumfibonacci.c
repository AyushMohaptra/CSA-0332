#include <stdio.h>
int main(){
  int fib=1,i,j;
  int c,a=0,b=1;
  scanf("%d",&i);
  for(j=0;j<i;j++) {
    c=a+b;
    a=b;
    b=c;
    fib=fib+c;
  }
  printf("%d",fib);
    return 0;}