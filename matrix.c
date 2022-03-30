#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct spm
{
    int row;
    int col;
    int value;
};
typedef struct spm M;
void main()
{
    int c,n,k,j,m,i,item,key;
    M a[20];
    printf("Enter row:");
    scanf("%d",&m);
    printf("Enter col:");
    scanf("%d",&n);
    a[0].row=m;
    a[0].col=n;
    c=0;
    k=1;
    printf("Enter matrix elements\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&item);
            if(item!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].value=item;
                c++;
                k++;
            }
        }
    }
    a[0].value=c;
    printf("Row\tCol\tValue\n");
    for(i=1;i<=a[0].value;i++)
    {
        printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].value);
    }
    printf("Enter key to be found:");
    scanf("%d",&key);
    for(i=0;i<=a[0].value;i++)
    {
        if(key==a[i].value)
        {
            printf("Element found at %d row and %d col",a[i].row,a[i].col);
            exit(0);
        }
    }
    printf("Unsuccesfull search");
}
