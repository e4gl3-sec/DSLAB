#include<stdio.h>

int front=-1,rear=-1,i,loc;

struct pri
{
	int priority;
	int item;
}A[10];

void enqueue(int size,int item,int prio)
{
  if(front==0&&rear==size-1)
  {
  	printf("\nThe queue is full\n");
  }
  else if(front==-1&&rear==-1)
  {
  	front=0;
  	rear=0;
  	A[rear].item=item;
  	A[rear].priority=prio;
  }
  else if(rear==size-1)
  {
  	for(i=front;i<=rear;i++)
  	{
  		A[i-1]=A[i];
      front--;
      rear--;
  	}
  	for(i=rear;i>=front;i--)
  	{
  		if(A[i].priority<prio)
  		{
  			loc=i+1;
  			break;
  		}
	}
  	for(i=rear;i>=loc;i--)
  	{
       A[i+1]=A[i];
  	}
  	A[loc].item=item;
  	A[loc].priority=prio;
  	rear++;
  }

  else
  {
  	for(i=front;i<=rear;i++)
  	{
  		if(A[i].priority<prio)
  		{
  			loc=i+1;
  			break;
  		}
	}
  	for(i=rear;i>=loc;i--)
  	{
       A[i+1]=A[i];
  	}
  	A[loc].item=item;
  	A[loc].priority=prio;
  	rear++;
   }

  }

void dequeue(int size)
{
	if(front==0&&rear==size-1)
  		{
  		printf("\nThe queue is empty\n");
  		}
  	else if(front==rear)
  	{
  		printf("\nThe item deleted is %d and its priority is %d\n",A[rear].item,A[rear].priority);
  		front=-1;
  		rear=-1;
  	}
  	else
  	{
  		printf("\nThe item deleted is %d and its priority is %d\n",A[front].item,A[front].priority);
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
		printf("\nThe elements and their priority in the queue is\n");
		for(i=front;i<=rear;i++)
		{
			printf("\nItem is %d ,priority is %d \n",A[i].item,A[i].priority);
		}
	}

}

void main()
{

	int size,ch,item,prio;
	printf("\nEnter the size of the Queue\n");
	scanf("%d",&size);
    do
    {
     printf("\nEnter your choice \n1]Priority Queue Element insertion\n2]Priority Queue Element Deletion\n3]Priority Queue Elements Display \n 4]Quit\n");
     scanf("%d",&ch);
     switch(ch)
     {
     case 1:printf("\nEnter the element to be inserted\n");
     	    scanf("%d",&item);
     	    printf("\nEnter the priority of the element\n");
     	    scanf("%d",&prio);
     	    enqueue(size,item,prio);
     	    break;
     case 2:dequeue(size);
     		break;
     case 3:display(size);	
     		break;
     case 4:printf("Exiting queue operations");
     	break;
     default:printf("\nEnter valid option!!!\n" );
     			break;
     }    
     }while(ch!=4);
}



