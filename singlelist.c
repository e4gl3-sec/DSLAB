#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node *ptr,*head=NULL,*temp,*new,*prev;

void insertfront(int item)
{
	new=(struct node *)malloc(sizeof(struct node));
	new->data=item;
	new->link=head;
	head=new;

}
void insertback(int item)
{
	new=(struct node *)malloc(sizeof(struct node));
	new->data=item;
	new->link=NULL;
	if (head==NULL)
	{
		head=new;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new;
	}
}

void insertspec(int item,int key)
{
	if(head==NULL)
	{
		printf("\nINSERTION NOT POSSIBLE\n");
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL && ptr->data!=key)
		{
			ptr=ptr->link;
		}
		if(ptr->link==NULL)
		{
			printf("\nElement not found insertion not possible\n");
		}
		else
		{
			new=(struct node *)malloc(sizeof(struct node));
			new->data=item;
			new->link=ptr->link;
			ptr->link=new;

		}
	}
}

void deletefront()
{
	if(head==NULL)
	{
		printf("\nThe list is empty\n");
	}
	else
	{
		temp=head;
		head=head->link;
		free(temp);
	}
}

void deleteend()
{
	if(head==NULL)
	{
		printf("\nThe list is empty\n");

	}
	else if(head->link==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}	
	else
	{   
		ptr=head;
		prev=ptr;
		while(ptr->link!=NULL)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		prev->link=NULL;
		free(ptr);

	}
}

void deletespec(int key)
{
	if(head==NULL)
	{
		printf("\nThe list is empty\n");
	}
	else if(head->data==key)
	{
		temp=head;
		head=head->link;
		free(temp);
	}
	else
	{
		ptr=head;
		prev=ptr;
		while(ptr->data!=key && ptr->link!=NULL)
		{
			prev=ptr;
			ptr=ptr->link;
		}
		if(ptr->data!=key)
		{
			printf("\nElement not found\n");
		}
		else
		{
			temp=ptr;
			prev->link=ptr->link;
			free(ptr);
		}
	}

}


void display()
{
	if(head==NULL)
	{
		printf("\nThe list is empty");
	}
	else
	{ 
		ptr=head;
		printf("\nThe elements of the list are\n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	}
}

void main()
{
	int item,ch,key;
	do
	{
		printf("\nEnter the options\n1]insertfront\n2]insertback\n3]insert at specific node\n4]deletefront\n5]deleteend\n6]delete at a specific node\n7]dispaly\n8]quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("\nEnter the element\n");
        	scanf("%d",&item);
        	insertfront(item);
        	break;
        case 2:printf("\nEnter the element\n");
        	scanf("%d",&item);
        	insertback(item);
        	break;
        case 3:printf("\nEnter the element\n");
        	scanf("%d",&item);
        	printf("\nEnter the key\n");
        	scanf("%d",&key);
        	insertspec(item,key);
            break;
         case 4:deletefront();
         	break;
         case 5:deleteend();
         	break;
         case 6:printf("\nEnter the key\n");
        	scanf("%d",&key);
        	deletespec(key);
        	break;
        case 7:display();
        	break;
        case 8:printf("Exiting operation");
        	break;
        default:printf("\nEnter valid option\n");
        	break;
        }
    }while(ch!=8);
        
	
}




