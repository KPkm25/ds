#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define qs 5
void in_rear(int item,int *r,int q[],int *count)
{
    if(*count==qs)
    {
        printf("Q overflow");
        return;
    }
    *r=*r+1%qs;
    q[*r]=item;
    *count+=1;

}
void del_front(int *f,int q[],int *count)
{
    int item;
    if(*count==0)
    {
        printf("Q empty");
        return;
    }
    item=q[*f];
    printf("Deleted item is %d",item);
    *f=*f+1%qs;
    *count-=1;
}
void display(int f,int q[],int count)
{
    int i;
    if(count==0)
    {
        printf("Q empty");
        return;
    }
    for(i=1;i<=count;i++)
    {
        printf("%d\n",q[f]);
        f=f+1%qs;
    }
}
void main()
{
    int n,i,f,r,item,choice,count,q[20];
    f=0;
    count=0;
    r=-1;
    for(;;)
    {
        printf("1.Insert Rear\t2.Delete Front\t3.Display\t4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter item:");
                    scanf("%d",&item);
                    in_rear(item,&r,q,&count);
                    break;
            case 2: del_front(&f,q,&count);
                    break;
            case 3: display(f,q,count);
                    break;
            default: exit(0);
        }
    }
}