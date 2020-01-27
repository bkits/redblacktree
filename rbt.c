//2014509
#include "rbt.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

struct node
{
 void *value;
 int color;//0=red 1=black
 struct node *lchild,*rchild,*parent;
}*root;



int mikrotero (void *x,void *y,int type)
{
	if (type==0)
    {
		if ((*(int*)x)<(*(int*)y))
         {return 1;}
         if ((*(int*)x)>(*(int*)y))
         {return 0;}
	 }
	 if (type==1)
	 {
		if ((*(float*)x)<(*(float*)y))
         {return 1;}
         if ((*(float*)x)>(*(float*)y))
         {return 0;}
	 }
	 if (type==2)
	 {
		if ((*(double*)x)<(*(double*)y))
         {return 1;}
         if ((*(double*)x)>(*(double*)y))
         {return 0;}
	 }
	 if (type==3)
	 {
		if ((*(char*)x)<(*(char*)y))
         {return 1;}
         if ((*(char*)x)>(*(char*)y))
         {return 0;}
	 }
 }


int isotita (void *x,void *y,int type)
{
	if (type==0)
    {
		if ((*(int*)x)==(*(int*)y))
         {return 1;}
         else
         {return 0;}
	 }
	 if (type==1)
	 {
		if ((*(float*)x)==(*(float*)y))
         {return 1;}
         else
         {return 0;}
	 }
	 if (type==2)
	 {
		if ((*(double*)x)==(*(double*)y))
         {return 1;}
         else
         {return 0;}
	 }
	 if (type==3)
	 {
		if ((*(char*)x)==(*(char*)y))
         {return 1;}
         else
         {return 0;}
	 }
 }

/*
struct node *search (int i, struct node *r)
{if (r==NULL || r->value==i) return r;
	if (r->value>i) r=r->lchild;
	else	r=r->rchild;
	return search(i,r);}

*/

struct node *search (void *i, struct node *r,int type)
{if (r==NULL || isotita(r->value,i,type)==1) return r;
	if (mikrotero(r->value,i,type)==1) r=r->rchild;
	else	r=r->lchild;
	return search(i,r,type);}



void setparent(struct node *r, struct node *r1)
{if (r!=NULL) r->parent=r1;}



void rrrotate(struct node *x )
{	struct node *y;
	y=x->lchild;
	x->lchild=y->rchild;
	setparent(y->rchild,x);
	setparent(y,x->parent);	
	if (x->parent==NULL)
		root=y;
	else {if (x==x->parent->rchild)
		x->parent->rchild=y;
		else
		 x->parent->lchild=y;}
	y->rchild=x;
	setparent(x,y);
}


void llrotate(struct node *x )
{	struct node *y;
	y=x->rchild;
	x->rchild=y->lchild;
	setparent(y->lchild,x);
	setparent(y,x->parent);
	if (x->parent==NULL)
		root=y;
	else {if (x==x->parent->lchild) x->parent->lchild=y;
	     else x->parent->rchild=y;}
	y->lchild=x;setparent(x,y);
}




struct node *minimum(struct node *r)
{while(r->lchild!=NULL)	r=r->lchild;return r;
}
struct node *successor(struct node *r)
{if (r->rchild!=NULL)
		return(minimum(r->rchild));
	struct node *y=r->parent;
	while(y!=NULL && r==y->rchild)
	{r=y;
		y=y->parent;}
	if (y==NULL) return r;
	else return y;
}
void print(struct node *r,int type )
 { 
	struct node *z;
    if(type==0)
       {
	if (r->lchild != NULL)
        print (r->lchild,type);
        printf("\n%d    ", *(int*)(r->value));
	if (r->color==0) printf("Red"); else printf("Black");
	if (r->parent!=NULL) printf("   Parent: %d",*(int*)(r->parent->value));
	if (r->rchild != NULL)
        print (r->rchild,type);
       }
if(type==1)
       {
	if (r->lchild != NULL)
        print (r->lchild,type);
        printf("\n%f    ", *(float*)(r->value));
	if (r->color==0) printf("Red"); else printf("Black");
	if (r->parent!=NULL) printf("   Parent: %f",*(float*)(r->parent->value));
	if (r->rchild != NULL)
        print (r->rchild,type);
       }
if(type==2)
       {
	if (r->lchild != NULL)
        print (r->lchild,type);
        printf("\n%lf    ",*(double*)( r->value));
	if (r->color==0) printf("Red"); else printf("Black");
	if (r->parent!=NULL) printf("   Parent: %lf",*(double*)(r->parent->value));
	if (r->rchild != NULL)
        print (r->rchild,type);
       }

if(type==3)
       {
	if (r->lchild != NULL)
        print (r->lchild,type);
        printf("\n%c    ", *(char*)(r->value));
	if (r->color==0) printf("Red"); else printf("Black");
	if (r->parent!=NULL) printf("   Parent: %c",*(char*)(r->parent->value));
	if (r->rchild != NULL)
        print (r->rchild,type);
       }

}


void insert(struct node *z,int type)
{
   struct node *x, *y;
   y = NULL;x = root;
   while ( x!=NULL)
   {y = x;if(mikrotero(z->value,x->value,type)==1)x=x->lchild;
	else x=x->rchild;}z->parent=y;
 if(y==NULL)root=z;
   else{z->parent=y;if(mikrotero(z->value,y->value,type)==1) y->lchild = z;
	else	y->rchild = z;}}

