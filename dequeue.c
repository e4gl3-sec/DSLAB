#include<stdio.h>
 

int A[10],i,front=-1,rear=-1; 
void inject(int size,int item)
{
	if(rear==size-1)
	{
		printf("\nThe queue is full\n");
	}
	else if(rear==-1&&front==-1)
	{
		rear=0;
		front=0;
		A[rear]=item;
    }
    else
    {
    	rear++;
    	A[rear]=item;
    }
}

void eject(int size)
{
	if(front==-1&&rear==-1)
	{
		printf("\nThe queue is empty\n");
	}
	else if(front==rear)
	{
		printf("\nThe element deleted is %d \n",A[rear] );
		front=rear=-1;
	}
	else
	{
		printf("\nThe element deleted is %d\n",A[rear]);
		rear--;
	}

}

void push(int size,int item)
{
	if(rear==size-1)
	{
		printf("\nThe queue is full\n");
	}
	else if(rear==-1&&front==-1)
	{
		rear=0;
		front=0;
		A[front]=item;
    }
    else if(front>0)
    {
    	front=front-1;
    	A[front]=item;
    }
    else
    {
    	for(i=rear;i>=0;i--)
    	{
    		A[i+1]=A[i];
    		
    	}
    	A[front]=item;
    	rear++;
    }
}

void pop(int size)
{
	if(front==-1)
	{
		printf("\nThe queue is empty\n");
	}
	else if(front==rear)
	{
		printf("\nThe element deleted is %d \n",A[front] );
		front=rear=-1;
	}
	else
	{
		printf("\nThe element deleted is %d\n",A[front]);
		front++;
	}

}



void display(int size)
{
	if(front==-1)
	{
		printf("\nThe queue is empty\n");
	}
	else
	{
		printf("\nThe elements in the queue is\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d ",A[i]);
		}
	}

}
void main()
{

	int size,ch,item;
	printf("\nEnter the size of the Queue\n");
	scanf("%d",&size);
    do
    {
     printf("\nEnter your choice \n1]INJECT element\n2]EJECT element\n3]PUSH element \n 4]POP element\n5]DISPLAY element\n6]QUIT\n");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:printf("\nEnter the element to be inserted\n");
     	    scanf("%d",&item);
     	    inject(size,item);
     	    break;
     case 2:eject(size);
     		break;
     case 3:printf("\nEnter the element to be inserted\n");
     	    scanf("%d",&item);
     	    push(size,item);
     	    break;
     case 4:pop(size);
     		break;
     case 5:display(size);	
     		break;
     case 6:printf("Exiting queue operations");
     	break;
     default:printf("\nEnter valid option!!!\n" );
     			break;
     }    
     }while(ch!=6);
}
