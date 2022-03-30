#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define qs 5
void in_rear(int item,int *r,int q[])
{
    if(*r==qs-1)
    {
        printf("Q overflow");
        return;
    }
    *r+=1;
    q[*r]=item;

}
void del_front(int *f,int *r,int q[])
{
    int item;
    if(*f>*r)
    {
        printf("Deletion not possible");
        return;
    }
    item=q[*f];
    *f=*f+1;
    printf("Deleted item is %d",item);
    if(*f>*r)
    {
        *f=0;
        *r=-1;
    }

}
void display(int f,int r,int q[])
{
    int i;
    if(f>r)
    {
        printf("Q empty");
        return;
    }
    for(i=f;i<=r;i++)
        printf("%d\n",q[i]);
}
void main()
{
    int n,i,f,r,item,choice,q[20];
    f=0;
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
                    in_rear(item,&r,q);
                    break;
            case 2: del_front(&f,&r,q);
                    break;
            case 3: display(f,r,q);
                    break;
            default: exit(0);
        }
    }
}