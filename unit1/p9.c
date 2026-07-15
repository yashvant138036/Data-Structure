#include<stdio.h>
#include<conio.h>

int main()
{
    int a[10], i, pos;

    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete (1 to 10): ");
    scanf("%d", &pos);

    if(pos < 1 || pos > 10)
    {
        printf("Invalid Position!");
    }
    else
    {

        for(i = pos - 1; i < 9; i++)
        {
            a[i] = a[i + 1];
        }

        printf("\nArray after deletion:\n");
        for(i = 0; i < 9; i++)
        {
            printf("%d ", a[i]);
        }
    }

    getch();
    return 0;
}
