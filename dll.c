#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*rlink;
    struct node*llink;
};
typedef struct node*N;

N in_front(int item,N first)
{
    N temp;
    temp=(N)malloc(sizeof(struct node));
    temp->info=item;
    temp->rlink=temp->llink=NULL;
    if(first==NULL)
        return temp;
    temp->rlink=first;
    first->llink=temp;
    return temp;
}
N in_left(int item,int key,N first)
{
    N temp,cur,prev;
    temp=(N)malloc(sizeof(struct node));
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(first==NULL)
    {
        printf("Not possible");
        return first;
    }
    if(key==first->info)
    {
        temp->rlink=first;
        first->llink=temp;
        return temp;
    }
    cur=first->rlink;
    while(cur!=NULL && key!=cur->info)
        cur=cur->rlink;
    if(cur==NULL)
    {
        printf("Item not found");
        free(temp);
        return first;
    }
    prev=cur->llink;
    prev->rlink=temp;
    temp->llink=prev;
    temp->rlink=cur;
    cur->llink=temp;
    return first;

}
N del(int item,N first)
{
    N temp,cur,prev,next;
    if(first==NULL)
    {
        printf("Empty");
        return first;
    }
    if(item==first->info)
    {
        temp=first;
        first=first->rlink;
        printf("Deleted item is %d",temp->info);
        free(temp);
        return first;
    }
    cur=first->rlink;
    while(cur!=NULL && item!=cur->info)
        cur=cur->rlink;
    if(cur==NULL)
    {
        printf("Item not found");
        return first;
    }
    prev=cur->llink;
    next=cur->rlink;
    prev->rlink=next;
    if(next->rlink!=0)
        next->llink=prev;
    free(cur);
    return first;

}
void display(N first)
{
    N cur;
    if(first==NULL)
    {
        printf("List empty");
        return ;
    }
    cur=first->rlink;
    while(cur!=0)
    {
        printf("%d\n",cur->info);
        cur=cur->rlink;
    }
}
void main()
{
    N first;
    int choice,item,key;
    first=NULL;
    for(;;)
    {
        printf("1.In_Front\t2.In_Left\t3.Del\n4.Display\t5.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item:");
                    scanf("%d",&item);
                    first=in_front(item,first);
                    break;
            case 2:printf("Enter item:");
                    scanf("%d",&item);
                    printf("Enter key:");
                    scanf("%d",&key);
                    first=in_left(item,key,first);
                    break;
            case 3:printf("Enter item:");
                    scanf("%d",&item);
                    first=del(item,first);
                    break;
            case 4:display(first);
                    break;
            default:exit(0);
        }
    }
}