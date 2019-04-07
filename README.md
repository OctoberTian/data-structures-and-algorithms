# 数据结构复习
2019年4月开始复习数据结构,将该部分代码添加到这里

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

