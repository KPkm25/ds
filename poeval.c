#include<stdio.h>
#include<string.h>
#include<math.h>
#define stacksize 75
void push(char item,int *top,char s[])
 {
     if(*top==stacksize-1)
     {
         printf("Stack overflow");

         return;
     }
     *top=*top+1;
     s[*top]=item;
 }
 int pop(int *top,char s[])
 {
     int item;
     if(*top==-1)
     {
        return -1;
     }
     item=s[*top];
     *top-=1;
     return item;
 }
 int evaluate(char postfix[])
{
    int top,n,i,op2,op1,res;
    char symbol,s[100];
    top=-1;
    n=strlen(postfix);
    for(i=0;i<n;i++)
    {
        symbol=postfix[i];
        switch(symbol)
        {
            case '+': op2=pop(&top,s);
                      op1=pop(&top,s);
                      res=op1+op2;
                      push(res,&top,s);
                      break;
            case '-': op2=pop(&top,s);
                      op1=pop(&top,s);
                      res=op1-op2;
                      push(res,&top,s);
                      break;
            case '*': op2=pop(&top,s);
                      op1=pop(&top,s);
                      res=op1*op2;
                      push(res,&top,s);
                      break;
            case '/': op2=pop(&top,s);
                      op1=pop(&top,s);
                      res=op1/op2;
                      push(res,&top,s);
                      break;
            case '^': op2=pop(&top,s);
                      op1=pop(&top,s);
                      res=(int) pow((double)op1,(double)op2);
                      push(res,&top,s);
                      break;
            default: push(symbol-'0',&top,s);
        }
    }
    return(pop(&top,s));
}
 void main()
 {
     char infix[50],postfix[50];
     int res;
     printf("Enter postfix expn:");
     scanf("%s",&postfix);
     
     res=evaluate(postfix);
   
     printf("Postfix evaluation is %d",res);

 }