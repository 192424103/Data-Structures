#include<stdio.h>

int main()
{
    int n,a=0,b=1,c,i;

    printf("Enter number of terms: ");
    scanf("%d",&n);

    printf("Fibonacci Series:\n");

    for(i=1;i<=n;i++)
    {
        if(i==1)
            printf("%d ",a);
        else if(i==2)
            printf("%d ",b);
        else
        {
            c=a+b;
            printf("%d ",c);
            a=b;
            b=c;
        }
    }

    return 0;
}
