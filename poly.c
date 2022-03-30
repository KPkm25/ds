#include<stdio.h>
#include<stdlib.h>
struct node
{
    int cf;
    int px;
    struct node*link;
};
typedef struct node*N;
N in_rear(int cf,int px,N head)
{
    N temp,cur;
    temp=(N)malloc(sizeof(struct node));
    temp->cf=cf;
    temp->px=px;
    temp->link=temp;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}
N read(N head)
{
    int n,i,cf,px;
    printf("ENter no. of terms\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter cf and px of %d term:",i);
        scanf("%d%d",&cf,&px);
        head=in_rear(cf,px,head);
    }
    return head;
}
int compare(int x,int y)
{
    if(x>y)
        return -1;
    if(x==y)
        return 0;
    else
        return 1;
}
N add(N h1,N h2,N h3)
{
    N p1,p2;
    int sum;
    p1=h1->link;
    p2=h2->link;
    while(p1!=h1 && p2!=h2)
    {
        switch(compare(p1->px,p2->px))
        {
            case 0:sum=p1->cf+p2->cf;
                    if(sum!=0)
                        h3=in_rear(sum,p1->px,h3);
                    p1=p1->link;
                    p2=p2->link;
                    break;
            case 1:h3=in_rear(p2->cf,p2->px,h3);
                    p2=p2->link;;
                    break;
            case -1:h3=in_rear(p1->cf,p1->px,h3);
                    p1=p1->link;;
                    break;
        }
    }
    while(p1!=h1)
    {
        h3=in_rear(p1->cf,p1->px,h3);
            p1=p1->link;;
    }
    while(p2!=h2)
    {
        h3=in_rear(p2->cf,p2->px,h3);
           p2=p2->link;;
    }
    return h3;
}
void display(N head)
{
    N cur;
    if(head->link==head)
    {
        printf("Poly doesn't exist");
        return;
    }
    cur=head->link;
    while(cur!=head)
    {
        if(cur->cf>0)
            printf("+");
        printf("%dx^%d",cur->cf,cur->px);
        cur=cur->link;
    }
}
void main()
{
    N h1,h2,h3;
    h1=(N)malloc(sizeof(struct node));
    h2=(N)malloc(sizeof(struct node));
    h3=(N)malloc(sizeof(struct node));
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;
    printf("Enter 1st poly:");
    h1=read(h1);
    printf("Enter 2nd poly:");
    h2=read(h2);
    h3=add(h1,h2,h3);
    printf("The 1st poly is\n");
    display(h1);
    printf("The 2nd poly is\n");
    display(h2);
    printf("The sum is\n");
    display(h3);

}