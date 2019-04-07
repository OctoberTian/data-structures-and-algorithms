#include <stdio.h>
#include <stdlib.h>
/*
线性表的链表在各节点在逻辑上是相连的，在物理上是不连的，而基于数组的线性表都是相连的
*/
typedef struct LNode
{
	int Data;
	struct LNode *Next;
}LNode;

//打印链表
void PrintNodes(LNode first[])
{
	LNode *point = first;
	while(point)
	{
		printf("%d ", point->Data);
		point = point->Next;
	}
	printf("\n");
	return;
}

//通过一个数组初始化一个链表
LNode *Init(int myList[], int len)
{
	LNode *point;
	LNode *first = (struct LNode*)malloc(sizeof(LNode));
	int i = 0;
	if(sizeof(myList) < 1)
	{
		printf("数组为空,无法初始化！");
	}
	for(i = 0; i < len; i++)
	{
		if(i == 0)
		{
			first->Data = myList[0];
			first->Next = (struct LNode*)malloc(sizeof(LNode));
			point = first->Next;;
		}
		else if(i == len-1)
		{
			point->Data = myList[i];
			point->Next = NULL;
		}
		else
		{
			point->Data = myList[i];
			point->Next = (struct LNode*)malloc(sizeof(LNode));
			point = point->Next;
		}
	}
	return first;
}

int Length(LNode *first)
{
	int len = 0;
	LNode *point = first;
	while(point)
	{
		len++;
		point = point->Next;
	}
	return len;
}

//按照位置查询结果
LNode *FindByPos(int Pos, LNode *first)
{
	LNode *point = first;
	int i = 1;
	if(Pos < 1 || Pos > Length(first))
	{
		printf("查询位置不合法！\n");
		return NULL;
	}
	while(i != Pos)
	{
		point = point->Next;
		i++;
	}
	return point;
}

//按照值查找
LNode *FindByVal(int Val, LNode *first)
{
	LNode *point = first;
	while(point != NULL && point->Data != Val)
	{
		point = point->Next;
	}
	return point;
}

//插入节点,插在指定位置之后
void Insert(int Pos, int Val, LNode *first)
{
	LNode *myNode = (struct LNode*)malloc(sizeof(LNode));
	myNode->Data = Val;
	LNode *posPoint = FindByPos(Pos, first);
	if(Pos == Length(first))
	{
		posPoint->Next = myNode;
		myNode->Next = NULL;
	}
	else
	{
		LNode *posPlusPoint = FindByPos(Pos+1, first);
		myNode->Next = posPlusPoint;
		posPoint->Next = myNode;
	}
	return;
}

LNode *Delete(int Pos, LNode *first)
{
	LNode *posNode = FindByPos(Pos, first);
	if(Length(first) == 1)
	{
		free(posNode);
		return NULL;
	}

	if(Pos == 1)
	{
		LNode *nowNode = first->Next;
		free(posNode);
		return nowNode;
	}

	if(Pos == Length(first))
	{
		LNode *beforeNode = FindByPos(Pos-1, first);
		beforeNode->Next = NULL;
		free(posNode);
		return first;
	}

	LNode *beforeNode = FindByPos(Pos-1, first);
	LNode *nextNode = posNode->Next;
	beforeNode->Next = nextNode;
	free(posNode);
	return first;
}

int main()
{
	int myList[7] = {1, 2, 3, 4, 5, 6, 7};
	int len = sizeof(myList)/sizeof(myList[0]);
	LNode *first = Init(myList, len);
	PrintNodes(first);
	printf("长度为：%d\n", Length(first));
	Insert(3, 100, first);
	LNode *myNode = FindByPos(8, first);
	printf("%d\n", myNode->Data);
	PrintNodes(first);
	LNode *nowNode = Delete(4, first);
	PrintNodes(nowNode);
    return 0;
}
