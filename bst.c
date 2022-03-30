#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*rlink;
    struct node*llink;
};
typedef struct node*N;
N in(int item,N root)
{
    N temp,cur,prev;
    temp=(N)malloc(sizeof(struct node));
    temp->info=item;
    temp->rlink=temp->llink=NULL;
    if(root==NULL)
        return temp;
    cur=root;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if(item<cur->info)
            cur=cur->llink;
        if(item>cur->info)
            cur=cur->rlink;
        else   
        { 
            printf("Item exits");
            free(temp);
            return root;
        }    
    }
    if(item<prev->info)
        prev->llink=temp;
    if(item>prev->info)
        prev->rlink=temp;
    return root;
}
void pr(N root)
{
    if(root==NULL)
        return;
    printf("%d\n",root->info);
    pr(root->llink);
    pr(root->rlink);
}
void ir(N root)
{
    if(root==NULL)
        return;
    pr(root->llink);
    printf("%d\n",root->info); 
    pr(root->rlink);
}
void po(N root)
{
    if(root==NULL)
        return;
    
    pr(root->llink);
    pr(root->rlink);
    printf("%d\n",root->info);
}
void main()
{
    N root;
    int choice,item;
    root=NULL;
    for(;;)
    {
        printf("1.Insert\t2.Pr\t3.Ir\t4.Po\t5.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Insert item:");
                    scanf("%d",&item);
                    root=in(item,root);
                    break;
            case 2:if(root==NULL)
                        printf("Empty");
                    else    
                        pr(root);
                    break;
            case 3:if(root==NULL)
                        printf("Empty");
                    else    
                        ir(root);
                    break;
            case 4:if(root==NULL)
                        printf("Empty");
                    else    
                        po(root);
                    break;
            default:exit(0);
        
        
        }
    }
}