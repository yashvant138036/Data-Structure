#include <stdio.h>
#include <conio.h>

int main()
{
    int A[3], B[3], C[3];
    int i;

    printf("Enter 3 elements of Array A:\n");
    for(i = 0; i < 3; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter 3 elements of Array B:\n");
    for(i = 0; i < 3; i++)
    {
        printf("B[%d] = ", i);
        scanf("%d", &B[i]);
    }

    for(i = 0; i < 3; i++)
    {
        C[i] = A[i] + B[i];
    }
    printf("Array C (A + B):\n");
    for(i = 0; i < 3; i++)
    {
        printf("C[%d] = %d\n", i, C[i]);
    }

    return 0;
}
