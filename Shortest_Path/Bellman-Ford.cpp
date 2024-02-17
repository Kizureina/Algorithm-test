#include "main.hpp"

//Bellman-ford算法用以解决有负权边的图的最短路径问题
void Bellman_ford_shortest_path()
{
	// 这三个数组的大小是比边数大一
	int u[6], v[6], w[6];

	// 类似于dijkstra算法的dis数组
	int dis[10];

	cin >> n >> m;

	for (size_t i = 1; i <= m; i++)
	{
		// 读入顶点和权值
		cin >> u[i] >> v[i] >> w[i];
	}

	// 初始化dis数组
	int length = n;
	for (size_t i = 1; i <= length; i++)
	{
		dis[i] = infinity;
	}
	// 起点到自己的最短距离为0
	dis[1] = 0;

	// Bellman-Ford算法核心：只有四行
	for (size_t i = 1; i <= n - 1; i++)
	{
		for (size_t j = 1; j <= m - 1; j++)
		{
			// 即对第j条边条做“松弛”
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