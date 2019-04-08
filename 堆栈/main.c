#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct SNode
{
	int Data[MAXSIZE];
	int Top;
}SNode;

//Á´±í´¢´æµÄ¶ÑÕ»
typedef struct SNode_List
{
	int Data;
	struct SNode_List *Next;
}SLNode;

SNode *CreateStack()
{
	SNode *myStack = (struct SNode*)malloc(sizeof(SNode));
	myStack->Top = 0;
	return myStack;
}

void PrintStack(SNode *myStack)
{
	int num = myStack->Top;
	while(num > 0)
	{
		printf("%d ", myStack->Data[num]);
		num--;
	}
	printf("\n");
	return;
}

void Push(SNode *sNode, int value)
{
	if(sNode->Top == MAXSIZE - 1)
	{
		printf("¶ÑÕ»Âú!");
		return;
	}
	sNode->Data[++(sNode->Top)] = value;
	return;
}

SLNode *CreateLStack()
{
	SLNode *lStack = (struct SLNode*)malloc(sizeof(SLNode));
	lStack->Next = NULL;
	return lStack;
}

int Pop(SNode *sNode)
{
	if(sNode->Top == 0)
	{
		printf("¶ÑÕ»¿Õ!");
		return;
	}
	return sNode->Data[--(sNode->Top)];
}

int IsLStackEmpty(SLNode *listStack)
{
	return (listStack->Next == NULL);
}

void PushListStack(SLNode *listStack, int value)
{
	SLNode *newNode = (struct SLNode*)malloc(sizeof(SLNode));
	newNode->Data = value;
	newNode->Next = listStack->Next;
	listStack->Next = newNode;
}

int PopListStack(SLNode *listStack)
{
	if(IsLStackEmpty(listStack))
	{
		printf("¶ÑÕ»¿Õ");
		return;
	}
	SLNode *top = listStack->Next;
	int value = top->Data;
	listStack->Next = top->Next;
	free(top);
	return value;
}

void PrintLStack(SLNode *listStack)
{
	SLNode *topElement = listStack->Next;
	while(topElement)
	{
		printf("%d ", topElement->Data);
		topElement = topElement->Next;
	}
	printf("\n");
	return;
}
int main()
{
	SNode *myStack = CreateStack();
	Push(myStack, 1);
	Push(myStack, 3);
	Push(myStack, 2);
	Push(myStack, 10);
	Push(myStack, 15);
	PrintStack(myStack);

	//Á´±íÊµÏÖµÄ¶ÑÕ»
	SLNode *listStack = CreateLStack();
	PushListStack(listStack, 3);
	PushListStack(listStack, 4);
	PushListStack(listStack, 5);
	PushListStack(listStack, 6);
	PushListStack(listStack, 7);
	PopListStack(listStack);
	PrintLStack(listStack);
    return 0;
}
