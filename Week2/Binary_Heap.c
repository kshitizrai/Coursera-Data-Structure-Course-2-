#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h> 

struct heap
{
	int size;
	int capacity;
	int elem_size;
	void *array ;
};

struct heap *create_heap(int capacity , int elem_size)
{
	struct heap *newHeap = (struct heap*)(malloc(sizeof(struct heap)));

	newHeap->size = 0;
	newHeap->elem_size = elem_size;
	newHeap->capacity = capacity;
	newHeap->array = malloc(capacity*elem_size);
}

int parent(int i)
{
	return((i-1)/2);
}

int right_child(int i)
{
	return(2*i+2);
}

int left_child(int i)
{
	return(2*i+1);
}

void print(struct heap *heap_array)
{
	for(int i=0 ; i<heap_array->size ; i++)
	{
		void *target =  (char*)(heap_array->array)+i*heap_array->elem_size;
		printf("%d ", *(int *)target);
	}
	printf("\n");
}

void swap(void *vp1 , void *vp2 , int elem_size)
{
	char temp[elem_size] ;
	memcpy(temp,vp1,elem_size);
	memcpy(vp1,vp2,elem_size);
	memcpy(vp2,temp,elem_size);
}

void siftUp(struct heap *heap_array , void *target)
{
	int i = heap_array->size-1;

	while(i!=0)
	{
		i = parent(i);
		void *parent = (char *)(heap_array->array) + i*heap_array->elem_size;
		if(memcmp(target,parent,heap_array->elem_size) > 0)
		{
			swap(target,parent,heap_array->elem_size);
			target = parent;
		}
	}
}

void siftDown(struct heap *heap_array , void *target)
{
	int i = 0;

	while(1)
	{
		int r = right_child(i);
		int l = left_child(i);

		void *smallest = (void *)(malloc(heap_array->elem_size));
		void *right = (char *)(heap_array->array) + r*heap_array->elem_size;
		void *left = (char *)(heap_array->array) + l*heap_array->elem_size;

		if(r<heap_array->size)
		{
			smallest = right;
			i=r;
		}
		else
			*(int *)smallest = INT_MIN;

		if((memcmp(target,right,heap_array->elem_size)>= 0||r>=heap_array->size)&&(memcmp(target,left,heap_array->elem_size)>= 0)||r>=heap_array->size)
		{
			break;
		}

		if(memcmp(smallest,left,heap_array->elem_size) < 0 && l<heap_array->size)
		{
			smallest = left;
			i = l;
		}

		swap(target,smallest,heap_array->elem_size);
		target = smallest;
	}
}

void insert_key(struct heap *heap_array , void *elem_addr)
{
	if(heap_array->size == heap_array->capacity)
	{
		printf("Heap is Full\n");
		return;
	}

	void *target = (char*)(heap_array->array) + (heap_array->size)*(heap_array->elem_size);
	memcpy(target,elem_addr,heap_array->elem_size);
	heap_array->size++; 
}

void *Extract_Max(struct heap *heap_array)
{
	void *root = (char *)heap_array->array;
	void *leaf = (char *)heap_array->array + (heap_array->size-1)*heap_array->elem_size;

	swap(root , leaf , heap_array->elem_size);
	heap_array->size = heap_array->size-1;
	siftDown(heap_array,root);
	return(leaf);
}

int main()
{
	struct heap *heap_array = create_heap(10,sizeof(int));
	int *elem = (int *)(malloc(sizeof(int)));
	*elem = 10;
	insert_key(heap_array,(void *)elem);
	*elem = 20;
	insert_key(heap_array,(void *)elem);
	*elem = 30;
	insert_key(heap_array,(void *)elem);
	*elem = 40;
	insert_key(heap_array,(void *)elem);
	*elem = 50;
	insert_key(heap_array,(void *)elem);
	*elem = 60;
	insert_key(heap_array,(void *)elem);
	*elem = 70;
	insert_key(heap_array,(void *)elem);
	*elem = 80;
	insert_key(heap_array,(void *)elem);
	*elem = 90;
	insert_key(heap_array,(void *)elem);
	*elem = 100;
	insert_key(heap_array,(void *)elem);
	print(heap_array);
	printf("Max = %d \n",*(int *)Extract_Max(heap_array));
	printf("Max = %d \n",*(int *)Extract_Max(heap_array));
	printf("Max = %d \n",*(int *)Extract_Max(heap_array));
	print(heap_array);
	insert_key(heap_array,(void *)elem);
	*elem = 80;
	insert_key(heap_array,(void *)elem);
	*elem = 90;
	insert_key(heap_array,(void *)elem);
	*elem = 100;
	print(heap_array);
}