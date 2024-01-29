#include "main.hpp"
#include <stdlib.h>

struct node
{
	int data;
	// �ݹ鶨��
	struct node* next;
};

void linkedList_test()
{
	node* head = NULL;
	node* q = (node*)malloc(sizeof(node));

	int length;
	std::cout << "����������:";
	std::cin >> length;

	// ��������
	for (size_t i = 0; i < length; i++)
	{
		// Ϊ�ڵ�����ڴ�ռ�
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

	//��������������������
	node* t = head;
	int insert_data;
	std::cin >> insert_data;

	while (t != NULL)
	{
		if (t->next->data > insert_data)
		{
			// Ϊ����Ľڵ�����ڴ�
			node* new_node = (node*)malloc(sizeof(node));
			new_node->data = insert_data;
			new_node->next = t->next;
			t->next = new_node;
			break;
		}
		t = t->next;
	}

	// �����������
	node* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		node* trash = temp;
		temp = temp->next;
		free(trash);
	}
}

