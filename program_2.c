#include<stdio.h>
#include<string.h>
#define MAX 1000
char stack[MAX];
int top=-1;
void push(char a)
{
if(top>=MAX-1)
printf("Stack is full");
else
{
top++;
stack[top]=a;
}
}
char pop()
{
char a;
a=stack[top];
top--;
return a;
}
int operator(char sign)
{
if(sign=='^' || sign=='*' || sign=='/' || sign=='+' || sign=='-')
return 1;
else
return 0;
}
int precedence(char sign)
{
if(sign=='^')
return 3;
else if(sign=='*' || sign=='/')
return 2;
else if(sign=='+' || sign=='-')
return 1;
else
return 0;

}
int main()
{
char infix[MAX],postfix[MAX],a,b;
int i=0,j=0;
printf("\n Enter arthmetic expression");
scanf("%s",infix);
while(infix[i]!=0)
{
a=infix[i];
if(a=='(')
{
push(a);
}
else if(a>='A' && a<='Z' || a>='a' && a<='z')
{
postfix[j]=a;
j++;
}
else if(operator(a)==1)
{
b=pop();
while(operator(a)==1 && precedence(b)>precedence(a))
{
postfix[j]=b;
j++;
b=pop();
}
push(b);
push(a);
}
else if(a==')')
{
b=pop();
while(b!='(')
{
postfix[j]=b;
j++;
b=pop();
}
}
else
{
printf("\n Invalid syntax");
}
i++;
}
while(top>-1)
{
postfix[j]=pop();
j++;
}

printf("Postfix expression is %s",postfix);
return 0;
}
