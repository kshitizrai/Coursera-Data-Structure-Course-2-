#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	void *elem11=(void *)malloc(sizeof(int));
	int *elem12 = (int *)malloc(sizeof(int));
	*elem12 = 1;
	memcpy(elem11,(void *)elem12 , sizeof(int));

	void *elem21=(void *)malloc(sizeof(int));
	int *elem22 = (int *)malloc(sizeof(int));
	*elem22 = 9;
	memcpy(elem21,(void *)elem22 , sizeof(int));

	int x = memcmp(elem11,elem21,sizeof(int));
	printf("%d\n",x);
}