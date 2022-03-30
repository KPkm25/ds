#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ss 50
int ipp(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case ')':return 0;
        case '(':return 9;
        default: return 7;

    }
}
int sp(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 4;
        case '#':return -1;
        case '(':return 0;
        default: return 8;
        
    }
}
void push(char item,int *top,char s[])
{
    if(*top==ss-1)
    {
        printf("Overflow");
        return;
    }
    *top+=1;
    s[*top]=item;
}
char pop(int *top,char s[])
{
    char item;
    if(*top==-1)
    {
        printf("Underflow");
        return;
    }
    item=s[*top];
    *top-=1;
    return item;
}
void itp(char in[],char po[])
{
    int j,n,i,top=-1;
    char symbol,s[50];
    j=0;
    n=strlen(in);
    push('#',&top,s);
    for(i=0;i<n;i++)
    {
        symbol=in[i];
        while(sp(s[top])>ipp(symbol))
        {
            po[j]=pop(&top,s);
            j+=1;
        }
        if(sp(s[top])!=ipp(symbol))
        {
            push(symbol,&top,s);
        }
        else
            pop(&top,s);
    }
    while(s[top]!='#')
    {
        po[j]=pop(&top,s);
        j+=1;
    }
    po[j]='\0';
}
void main()
{
    char in[50],po[50];
    printf("Enter infix exp:");
    scanf("%s",&in);
    itp(in,po);
    printf("Postfix exp is %s",po);

}