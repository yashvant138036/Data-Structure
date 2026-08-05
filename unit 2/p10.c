#include <stdio.h>

void findMinMax(int a[], int n, int i, int *min, int *max)
{
    if(i == n)
        return;

    if(a[i] < *min)
        *min = a[i];

    if(a[i] > *max)
        *max = a[i];

    findMinMax(a, n, i + 1, min, max);
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int min = a[0];
    int max = a[0];

    findMinMax(a, n, 0, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}
