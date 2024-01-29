#include "main.hpp"
#include <stdlib.h>

struct node
{
	int data;
	// 递归定义
	struct node* next;
};

void linkedList_test()
{
	node* head = NULL;
	node* q = (node*)malloc(sizeof(node));

	int length;
	std::cout << "输入链表长度:";
	std::cin >> length;

	// 创建链表
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

	//插入链表（插入有序链表）
	node* t = head;
	int insert_data;
	std::cin >> insert_data;

	while (t != NULL)
	{
		if (t->next->data > insert_data)
		{
			// 为插入的节点分配内存
			node* new_node = (node*)malloc(sizeof(node));
			new_node->data = insert_data;
			new_node->next = t->next;
			t->next = new_node;
			break;
		}
		t = t->next;
	}

	// 遍历输出链表
	node* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		node* trash = temp;
		temp = temp->next;
		free(trash);
	}
}

