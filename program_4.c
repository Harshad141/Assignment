# include <stdio.h>
# include <malloc.h>
#include <stdlib.h>

struct node
{
int info;
struct node *left;
struct node *right;
}*root;



void find(int item,struct node **par,struct node **loc)
{
struct node *ptr,*ptrsave;

if(root==NULL)  
{
*loc=NULL;
*par=NULL;
return;
}
if(item==root->info) 
{
*loc=root;
*par=NULL;
return;
}
if(item<root->info)
ptr=root->left;
else
ptr=root->right;
ptrsave=root;

while(ptr!=NULL)
{
if(item==ptr->info)
{       *loc=ptr;
*par=ptrsave;
return;
}
ptrsave=ptr;
if(item<ptr->info)
ptr=ptr->left;
else
ptr=ptr->right;
}
*loc=NULL;   
*par=ptrsave;
}

void insert(int item)
{       struct node *tmp,*parent,*location;
find(item,&parent,&location);
if(location!=NULL)
{
printf("Item already present");
return;
}

tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=item;
tmp->left=NULL;
tmp->right=NULL;

if(parent==NULL)
root=tmp;
else
if(item<parent->info)
parent->left=tmp;
else
parent->right=tmp;
}


void case_a(struct node *par,struct node *loc )
{
if(par==NULL) 
root=NULL;
else
if(loc==par->left)
par->left=NULL;
else
par->right=NULL;
}

void case_b(struct node *par,struct node *loc)
{
struct node *child;


if(loc->left!=NULL) 
child=loc->left;
else                
child=loc->right;

if(par==NULL )  
root=child;
else
if( loc==par->left)   
par->left=child;
else                 
par->right=child;
}

void case_c(struct node *par,struct node *loc)
{
struct node *ptr,*ptrsave,*suc,*parsuc;


ptrsave=loc;
ptr=loc->right;
while(ptr->left!=NULL)
{
ptrsave=ptr;
ptr=ptr->left;
}
suc=ptr;
parsuc=ptrsave;

if(suc->left==NULL && suc->right==NULL)
case_a(parsuc,suc);
else
case_b(parsuc,suc);

if(par==NULL) 
root=suc;
else
if(loc==par->left)
par->left=suc;
else
par->right=suc;

suc->left=loc->left;
suc->right=loc->right;
}
int del(int item)
{
struct node *parent,*location;
if(root==NULL)
{
printf("Tree empty");
return 0;
}

find(item,&parent,&location);
if(location==NULL)
{
printf("Item not present in tree");
return 0;
}

if(location->left==NULL && location->right==NULL)
case_a(parent,location);
if(location->left!=NULL && location->right==NULL)
case_b(parent,location);
if(location->left==NULL && location->right!=NULL)
case_b(parent,location);
if(location->left!=NULL && location->right!=NULL)
case_c(parent,location);
free(location);
}
void display(struct node *ptr,int level)
{
int i;
if ( ptr!=NULL )
{
display(ptr->right, level+1);
printf("\n");
for (i = 0; i < level; i++)
printf("    ");
printf("%d", ptr->info);
display(ptr->left, level+1);
}
}
int main()
{
int choice,num;
root=NULL;
while(1)
{
printf("\n");
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Quit\n");
printf("Enter your choice : ");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("Enter the number to be inserted : ");
scanf("%d",&num);
insert(num);
break;
case 2:
printf("Enter the number to be deleted : ");
scanf("%d",&num);
del(num);
break;
case 3:
display(root,1);
break;
case 4:
            exit(0);
default:
printf("Wrong choice\n");
}
}
return 0;}