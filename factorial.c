#include <stdio.h>
int main() {
  int n, i;
  int sum1=1;
  scanf("%d", &n);
  for(i=1;i<=n;i++)
    sum1=sum1*i;
  printf("%d\n", sum1);
}