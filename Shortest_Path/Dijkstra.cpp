#include "main.hpp"

// dijkstra�㷨��Դ���·��
void dijkstra_shortest_path()
{
	// ��ʱ��book������֮ǰ���岻ͬ��������ǡ���֪���·�����ļ���
	// book[10]
	int dis[10];
	// �������¶��㵽������ĳ�ʼ��������̾���

	// ��ʼ��dis����
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		dis[i] = e[1][i];
	}

	// ��ʼ��book����
	for (size_t i = 1; i <= length; i++)
	{
		book[i] = 0;
	}
	// 1���Լ�����Ϊ0�����б��Ϊ��֪���·��
	book[1] = 1;

	int nearest = 0;
	for (size_t i = 1; i <= length - 1; i++)
	{
		int min = infinity;

		for (size_t j = 1; j <= length; j++)
		{
			// ����Ѱ��һ������Դ�����(dis��������С�ĵ�)���洢��nearest
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				nearest = j;
			}
		}
		// ���nearest��Ϊ��֪��̾���
		book[nearest] = 1;

		// ��չ���������г��㣬������Щ�������ӵı��ж��Ƿ���Ը���dis���飨�����ɳڡ���
		for (size_t v = 1; v <= length; v++)
		{
			// ���õ��г���ʱ
			if (e[nearest][v] < infinity)
			{
				// ����Floyd-Warshall�㷨���ж����м��ʱ�Ƿ���̣�������������dis����
				if (dis[v] > dis[nearest] + e[nearest][v])
				{
					dis[v] = dis[nearest] + e[nearest][v];
				}
			}
		}

	}

	for (size_t i = 1; i <= length; i++)
	{
		cout << dis[i] << " ";
	}
}