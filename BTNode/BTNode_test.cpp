#include <stdio.h>
#include "main.h"

typedef struct node
{
	int data;
	struct node * lchild, * rchild;
} BTnode, *BTNodePtr;
// BTnode与*BTNodePtr区别是什么？
// 前者是一个node结构体(即一块内存区域的首地址)，后者是一个指向node结构体的指针
// 对前者引用变量：BTnode.lchild
// 对后者引用变量：BTNodePrt->lchild

int main()
{
	// 定义二叉树根节点指针和节点指针
	BTNodePtr T, p, q;
}

void visit(BTNodePtr t)
{
	printf("%d ", t->data);
}

// 前序遍历
void perorder(BTNodePtr t)
{
	if (t != NULL)
	{
		visit(t);	// 访问t指向的节点
		perorder(t->lchild);
		perorder(t->rchild);
	}
}

// 中序遍历
void inorder(BTNodePtr t)
{
	if (t != NULL)
	{
		// 左-根-右
		inorder(t->lchild);
		visit(t);
		inorder(t->rchild);
	}
}

// 后序遍历
void postorder(BTNodePtr t)
{
	if (t != NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		visit(t);
	}
}


// 层次遍历
void layerorder(BTNodePtr t)
{
	// 定义一个存储树的节点的队列
	BTNodePtr queue[NodeNum], p;

	int front, rear;
	if (t != NULL)
	{
		// 将根节点入队
		queue[0] = t;
		// 入队后初始化首指针和尾指针
		front = -1;
		rear = 0;

		// 当队列不空时执行遍历
		while (front < rear)
		{
			// 访问当前队首的节点时，front先加再取值
			front++;
			p = queue[front];

			// 访问p指向的节点
			visit(p);

			if (p->lchild != NULL)
			{
				// 从队尾入队时，队尾指针先加一再入队
				rear++;
				queue[rear] = p->lchild;
			}

			if (p->rchild != NULL)
			{
				rear++;
				queue[rear] = p->rchild;
			}
		}
	}
	// 执行之后，队列queue中的节点为层次遍历结果
}