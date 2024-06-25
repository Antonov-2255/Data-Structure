#include <stdio.h>
#include <stdlib.h>

int main() {

int i, n, *ptr;

printf("Enter the number of values: ");
scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    /*for (i = 0; i < n; i++) {
        printf("Enter the value: ");
        scanf("%d", (ptr + i));
    }*/


    for (i = 0; i < n; i++) {
        printf("\nEntered values are: ");
        printf("%d ", *(ptr + i));
    }

    free(ptr);
}
