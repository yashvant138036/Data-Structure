#include <stdio.h>

int main()
{
    int n, i, scd;

    printf("Enter a number: ");
    scanf("%d", &n);

    scd = n;

    for (i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            scd = i;
            break;
        }
    }

    printf("Smallest Common Divisor of %d = %d", n, scd);

    return 0;
}
