#include <stdio.h>
#include "main.h"

// ��������
#define MAXD 20;

struct node1
{
	int data;
	node1* next[20];
	// �����20�����Ķȣ����ڵ�������������/��֧������
};
typedef node1 TNode;
typedef node1 *TNodePtr;


//int main()
//{
//	BTNodePtr t;
//}

void visit(TNodePtr t)
{

}


void DFSTree(TNodePtr t)
{
	int i;
	if (t != NULL)
	{
		visit(t);
		for (i = 0; i < 20; i++)
		{
			if (t->next[i] != NULL)
			{
				DFSTree(t->next[i]);
			}
		}
	}
}

void BFSTree(TNodePtr t)
{

}