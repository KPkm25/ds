#include<stdio.h>
#include<stdlib.h>

void dfs(int n,int a[][20],int u,int s[],int t[][5])
{
    int v;
    static int k=1;
    s[u]=1;
    for(v=1;v<=n;v++)
    {
        if(a[u][v]==1 && s[u]==0)
        {
            t[k][1]=u;
            t[k][2]=v;
            k+=1;
            dfs(n,a,v,s,t);
        }
    }
}
void main()
{
    int flag,n,i,j,a[20][20],src,s[20],t[20][5];
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
    dfs(n,a,src,s,t);
    for(i=1;i<=n;i++)
    {
        if(s[i]==0)
        {
            printf("Graph not connected\n");
            exit(0);
        }
    }
    printf("Graph is connected\n");
    printf("Spanning tree is\n");
    for(i=1;i<=n;i++)
        printf("%d-%d\n",t[i][1],t[i][2]);
}