#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}linklist;
typedef struct LNode * PList;
typedef struct LNode List;

int main()
{
	linklist *new_list;
	PList p;

	printf("Check\n");
	p->data = 6;


	printf("p:%p, *p:%x\n",
		p, *p);

	printf("new_list:%p, *new_list:%p; p:%p, *p:%p\n",
		new_list, (void *)new_list, p, (void *)p);
	
	return 0;
}
