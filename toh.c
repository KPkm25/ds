#include<stdio.h>
#include<conio.h>
int c=0;

void toh(int n,char src,char temp,char dest)
{
    if(n==1)
    {
        printf("Move %d disc from %c to %c\n",n,src,temp);
        c++;
        return;
    }
    toh(n-1,src,dest,temp);
    printf("Move %d disc from %c to %c\n",n,src,temp);
    c++;
    toh(n-1,temp,src,dest);
}
void main()
{
    int n;
    printf("Enter no. of discs:");
    scanf("%d",&n);
    toh(n,'A','B','C');
    printf("Total no. of moves is %d",c);
}