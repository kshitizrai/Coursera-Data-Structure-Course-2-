#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	char ch;
	struct Node *next;
};

void printList(struct Node *top_ref)
{
	if(top_ref == NULL)
	{
		printf("\n Stack is empty ");
		return;
	}

	while(top_ref!=NULL)
	{
		printf("%c",top_ref->ch);
		top_ref = top_ref->next;
	}
	return;
}

void push(struct Node **head_ref , char ch)
{
	struct Node *new_Node = (struct Node*)(malloc(sizeof(struct Node)));

	new_Node->ch = ch ;

	if(*head_ref != NULL)
		new_Node->next = *head_ref;

	*head_ref = new_Node;
}

bool empty(struct Node *head_ref) 
{
	if(head_ref == NULL)
		return(1);
	else
		return(0);
}

char pop(struct Node **head_ref )
{
	char ch = (*head_ref)->ch;

	if(*head_ref != NULL)
		*head_ref = (*head_ref)->next;

	return(ch);
}

int main(void)
{
	struct Node *top = (struct Node*)(malloc(sizeof(struct Node)));

	top = NULL ;

	char c=getchar();
	char ontop;

	bool ans = 1;
	while(c != '\n')
	{
		if(c == '(' || c == '[')
			push(&top,c);
		else
		{
			if(empty(top) == 1)
				ans = 0;

			ontop = pop(&top);
			if((ontop == '[' && c != ']') || (ontop == '(' && c!=')'))
				ans = 0;
		}
		c = getchar();	
	}

	if(empty(top) == 1)
		printf("Balanced  \n");
	else
		printf("Not Balanced \n");
}