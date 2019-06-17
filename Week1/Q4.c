#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

int max = 0;

void get_max(struct Node *head_ref)
{
	max = INT_MIN;
	while(head_ref != NULL)
	{
		if(head_ref->data > max)
			max = head_ref->data;
		head_ref = head_ref->next;;
	}
}

void push(struct Node **head,int data)
{
	struct Node *newNode = (struct Node*)(malloc(sizeof(struct Node)));
	newNode->next = *head;
	*head = newNode;
	if(max<data)
	{
		newNode->data = (2*data)+max;
		max = data;
	}
	else
		newNode->data = data;
}

void pop(struct Node **head)
{
	if(*head == NULL)
		return;
	struct Node *head_ref = *head;
	(*head) = (*head)->next;
	if(head_ref->data > max)
	{
		max = ((head_ref->data)-(2*max));
	}
	free(head_ref);
}

int main()
{
	int size,data;
	struct Node *head = NULL;
	struct Node *head_max = NULL;
	scanf("%d",&size);
	char *ptr = (char *) malloc(sizeof(char));
	getchar();

	int *print = (int *)malloc(sizeof(int)*size);
	int count = 0;

	for(int i=0 ; i<size ; i++)
	{
		char *array = (char *)malloc(sizeof(char));
		int size=0;
		scanf("%c",ptr);
		int flag = 0;
		
		while(*ptr != '\n')
		{
			*(char *)(array+size) = *ptr;
			if(size == 1)
			{
				switch (*ptr)
				{
					case 'u':	flag = 1;
								break;
					case 'o':	pop(&head);
								break;
					case 'a':	print[count++] = max;
								break;
				}
			} 
			size++;
			if(flag == 1)
			{
				while(*ptr != ' ')
				{
					array = realloc(array,size);
					scanf("%c",ptr);
				}
				scanf("%d",&data);
				scanf("%c",ptr);
				break;
			}
			array = realloc(array,size);
			scanf("%c",ptr);
		}
		if(flag==1)
		{
			push(&head,data);
		}
	}
	
	for(int i=0 ; i<count ; i++)
	{
		printf("%d\n",(print[i]));
	}
}