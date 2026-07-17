#include <stdio.h>
#include <conio.h>

void main()
{
    int a[20], n, i, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid Position!");
    }
    else
    {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        for(i = n; i >= pos; i--)
        {
            a[i] = a[i - 1];
        }


        a[pos - 1] = value;

        n++;

        printf("\nArray after insertion:\n");
        for(i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
    }

    getch();
}
