#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
} linklist;
typedef struct LNode * PList;
typedef struct LNode List;

//创建一个链表
PList Create(int length)
{
	PList head = NULL;
	PList p1 = NULL;
	PList p2 = NULL;
	for (int i = 0; i < length; i++)
	{
		p1 = (PList)malloc(sizeof(List));
		if (head == NULL)//如果表没有头的话
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;//将前一项的下一项指定为当前项
			p2 = p1;//将p2指向目前p1所开辟的内存空间里
		}
		p2->next = NULL;
	}
	return head;
}
int Length(PList PtrL)
{
	PList p = PtrL;//p指向表的第一个节点
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}
//按序号查找
PList FindKth(int K, PList PtrL)
{
	PList p = PtrL;
	int i = 1;
	while (p != NULL && i < K)
	{
		p = p->next;
		i++;
	}
	if (i == K) return p;
	else return NULL;
}
//按值查找
PList Find(int X, PList PtrL)
{
	PList p = PtrL;
	while (p->data != X && p != NULL)
	{
		p = p->next;
	}
	if (p == NULL) return NULL;//破坏循环条件为p到了链表尾端，那么说明没找到
	else return p;
}
//插入
PList Insert(int X, int i, PList PtrL)
{
	PList previous, insert_one;
	//新节点插入在表头
	if (i == 1)
	{
		insert_one = (PList)malloc(sizeof(struct LNode));
		insert_one->data = X;
		insert_one->next = PtrL;
		return insert_one;
	}
	//插入链表中段
	previous = FindKth(i - 1, PtrL);//首先找到插入的前一个位置
	if (previous == NULL)//如果找不到前一个位置，那么说明不可插入
	{
		printf("Error:arguement is illegal!");
		return NULL;
	}
	else
	{
		insert_one = (PList)malloc(sizeof(struct LNode));//因为要插入，所以要先申请一块内存空间
		insert_one->next = previous->next;//将插入节点的next指向变为和前一个指针一样的指向
		previous->next = insert_one;//将前一个节点的指向变成插入节点
		insert_one->data = X;//将数据赋值
		return PtrL;//链表首地址未发生变化，因此原样
	}
}
//删除第i个节点，注意要释放被删除节点的内存空间
PList Delete(int i, PList PtrL)
{
	PList previous, target_node;
	//删除首地址
	if (i == 1)
	{
		target_node = PtrL;
		if (PtrL != NULL) PtrL = PtrL->next;//将后一个节点赋值给PtrL的首地址
		else return NULL;
		free(target_node);//释放一块内存空间
		return PtrL;
	}
	//删除中段地址
	previous = FindKth(i - 1, PtrL);
	if (previous == NULL)
	{
		printf("Error:%d node is not exist", i - 1);
		return NULL;
	}
	else if (previous->next == NULL)
	{
		printf("Error:%d node is not exist", i);
		return NULL;
	}
	else
	{
		target_node = previous->next;
		previous->next = target_node->next;
		free(target_node);
		return PtrL;
	}
}
int main()
{
	PList new_list = Create(1);
	int length = Length(new_list);
	printf("Init link list length: %d\n", length);
	printf("new_list:%p, new_list:%p, new_list->data:0x%x, new_list->next:%p\n",
		new_list, (void *)new_list, new_list->data, new_list->next);
	Insert(222, 1, new_list);
	Insert(12, 2, new_list);
	length = Length(new_list);
	printf("\nAfter insert, link list length: %d\n", length);
	printf("new_list:%p, new_list:%p\n",
		new_list, (void *)new_list);
	printf("new_list->data:%d,new_list->next:%p, new_list->next->data:0x%x\n",
		new_list->data, new_list->next, new_list->next->data);
	return 0;
}
