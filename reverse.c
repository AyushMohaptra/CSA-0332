#include <stdio.h>
int i,j,k;
int rev(N){
  int r=0;
  while(N>0){
    r=r*10+N%10;
    N=N/10;
    }
    return r;}
int main() {
    scanf("%d",&i);
    printf("The Number is : %d\n",i);
    printf("The Number after reversing is : %d",rev(i));
    return 0;
}