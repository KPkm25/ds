#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*N;

N push(int item,N first)
{
    N temp;
    temp=(N)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=first;
    if(first==NULL)
        return temp;
    first=temp;
    return first;
    
}
N pop(N first)
{
    N temp;
    if(first==NULL)
    {
        printf("Deletion not possible");
        return first;
    }
    temp=first;
    first=first->link;
    printf("Deleted info is %d",temp->info);
    free(temp);
    return first;

}
void display(N first)
{
    N cur;
    if(first==NULL)
    {
        printf("Empty");
        return;
    }
    cur=first;
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->link;
    }
}
void main()
{
    int choice,item;
    N first;
    first=NULL;
    for(;;)
    {
        printf("1.Push\t2.Pop\t3.Display\t4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter item:");
                    scanf("%d",&item);
                    first=push(item,first);
                    break;
            case 2: first=pop(first);
                    break;
            case 3: display(first);
                    break;
            default: exit(0);
        }

    }
}