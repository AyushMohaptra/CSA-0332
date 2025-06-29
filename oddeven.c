#include <stdio.h>

int main() {
  int n, i, num;

  printf("Enter the number of integers: ");
  scanf("%d", &n);

  printf("Enter the integers:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    if (num % 2 == 0) {
      printf("%d is EVEN\n", num);
    } else {
      printf("%d is ODD\n", num);
    }
  }

  return 0;
}
