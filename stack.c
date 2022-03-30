#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ss 5
void push(int item,int *top,int s[])
{
    if(*top==ss-1)
    {
        printf("Overflow");
        return;
    }
    *top+=1;
    s[*top]=item;
}
int pop(int *top,int s[])
{
    int item;
    if(*top==-1)
    {
        printf("Underflow");
        return;
    }
    item=s[*top];
    *top-=1;
    return item;
}
void display(int top,int s[])
{
    int i;
    if(top==-1)
    {
        printf("STack empty\n");
        return;
    }
    printf("STack content are\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
}
void main()
{
    int n,i,top,item,choice,s[20];
    top=-1;
    for(;;)
    {
        printf("1.Push\t2.Pop\t3.Display\t4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter item:");
                    scanf("%d",&item);
                    push(item,&top,s);
                    break;
            case 2: pop(&top,s);
                    break;
            case 3: display(top,s);
                    break;
            default: exit(0);
        }
    }
}