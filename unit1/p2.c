#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10],i,sum;
    float avg;
    printf("enter 10 values:");

    sum=0;

    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    avg=sum/10;

    printf("sum= %d\n",sum);
    printf("average=%f",avg);
    getch();
}
