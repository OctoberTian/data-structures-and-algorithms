#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
/*
1. malloc的全称是memory allocation，中文叫动态内存分配，用于申请一块连续的指定大小的内存块区域以void*类型返回分配的内存区域地址，当无法知道内存具体位置的时候，想要绑定真正的内存空间，就需要用到动态的分配内存。

*/

typedef struct LNode
{
	int Data[MAXSIZE];
	int Last;
}LNode;

LNode *MakeEmpty()
{
	LNode *PtrL;
	PtrL = (struct LNode *)malloc(sizeof(struct LNode));
	PtrL->Last = -1;
	return PtrL;
}

int Find(int X, LNode *PtrL)
{
	int i = 0;
	while(i <= PtrL->Last && PtrL->Data[i] != X)
	{
		i++;
	}
	if(i > PtrL->Last)
	{
		return -1;
	}
	else{
		return i;
	}
}

void Insert(int X, int Pos, LNode *PtrL)
{
	int j;
	//首先判断是否表满:Last是最后一个元素的位置,MAXSIZE是最大容量,由于是0-LAST,所以LAST位置是第LAST+1个元素
	if(PtrL->Last == MAXSIZE)
	{
		printf("表满,无法插入");
		return;
	}
	//检查插入的位置是否合法:Pos是插入位置,Pos=1其实Last是0
	if(Pos < 1 || Pos > PtrL->Last+2)
	{
		printf("位置不合法");
		return;
	}
	//依次退后一个
	for(j = PtrL->Last; j >= Pos-1; j--)
	{
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	//放入
	PtrL->Data[Pos-1] = X;
	//Last右移
	PtrL->Last++;
	return;
}

void Delete(int Pos, LNode *PtrL)
{
	int j;
	//判断位置的合法性
	if(Pos < 1 || Pos > PtrL->Last+1)
	{
		printf("不存在该位置元素");
		return;
	}
	for(j = Pos; j <= PtrL->Last; j++)
	{
		PtrL->Data[j-1] = PtrL->Data[j];
	}
	PtrL->Last--;
	return;
}

void PrintNodes(LNode *PtrL)
{
	int i;
	if(PtrL->Last == -1)
	{
		printf("线性数组为空");
		return;
	}
	for(i = 0; i <= PtrL->Last; i++)
	{
		printf("%d ", PtrL->Data[i]);
	}
	printf("\n");
	return;
}

int main()
{
    printf("Hello world!\n");
    LNode *myNode = MakeEmpty();
    Insert(10, 1, myNode);
    Insert(15, 2, myNode);
    PrintNodes(myNode);
    int pos = Find(15, myNode);
    printf("postion:%d\n", pos);
    Delete(1, myNode);
    PrintNodes(myNode);
    return 0;
}
