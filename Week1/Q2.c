#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

struct Node 
{
	int data;
	struct Linked_List *head;
};

struct Linked_List
{
	struct Node *data;
	struct Linked_List *next;	
};

void create_Node(struct Node *head,int info)
{
	struct Node *head_ref = head;

	head_ref->data = info;
	head_ref->head = NULL;
}

void add_element(struct Linked_List **head, struct Node *addition)
{
	struct Linked_List *newNode = (struct Linked_List*)(malloc(sizeof(struct Linked_List)));
	newNode->data = addition;
	newNode->next = NULL;

	if(*head == NULL)
	{
		*head = newNode;
		return;
	}

	struct Linked_List *temp = (*head)->next;
	(*head)->next = newNode;
	newNode->next = temp;
}

int commute_height(struct Node *root)
{
//	printf("root = %d \n ",root->data);
	if(root == NULL)
		return(0);
	if(root->head == NULL)
		return(1);
	int height_prev = INT_MIN;
	int height_new;

	while(root->head != NULL)
	{
		height_new = 1+commute_height((root->head)->data);
	//	printf("height = %d\n",height_new);
		if(height_new>height_prev)
		{
			height_prev = height_new;
		}
		root->head = (root->head)->next;
	}
	return(height_prev);
}

int main()
{
	int size,read,root;
	scanf("%d",&size);

	struct Node *array = (struct Node*)(malloc(sizeof(struct Node)*size));
	for(int i=0 ; i<size ; i++)
	{
		create_Node((array+i),i);
	}
	for(int i=0 ; i<size ; i++)
	{
		scanf("%d",&read);
		if(read == -1)
			root = i;
		else
		{
			add_element(&((array+read)->head),(array+i));
		}
	}

/*	for(int i=0 ; i<size ; i++)
	{
		printf("Child of %d are ->",i);
		while((array+i)->head!=NULL)
		{
			printf("%d ",(((array+i)->head)->data)->data);
			(array+i)->head = ((array+i)->head)->next;
		}
		printf("\n");
	}
*/
	int height = commute_height((array+root));
	printf("%d\n",height);
}