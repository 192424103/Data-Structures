#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push()
{
    int x;
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d",&x);
        stack[++top]=x;
    }
}

void pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
    else
        printf("Deleted Element = %d\n",stack[top--]);
}

void peek()
{
    if(top==-1)
        printf("Stack Empty\n");
    else
        printf("Top Element = %d\n",stack[top]);
}

void display()
{
    int i;
    if(top==-1)
        printf("Stack Empty\n");
    else
    {
        printf("Stack Elements:\n");
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid Choice\n");
        }
    }
}
