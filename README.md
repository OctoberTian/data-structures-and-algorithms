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

