#include<stdio.h>
#include<stdlib.h>
#define s 8
int in(int item,int n,int a[])
{
    int c,p;
    if(n==s+1)
    {
        printf("Heap is full");
        return n-1;
    }
    c=n;
    p=c/2;
    while(p!=0 && item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=c/2;
    }
    a[c]=item;
    return n;
}
void display(int a[],int n)
{
    int i;
    if(n==0)
    {
        printf("Heap is empty");
        return;
    }
    printf("Heap content are\n");
    for(i=1;i<=n;i++)
        printf("%d\n",a[i]);
}
void main()
{
    int a[100],choice,item,n=0;
    for(;;)
    {
        printf("1.Insert\t2.Display\t3.exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item:");
                    scanf("%d",&item);
                    n=in(item,n+1,a);
                    break;
            case 2:display(a,n);
                    break;
            default:exit(0);
        }
    }
}