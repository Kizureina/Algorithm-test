#include "main.hpp"

void gragh_search_bfs()
{
	cout << "����ͼ�Ķ�����:";
	cin >> n;

	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		for (size_t j = 1; j <= length; j++)
		{
			if (i == j)
			{
				// 0��־�Լ����Լ�
				e[i][j] = 0;
			}
			else
			{
				// ���������û�бߣ��ȳ�ʼ��Ϊ��û������
				e[i][j] = 99999999999;
			}
		}
	}

	int m;
	cout << "�������";
	cin >> m;
	cout << "�����������ӵĶ���:";

	length = m;
	for (int i = 1; i <= length; i++)
	{
		int a, b;
		cin >> a >> b;

		e[a][b] = 1;
		e[b][a] = 1;
	}
	
	int queue[20];
	int tail = 1;
	int head = 1;

	queue[tail] = 1;
	tail++;
	book[1] = 1;
	
	while (head < tail)
	{
		int cur = queue[head];
		length = n;
		
		// ������ǰ�����еı�
		for (size_t i = 1; i <= length; i++)
		{
			if (e[cur][i] == 1 && book[i] == 0)
			{
				queue[tail] = i;
				tail++;
				book[i] = 1;
			}

			// ���������ĵ�������е�ʱ��˵���Ѿ�ȫ��������ɣ�
			if (tail > n)
			{
				break;
				cout << "��ȫ������";
			}
		}

		head++;
	}

	length = tail;
	for (size_t i = 1; i < length; i++)
	{
		cout << queue[i] << " ";
	}
}