#include<stdio.h>
int queue[100];
int front=-1;
int rear = -1;
int max;
void enqueue(int item)
{
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=item;
	}
	else if((rear+1)%max==front)
	{
		printf("queue is overflow");
	}
	else
	{
		rear=(rear+1)%max;
		queue[rear]=item;
	}
	
}
int dequeue()
{
	if(front==-1 && rear ==-1)
	{
		printf("queue is underflow");
	}
	else if(front == rear)
	{
		printf("dequeued element is  %d",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{	
		printf("\ndequeued element is  %d",queue[front]);
		front=(front+1)%max;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("\nqueue is empty");
	}
	else
	{
		printf("\nelement i the queue are: \n");

		for(i=front;i!=rear;i=(i+1)%max)
		{
			printf("%d",queue[i]);
		}printf("%d",queue[rear]);

	}
}
int main()
{
	int choice=1,n;
	printf("enter the size of the queue" );
	scanf("%d",&max);
	while(choice<4&&choice!=0)
	{	
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("enter the element to be inserted: ");
				scanf("%d",&n);
				enqueue(n);
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
		}
	}
}
