#include "main.hpp"
#include <stdlib.h>

struct node
{
	int data;
	// 递归定义
	struct node* next;
};

// 创建链表
void linkedList_test()
{
	node* head = NULL;
	node* q = (node*)malloc(sizeof(node));

	int length;
	std::cout << "输入链表长度:";
	std::cin >> length;

	for (size_t i = 0; i < length; i++)
	{
		// 为节点分配内存空间
		node* p = (node*)malloc(sizeof(node));
		
		std::cin >> p->data;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
			q = head;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}

	node* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		node* trash = temp;
		temp = temp->next;
		free(trash);
	}
}