void insertfix(struct node *x,int type)
{struct node *y;insert(x,type);while (x->parent!=NULL && x->parent->color==0)
	{if (x->parent==x->parent->parent->lchild)
	{y=x->parent->parent->rchild;
	if (y!=NULL && y->color==0){x->parent->color=1;
	y->color=1;x->parent->parent->color=0;
	x=x->parent->parent;}
	 else{if (x==x->parent->rchild)
		{x=x->parent;llrotate(x);}
	     x->parent->color=1;x->parent->parent->color=0;
	rrrotate(x->parent->parent);}}
        else
	{ y=x->parent->parent->lchild;              
	if (y!=NULL && y->color==0)
        {x->parent->color=1;y->color=1;
         x->parent->parent->color=0;x=x->parent->parent;}
         else
        {if (x==x->parent->lchild)
          {x=x->parent;rrrotate(x);}
        
         x->parent->color=1;x->parent->parent->color=0;
	llrotate(x->parent->parent);}}}root->color=1;}


void deletefix(struct node *x)
{struct node *w;
while (x!=NULL && x->color==1)
{if (x==x->parent->lchild)
{w=x->parent->rchild;
 if (w!=NULL)
  {if (w->color==0)
	{w->color=1;x->parent->color=0;
	llrotate(x->parent);w=x->parent->rchild;}
	if ( w->lchild->color==1 && w->rchild->color==1)
	{w->color=0;x=x->parent;}
	else if (w->rchild->color==1)
	 {w->lchild->color=1;w->color=0;rrrotate(w);w=x->parent->rchild;}
	w->color=x->parent->color;x->parent->color=1;w->rchild->color=1;}
	llrotate(x->parent);x=root;}
	else
	{w=x->parent->lchild;
	if (w!=NULL)
	{if (w->color==0)
	{w->color=1; x->parent->color=0;rrrotate((x->parent));
           w=x->parent->lchild;}
          if ( w->rchild->color==1 && w->lchild->color==1)
	{w->color=0;x=x->parent;}
         else if (w->lchild->color==1)
	 {w->rchild->color=1;w->color=0;llrotate(w);
          w=x->parent->lchild;}
          w->color=x->parent->color;x->parent->color=1;
          w->lchild->color=1;}rrrotate(x->parent);x=root;}x->color=1;}}
 
  void delete (struct node *z)
{struct node *y,*x;y=z;
if (root==NULL){printf("\n Empty \n");return;}
	if (z==NULL)
		printf("\n\n\tNo Node to Delete.");
	else
	{if (z->lchild==NULL || z->rchild==NULL) y=z;
	else y=successor(z);
	if (y->lchild!=NULL) {x=y->lchild;}
	else {x=y->rchild;} setparent(x,y->parent);
	if (y->parent==NULL) root=x;
	else if (y==y->parent->lchild)
		y->parent->lchild=x;
	   else {y->parent->rchild=x;}
		if (y!=z) z->value=y->value;
		if (y->color==1) deletefix(x);}}



void do_insert(int type)
{struct node *temp;float da1;double da2;int r,da0;
temp=(struct node *)malloc(sizeof(struct node));
    temp->color=0;temp->lchild=NULL;temp->rchild=NULL;
   temp->lchild=NULL;temp->parent=NULL;
   printf ("\n enter value \n");
   
if (type==0)
   { temp->value=(int*)malloc(sizeof(int));
    *(int*)(temp->value)=inputi();
    }

if (type==1)
{ da0=scanf("%f",&da1);getchar();
while(da0!=1) 
{printf("prepei na einai ari8mos\n");
da0=scanf(" %f",&da1);
while((r = getchar()) != '\n');
}
     temp->value=(float*)malloc(sizeof(float));
    *(float*)(temp->value)=da1;
    }

if (type==2)
{ 
da0=scanf("%lf",&da2);getchar();
while(da0!=1) 
{printf("prepei na einai ari8mos\n");
da0=scanf(" %lf",&da2);while((r = getchar()) != '\n');
}

    temp->value=(double*)malloc(sizeof(double));
    *(double*)(temp->value)=da2;
    }

if (type==3)
   { 
    
    temp->value=(char*)malloc(sizeof(char));
    *(char*)(temp->value)=inputc();
    }

   insertfix(temp,type);
}

void do_delete(int type)
{int r,da0;float da1;double da2;char da3;void *temp;
printf("\n enter value \n");


if (type==0)
   { temp=(int*)malloc(sizeof(int));
    *(int*)(temp)=inputi();
    }

if (type==1)
{ da0=scanf("%f",&da1);getchar();
while(da0!=1) 
{printf("prepei na einai ari8mos\n");
da0=scanf(" %f",&da1);
while((r = getchar()) != '\n');
}
     temp=(float*)malloc(sizeof(float));
    *(float*)(temp)=da1;
    }

if (type==2)
{ 
da0=scanf("%lf",&da2);getchar();
while(da0!=1) 
{printf("prepei na einai ari8mos\n");
da0=scanf(" %lf",&da2);while((r = getchar()) != '\n');
}

    temp=(double*)malloc(sizeof(double));
    *(double*)(temp)=da2;
    }

if (type==3)
   { 
    
    temp=(char*)malloc(sizeof(char));
    *(char*)(temp)=inputc();
    }



delete(search(temp,root,type));

}

void do_print(int type)
{
if (root==NULL){printf("\n Empty\n\n");}
    else {print(root,type);}
}


