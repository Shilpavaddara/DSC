#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char ch)
{
    if(top ==MAX-1){
        printf("stack overflow\n");
        exit(1);
    }
    stack[++top]=ch;
}
char pop()
{
    if(top==-1){
        printf("stack underflow\n");
        exit(1);
    }
    return stack[top--];
}
int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}
void infixtopostfix(char infix[])
{

    char postfix[MAX];
    int i=0, j=0;
    char ch,x;

    while((ch=infix[i++])!= '\0'){
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')'){



            while((x=pop())!='('){
                    postfix[j++]=x;
                  }
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }

    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("postfix expression:%s\n",postfix);
}
int main()
{
    char infix[MAX];
    printf("Enter valid expression:");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}