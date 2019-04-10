#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int Data;
	struct Node *Next;
}Node;

typedef struct QNode
{
	struct Node *Front;
	struct Node *Rear;
}QNode;

QNode *CreateQueue()
{
	QNode *queue = (struct QNode *)malloc(sizeof(QNode));
	queue->Front = NULL;
	queue->Rear = NULL;
	return queue;
}

void AddQueue(QNode *queue, int value)
{
	Node *newNode = (struct Node *)malloc(sizeof(Node));
	newNode->Data = value;
	if(queue->Front == NULL && queue->Rear ==NULL)
	{
		newNode->Next = NULL;
		queue->Front = queue->Rear = newNode;
		return;
	}
	Node *tempPoint = queue->Front;
	while(tempPoint != queue->Rear)
	{
		tempPoint = tempPoint->Next;
	}
	tempPoint->Next = newNode;
	queue->Rear = newNode;
}

int DeleteQueue(QNode *queue)
{
	if(queue->Front == NULL)
	{
		printf("╤сапн╙©у");
		return;
	}
	if(queue->Front == queue->Rear)
	{
		int deleteVal = queue->Front->Data;
		free(queue->Front);
		queue->Front = queue->Rear = NULL;
		return deleteVal;
	}
	Node *nextNode = queue->Front->Next;
	int deleteVal = queue->Front->Data;
	free(queue->Front);
	queue->Front = nextNode;
	return deleteVal;
}

void PrintQueue(QNode *queue)
{
	Node *tempPoint = queue->Front;
	while(tempPoint != queue->Rear)
	{
		printf("%d ", tempPoint->Data);
		tempPoint = tempPoint->Next;
	}
	printf("%d\n", tempPoint->Data);
}

int main()
{
	QNode *queue = CreateQueue();
	AddQueue(queue, 1);
	AddQueue(queue, 2);
	AddQueue(queue, 3);
	AddQueue(queue, 4);
	AddQueue(queue, 5);
	AddQueue(queue, 6);
	printf("%d\n", DeleteQueue(queue));
	printf("%d\n", DeleteQueue(queue));
	PrintQueue(queue);
    return 0;
}
