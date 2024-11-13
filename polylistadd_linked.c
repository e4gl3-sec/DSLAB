#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coeff;
	int expo;
	struct node *link;
};
struct node *ptr,*head=NULL,*temp,*new,*prev,*phead=NULL,*qhead=NULL,*rhead=NULL,*p,*q,*r;

void insertelement(struct node **head,int item,int exp)
{
	new=(struct node *)malloc(sizeof(struct node));
	new->coeff=item;
	new->expo=exp;
	if (*head==NULL)
	{
		*head=new;
	}
	else
	{
		ptr=*head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
	}
}

void add(struct node **qhead,struct node **phead)
{
	p=*phead;
	q=*qhead;


	while(p!=NULL&&q!=NULL)
	{
		new=(struct node *)malloc(sizeof(struct node));
		if(p->expo==q->expo)
		{
			new->coeff=p->coeff+q->coeff;
			new->expo=p->expo;
			new->link=NULL;
			p=p->link;
			q=q->link;
			if(rhead==NULL)
			{
				r=rhead=new;
			}
			else
			{
				r=rhead;
				while(r->link!=NULL)
				{
					r=r->link;
				}
				r->link=new;
				r=new;
			}
		}
		else if(p->expo>q->expo)
		{
			new->coeff=p->coeff;
			new->expo=p->expo;
			new->link=NULL;
			p=p->link;
			if(rhead==NULL)
			{
				r=rhead=new;
			}
			else
			{
				r=rhead;
				while(r->link!=NULL)
				{
					r=r->link;
				}
				r->link=new;
				r=new;
			}
		}
		else 
		{
			new->coeff=q->coeff;
			new->expo=q->expo;
			new->link=NULL;
			q=q->link;
			if(rhead==NULL)
			{
				r=rhead=new;
			}
			else
			{
				r=rhead;
				while(r->link!=NULL)
				{
					r=r->link;
				}
				r->link=new;
				r=new;
			}
		}

	}
	while(p!=NULL)
	{
			new=(struct node *)malloc(sizeof(struct node));
		    new->coeff=p->coeff;
		    new->expo=p->expo;
			new->link=NULL;
			p=p->link;
			if(rhead==NULL)
			{
				r=rhead=new;
			}
			else
			{
				r=rhead;
				while(r->link!=NULL)
				{
					r=r->link;
				}
				r->link=new;
				r=new;
			}
	}
	while(q!=NULL)
	{
			new=(struct node *)malloc(sizeof(struct node));
		    new->coeff=q->coeff;
		    new->expo=q->expo;
			new->link=NULL;
			q=q->link;
			if(rhead==NULL)
			{
				r=rhead=new;
			}
			else
			{
				r=rhead;
				while(r->link!=NULL)
				{
					r=r->link;
				}
				r->link=new;
				r=new;
			}
	}
}

void display(struct node **head)
{
	if(*head==NULL)
	{
		printf("\nThe polynomial is empty\n");
	}
	else
	{ 
		ptr=*head;
		
		while(ptr!=NULL)
		{
			printf("%d(x)^%d",ptr->coeff,ptr->expo);
			if(ptr->link!=NULL)
			{
				printf("+");
			}
			ptr=ptr->link;
			
		}
	}
}

void main()
{
	int item,exp,n1,n2,i;
	printf("\nEnter the terms for the first polynomial\n");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("\nEnter coefficient for first polynomial and the respective exponent in descending order\n");
		scanf("%d,%d",&item,&exp);
		insertelement(&phead,item,exp);
		printf("\nThe terms for the first polynomial\n");
		display(&phead);
	}
	printf("\nEnter the terms for the second polynomial\n");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		printf("\nEnter coefficient for second polynomial and the respective exponent in descending order\n");
		scanf("%d,%d",&item,&exp);
		insertelement(&qhead,item,exp);
		printf("\nThe terms for the second polynomial\n");
		display(&qhead);
	}
	add(&phead,&qhead);
	printf("\nResultant polynomial\n");
	printf("\nThe terms for the Resultant polynomial\n");
	display(&rhead);
}





