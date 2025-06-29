#include<stdio.h>
int main() {
  int i,j,k;
  int matrix[3][3];
  int matrix1[3][3];
  int matrix2[3][3];
  for(i=0;i<3;i++) {
    for(j=0;j<3;j++){
      printf("Enter element of 2nd matrix \n");
      scanf("%d",&matrix1[i][j]);
    }
  }

  for(i=0;i<3;i++) {
    for(j=0;j<3;j++) {
      printf("Enter element of 1st matrix \n");
      scanf("%d",&matrix[i][j]);
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      for (k = 0; k < 3; k++) {
        matrix2[i][j] += matrix[i][k] * matrix1[k][j];
      }
    }
  }

  for(i=0;i<3;i++) {
    for(j=0;j<3;j++) {
      printf("%d\t",matrix2[i][j]);
    }
  }
  return 0;}
