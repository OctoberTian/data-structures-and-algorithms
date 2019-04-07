#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
/*
1. malloc��ȫ����memory allocation�����Ľж�̬�ڴ���䣬��������һ��������ָ����С���ڴ��������void*���ͷ��ط�����ڴ������ַ�����޷�֪���ڴ����λ�õ�ʱ����Ҫ���������ڴ�ռ䣬����Ҫ�õ���̬�ķ����ڴ档

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
	//�����ж��Ƿ����:Last�����һ��Ԫ�ص�λ��,MAXSIZE���������,������0-LAST,����LASTλ���ǵ�LAST+1��Ԫ��
	if(PtrL->Last == MAXSIZE)
	{
		printf("����,�޷�����");
		return;
	}
	//�������λ���Ƿ�Ϸ�:Pos�ǲ���λ��,Pos=1��ʵLast��0
	if(Pos < 1 || Pos > PtrL->Last+2)
	{
		printf("λ�ò��Ϸ�");
		return;
	}
	//�����˺�һ��
	for(j = PtrL->Last; j >= Pos-1; j--)
	{
		PtrL->Data[j+1] = PtrL->Data[j];
	}
	//����
	PtrL->Data[Pos-1] = X;
	//Last����
	PtrL->Last++;
	return;
}

void Delete(int Pos, LNode *PtrL)
{
	int j;
	//�ж�λ�õĺϷ���
	if(Pos < 1 || Pos > PtrL->Last+1)
	{
		printf("�����ڸ�λ��Ԫ��");
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
		printf("��������Ϊ��");
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
