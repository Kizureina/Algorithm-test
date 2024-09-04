#include <stdio.h>
#include "main.h"

typedef struct node
{
	int data;
	struct node * lchild, * rchild;
} BTnode, *BTNodePtr;
// BTnode��*BTNodePtr������ʲô��
// ǰ����һ��node�ṹ��(��һ���ڴ�������׵�ַ)��������һ��ָ��node�ṹ���ָ��
// ��ǰ�����ñ�����BTnode.lchild
// �Ժ������ñ�����BTNodePrt->lchild

int main()
{
	// ������������ڵ�ָ��ͽڵ�ָ��
	BTNodePtr T, p, q;
}

void visit(BTNodePtr t)
{
	printf("%d ", t->data);
}

// ǰ�����
void perorder(BTNodePtr t)
{
	if (t != NULL)
	{
		visit(t);	// ����tָ��Ľڵ�
		perorder(t->lchild);
		perorder(t->rchild);
	}
}

// �������
void inorder(BTNodePtr t)
{
	if (t != NULL)
	{
		// ��-��-��
		inorder(t->lchild);
		visit(t);
		inorder(t->rchild);
	}
}

// �������
void postorder(BTNodePtr t)
{
	if (t != NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		visit(t);
	}
}


// ��α���
void layerorder(BTNodePtr t)
{
	// ����һ���洢���Ľڵ�Ķ���
	BTNodePtr queue[NodeNum], p;

	int front, rear;
	if (t != NULL)
	{
		// �����ڵ����
		queue[0] = t;
		// ��Ӻ��ʼ����ָ���βָ��
		front = -1;
		rear = 0;

		// �����в���ʱִ�б���
		while (front < rear)
		{
			// ���ʵ�ǰ���׵Ľڵ�ʱ��front�ȼ���ȡֵ
			front++;
			p = queue[front];

			// ����pָ��Ľڵ�
			visit(p);

			if (p->lchild != NULL)
			{
				// �Ӷ�β���ʱ����βָ���ȼ�һ�����
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
	// ִ��֮�󣬶���queue�еĽڵ�Ϊ��α������
}