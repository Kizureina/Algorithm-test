#include "main.hpp"

//Bellman-ford算法用以解决有负权边的图的最短路径问题
void Bellman_ford_shortest_path()
{
	// 这三个数组的大小是比边数大一
	int u[6], v[6], w[6];

	// 类似于dijkstra算法的dis数组
	int dis[10];
	// 备份数组，用于检测某轮松弛后dis数组是否有变化
	int back[10];

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
	int flag = 0;// 检测负权回路

	// Bellman-Ford算法核心：只有四行
	// 外循环是进行所有边松弛的轮数
	// 轮数：相当于结果多少条边实现最短路径 ==> 所以n个顶点时，轮数为n-1
	for (size_t i = 1; i <= n - 1; i++)
	{
		// 内循环是根据每条边做松弛
		for (size_t j = 1; j <= m; j++)
		{
			// 即对第j条边条做“松弛”
			// 与Dijkstra的用点插入松弛边不同，
			// B-F算法的松弛是用边的两个点到起始点的dis[1]和dis[2]+边的权值做比较，
			// 如果走这条边能让dis[1]更小，则完成松弛
			if (dis[v[j]] > dis[u[j]] + w[j])
			{
				dis[v[j]] = dis[u[j]] + w[j];
			}
		}
	}

	// 当完成n - 1轮松弛以后，还可以松弛，则说明有负权回路
	for (size_t i = 1; i <= m; i++)
	{
		if (dis[v[i]] > dis[u[i]] + w[i])
		{
			flag = 1;
		}
	}

	if (flag == 1)
	{
		cout << "该图含有负权回路！\n";
	}

	for (size_t i = 1; i <= length; i++)
	{
		cout << dis[i] << " ";
	}

}