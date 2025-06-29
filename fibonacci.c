#include <stdio.h>
int main() {
    int n, a = 0, b = 1, c;
    printf("Enter the number of terms : ");
    scanf("%d", &n);
    printf("0 1 ");
    for(n=0; n < 10; n++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}