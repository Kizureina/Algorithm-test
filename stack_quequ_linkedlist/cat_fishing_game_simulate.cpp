#include "main.hpp"

struct queue
{
	int data[1024] = { 0 };
	int head;
	int tail;
};

struct stack
{
	int data[10] = { 0 };
	int top;
};

void cat_fishing_test()
{
	struct queue user1, user2;
	struct stack table;

	//��ʼ��
	user1.head = 0;
	user1.tail = 0;

	user2.head = 0;
	user2.tail = 0;

	table.top = 0;

	// ������
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "�������1����:";
		std::cin >> user1.data[user1.tail];
		user1.tail++;
	}

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "�������2����:";
		std::cin >> user2.data[user2.tail];
		user2.tail++;
	}

}