#include "main.hpp"

struct queue
{
	int data[100];
	int head;
	int tail;
};

// ���ڲ��Զ��в����Ľ���Ӧ��

void queue_test()
{
	struct queue q;
	q.head = 1;
	q.tail = 1;

	for (size_t i = 0; i < 9; i++)
	{
		std::cin >> q.data[q.tail];
		q.tail++;
	}

	while (q.head < q.tail)
	{
		std::cout << q.data[q.head];
		q.head++;

		q.data[q.tail] = q.data[q.head];
		q.tail++;
		// ���׳���
		q.head++;
	}
}