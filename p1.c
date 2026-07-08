#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10],i,s;
    printf("enter 10 values");

    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }


    for(i=0;i<=9;i++)
    {
        printf("%d\n",a[i]);
    }
    printf("enter the value want to search");
    scanf("%d",&s);
    for(i=0;i<=9;i++)
    {
        if(s==a[i])
        {
           break;
        }
    }
    if(i==10)
    {
        printf("value not found");
    }
    else
    {
        printf("value found at location %d",i+1);
    }
    getch();
}
