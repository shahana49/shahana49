#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,max;
int queue[100];
void enqueue()
{
	int item;
	printf("\n enter the element");
	scanf("\n %d",&item);
	if(rear==max-1)
	{
		printf("\n overflow\n");
		return;
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear=rear+1;
	}
	queue[rear]=item;
	printf("\n value inserted");
}
void dequeue()
{	
	int item;
	if(front==-1||front>rear)
	{
		printf("\n under flow \n");
		return;
	}
	else
	{
		item=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
		printf("element deleted");
	}
}
void display()
{
	int i;
	if(rear==-1)
	{
		printf("empty queue");
	}
	else
	{
		printf("element in the queue are:");
		for(i=front;i<=rear;i++)
		{
			printf("\n%d",queue[i]);
		}
	}
}
int main()
{
	int choice;
	printf("\n enter the size of queue:");
	scanf("%d",&max);
	printf("queue operation using array");
	printf("\n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit");
	while(choice!=4)
	{
		printf("\n enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				enqueue();
				break;
			}
			case 2:
			{
				dequeue();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4:
			{
				printf("exited");
				break;
			}
			default:
				printf("enter valid choice");
		}
	}
	return;
}
			



		
