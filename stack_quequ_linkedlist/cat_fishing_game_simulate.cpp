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

// 使用栈和队列模拟小猫钓鱼游戏
void cat_fishing_test()
{
	struct queue user1, user2;
	struct stack table;

	//初始化
	user1.head = 0;
	user1.tail = 0;

	user2.head = 0;
	user2.tail = 0;

	table.top = 0;

	// 读入牌
	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "输入玩家1的牌:";
		std::cin >> user1.data[user1.tail];
		user1.tail++;
	}

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << "输入玩家2的牌:";
		std::cin >> user2.data[user2.tail];
		user2.tail++;
	}

	// 当两人手牌的队列都不为空时继续游戏
	while (user1.head < user1.tail && user2.head < user2.tail)
	{
		// 玩家一出牌
		int the_output_card = user1.data[user1.head];

		// 判断是否与桌上现有的牌相同
		int flag = 0;
		for (size_t i = 0; i < table.top; i++)
		{
			if (the_output_card == table.data[i])
			{
				flag = 1;
				break;
			}
		}

		// 玩家一没赢牌
		if (flag == 0)
		{
			user1.head++;
			table.top++;
			// 入栈
			table.data[table.top] = the_output_card;
		}

		// 玩家一赢牌
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

		// .....玩家二的操作一样，此处省略
	}

	// 判断游戏胜者
	if (user1.head == user1.tail)
	{
		std::cout << "胜利者为玩家二\n此时玩家二的手牌为" << std::endl;
		for (size_t i = user2.head; i < user2.tail - 1; i++)
		{
			std::cout << user2.data[i] << " ";
		}
		// 桌上的牌
		if (table.top > 0)
		{
			for (size_t i = 0; i < table.top; i++)
			{
				std::cout << table.data[i] << " ";
			}
		}
		else
		{
			std::cout << "结束时桌上没有牌" << std::endl;
		}
	}
}