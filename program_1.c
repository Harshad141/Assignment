#include<stdio.h>
#include<string.h>
#define MAX 1000
int top=-1;
int insert;
char reverse_string[MAX];
int isempty();
int isfull();
void push(char item);
char pop();
int main()
{
char string[MAX];
int i;
printf("\nInput a string :");
scanf("%s",string);
for(i=0;i<strlen(string);i++)
push(string[i]);
for(i=0;i<strlen(string);i++)
string[i]=pop();
printf("\nReverse string is: %s",string);
return 0;
}

void push(char insert)
{
if(isfull())
{
printf("\n Stack is full");

}
top++;
reverse_string[top]=insert;
}
char pop()
{
if(isempty())
{
printf("\n Stack is empty");
return 0;
}
insert=reverse_string[top];
top--;
return insert;
}
int isempty()
{
if(top==-1)
return 1;
else
return 0;
}
int isfull()
{
if(top==MAX-1)
return 1;
else
return 0;
}