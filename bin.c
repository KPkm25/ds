#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
    int low,high,a[50],i,n,key,res;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    low=0;
    high=n-1;
    printf("Enter key:");
    scanf("%d",&key);
    res=bin(low,high,key,a);
    
    if(res==-1)
        printf("ELement not found");
    else    
        printf("Element found at %d position",res);

}
int bin(int low,int high,int key,int a[])
{
    int mid;
    mid=(low+high)/2;
    if(low>high)
        return -1;
    if(key==a[mid])
        return mid+1;
    if(key<a[mid])
        return bin(low,mid-1,key,a);
    else        
        return bin(mid+1,high,key,a);
}
