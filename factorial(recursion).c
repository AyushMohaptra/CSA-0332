int N;
int factorial(N)
{
    if (N <= 1)
        return 1;
    else
        return N * factorial(N - 1);
}
int main(){
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    printf("Factorial of %d is %d\n", N, factorial(N));
    return 0;
}