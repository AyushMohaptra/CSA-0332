#include <stdio.h>
int array[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int main(){
    int size=sizeof(array)/sizeof(array[0]);
    int i, search;
    scanf("%d", &search);
    for(i=0;i<size;i++) {
        if (array[i]==search)
        {
            printf("ELEMENT FOUND AT INDEX %d ",i);
        }
    }
    return 0;}