#include "main.hpp"

//Bellman-ford�㷨���Խ���и�Ȩ�ߵ�ͼ�����·������
void Bellman_ford_shortest_path()
{
	// ����������Ĵ�С�Ǳȱ�����һ
	int u[6], v[6], w[6];

	// ������dijkstra�㷨��dis����
	int dis[10];

	cin >> n >> m;

	for (size_t i = 1; i <= m; i++)
	{
		// ���붥���Ȩֵ
		cin >> u[i] >> v[i] >> w[i];
	}

	// ��ʼ��dis����
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		dis[i] = infinity;
	}
	// ��㵽�Լ�����̾���Ϊ0
	dis[1] = 0;

	// Bellman-Ford�㷨���ģ�ֻ������
	for (size_t i = 1; i <= n - 1; i++)
	{
		for (size_t j = 1; j <= m - 1; j++)
		{
			// ���Ե�j�����������ɳڡ�
			if (dis[v[j]] > dis[u[j]] + w[j])
			{
				dis[v[j]] = dis[u[j]] + w[j];
			}
		}
	}

	for (size_t i = 1; i <= length; i++)
	{
		cout << dis[i] << " ";
	}

}