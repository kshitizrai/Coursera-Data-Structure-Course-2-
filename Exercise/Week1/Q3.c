#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue
{
	int front , capacity , rear ,size;
	int *array;
};

bool isFull(struct Queue *queue)
{
	return(queue->size == queue->capacity);
}

bool isEmpty(struct Queue *queue)
{
	return(queue->size == 0);
}

struct Queue* createQueue(int capacity)
{
	struct Queue *queue = (struct Queue*)(malloc(sizeof(struct Queue)));

	queue->front = 0;
	queue->size = 0;
	queue->capacity=capacity;
	queue->rear = queue->capacity - 1;
	queue->array = (int *)(malloc(sizeof(int)*queue->capacity));
	return(queue);
}

void enqueue(struct Queue *queue , int item)
{
	if(isFull(queue))
		return;

	queue->rear = (queue->rear+1)%queue->capacity;
	queue->size = queue->size + 1;
	(queue->array)[queue->rear] = item;
	return;
}

void pop(struct Queue *queue)
{
	if(isEmpty(queue))
		return ;

	queue->front = (queue->front+1)%queue->capacity;
	queue->size = queue->size-1;
}

int dequeue(struct Queue *queue)
{
	if(isEmpty(queue))
		return (INT_MIN);

	int item = queue->array[queue->rear];
	return(item);
}

int dequeuef(struct Queue *queue)
{
	if(isEmpty(queue))
		return (INT_MIN);

	int item = queue->array[queue->front];
	return(item);
}

void printQueue(struct Queue *queue)
{
	printf("Front = %d\n",queue->front);
	printf("Size = %d\n",queue->size);
	printf("Rear = %d\n",queue->rear);
	printf("Capacity = %d\n",queue->capacity);
}


int main(void)
{
	int buffer,st1,pr1,st2,pr2,i,x,y,prst;
	scanf("%d",&buffer);
	int packets;
	scanf("%d",&packets);
	
	struct Queue *queue = createQueue(buffer);
	int *ans = (int *)(malloc(sizeof(int)*(packets)));

	if(packets == 0)
		return 0;

	scanf("%d",&st1);
	scanf("%d",&pr1);

	x = st1+pr1;
	*(ans) = st1;
	enqueue(queue,x);
	prst=st1;

	for(i=1 ; i<packets ; i++)
	{
//		printQueue(queue);

		scanf("%d",&st2);
		scanf("%d",&pr2);
		y = st2 + pr2;
		x = dequeue(queue);
		prst = st2;
		if(prst<st2)
		{
			pop(queue);
		}
		if(st2>=dequeuef(queue))
		{
			pop(queue);
		}	

		if(st2>=x)
		{
			pop(queue);
			enqueue(queue,y);
			ans[i] = st2;
		}
		else
		{

			if(isFull(queue))
				{
					ans[i]=-1;
				}
			else
				{
					enqueue(queue,x+pr2);
					ans[i] = x;
				}
		}
	//	printQueue(queue);
	//	printf("\n");
	}

	for(i=0 ; i<packets ; i++)
	{
		printf("%d\n",*(ans+i));
	}
}