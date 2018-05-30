#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data ;
	struct Node *next;
};

void push(struct Node **head_ref , int new_data)
{
	struct Node *new_Node = (struct Node*)(malloc(sizeof(struct Node)));

	new_Node->data = new_data ;

	if(*head_ref != NULL)
		new_Node->next = *head_ref;

	*head_ref = new_Node;
}

int pop(struct Node **head_ref)
{
	int ch;

	if(*head_ref == NULL)
		return(0);
	else
	{
		ch = (*head_ref)->data;
		*head_ref = (*head_ref)->next;
		return(ch);
	}	
}

bool empty(struct Node *head_ref)
{
	if(head_ref == NULL)
		return(1);
	else
		return(0);
}

int main(void)
{
	struct Node *top = (struct Node*)(malloc(sizeof(struct Node)));
	struct Node *index = (struct Node*)(malloc(sizeof(struct Node)));

	top = NULL;
	index = NULL;
	int ans;
	bool check = 1;
	int position = 0;
	char input = getchar() , ontop;

	while(input != '\n')
	{
		position = position + 1;
		ans=position;
	//	printf("ans=%d\n",ans);
		if(input == '(' || input == '[' || input == '{')
		{
			push(&top,input);
			push(&index,position);
		}
		
		if(input == ')' || input == ']' || input == '}')
		{
			if(empty(top)==1)
			{
				check = 0;
				ans = position;
				break;
			}
			ontop = pop(&top);
			if((ontop=='['&&input!=']')||(ontop=='('&&input!=')')||(ontop=='{'&&input!='}'))
				{
					ans = position;
					check = 0;
					break;
				}
			else
			{
				int x = pop(&index);
			}

		}
		input = getchar();
	}
	if(empty(top) && check != 0)
		printf("Success\n");
	if(check == 0)
		printf("%d\n",ans);
	if(check != 0 && (empty(top)==0))
		printf("%d\n",pop(&index));
}