# 数据结构复习
2019年4月开始复习数据结构,将该部分代码添加到这里

使用的IDE为CodeBlocks

# 线性表

## 线性表-数组

通过数组的方式实现线性表,关键代码结点:

```c
typedef struct LNode
{
	ElementType Data[MAXSIZE];
	int Last;
}LNode;
```

## 线性表-链表(基础)

线性表的链表在各节点在逻辑上是相连的，在物理上是不连的，而基于数组的线性表都是相连的

```c
typedef struct LNode
{
	int Data;
	struct LNode *Next;
}LNode;
```

# 堆栈

## 堆栈-数组储存

## 堆栈-链表储存

```c
typedef struct SNode
{
	int Data[MAXSIZE];
	int Top;
}SNode;

//链表储存的堆栈
typedef struct SNode_List
{
	int Data;
	struct SNode_List *Next;
}SLNode;
```

# 队列

## 队列-单向链表实现

两个节点类型，第一个是储存作用，第二个是队列的两个指针

```c
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
```

