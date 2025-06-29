#include <stdio.h>
int main(){
    int array1[] = {1, 3, 5, 7, 9};
    int array2[] = {2, 4, 6, 8, 10};
    int array3[10];
    for (int i=0;i<5;i++) {
      array3[2*i]=array1[i];
      array3[2*i+1]=array2[i];
    }
    printf("Merged array is :");
    for (int j=0;j<10;j++){
      printf(" %d ", array3[j]);
    }
    return 0;}
