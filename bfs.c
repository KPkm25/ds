#include<stdio.h>
#include<stdlib.h>
void bfs(int n,int a[][20],int src,int s[20],int t[][5])
{
    int f,r,k,u,v,q[20];
    f=0;
    r=-1;
    k=1;
    s[src]=1;
    r+=1;
    q[r]=src;
    while(f<=r)
    {
        u=q[f];
        f+=1;
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1 && a[v]==0)
            {
                s[v]=1;
                r+=1;
                q[r]=v;
                t[k][1]=u;
                t[k][2]=v;
                k+=1;
            }
        }
    }
}
void main()
{
    int flag,n,i,j,a[20][20],src,s[20],t[20][5];
    flag=1;
    printf("Enter vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    printf("Read src:");
    scanf("%d",&src);
    for(i=1;i<=n;i++)
        s[i]=0;
    bfs(n,a,src,s,t);
    for(i=1;i<=n;i++)
    {
        if(s[i]==0)
        {
            printf("Node %d isn't reachable from %d\n",i,src);
            flag=0;
        }
        else    
            printf("Node %d is reachable from %d\n",i,src);
    }
    if(flag==0)
        printf("Some nodes aren't reachable");
    else    
    {
        printf("Spanning tree is\n");
        for(i=1;i<=n;i++)
        {
            printf("%d-%d\n",t[i][1],t[i][2]);
        }
    }
}