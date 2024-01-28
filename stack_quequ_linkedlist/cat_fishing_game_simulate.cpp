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

// ʹ��ջ�Ͷ���ģ��Сè������Ϸ
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

	// ���������ƵĶ��ж���Ϊ��ʱ������Ϸ
	while (user1.head < user1.tail && user2.head < user2.tail)
	{
		// ���һ����
		int the_output_card = user1.data[user1.head];

		// �ж��Ƿ����������е�����ͬ
		int flag = 0;
		for (size_t i = 0; i < table.top; i++)
		{
			if (the_output_card == table.data[i])
			{
				flag = 1;
				break;
			}
		}

		// ���һûӮ��
		if (flag == 0)
		{
			user1.head++;
			table.top++;
			// ��ջ
			table.data[table.top] = the_output_card;
		}

		// ���һӮ��
		if (flag == 1)
		{
			user1.head++;
			user1.data[user1.tail] = the_output_card;
			user1.tail++;

			while (table.data[table.top] != the_output_card)
			{
				user1.data[user1.tail] = table.data[table.top];
				user1.tail++;
				table.top--;
			}
		}

		// .....��Ҷ��Ĳ���һ�����˴�ʡ��
	}

	// �ж���Ϸʤ��
	if (user1.head == user1.tail)
	{
		std::cout << "ʤ����Ϊ��Ҷ�\n��ʱ��Ҷ�������Ϊ" << std::endl;
		for (size_t i = user2.head; i < user2.tail - 1; i++)
		{
			std::cout << user2.data[i] << " ";
		}
		// ���ϵ���
		if (table.top > 0)
		{
			for (size_t i = 0; i < table.top; i++)
			{
				std::cout << table.data[i] << " ";
			}
		}
		else
		{
			std::cout << "����ʱ����û����" << std::endl;
		}
	}
}